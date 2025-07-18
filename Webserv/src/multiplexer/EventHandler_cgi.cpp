#include "EventHandler.hpp"
#include "string.h"
#include <cctype>
#include <csignal>
#include <ctime>
#include <sched.h>
#include <stdlib.h>

static void	close_all(int fd[], int fd_body[])
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (fd_body[0] != -1)
		close(fd_body[0]);
	if (fd_body[1] != -1)
		close(fd_body[1]);
}

std::string	process_header_field(const std::string& s)
{
	std::string	processed(s);

	for (std::string::iterator	it = processed.begin(); it < processed.end(); it++)
	{
		if (*it == '-')
		{
			*it = '_';
			continue;
		}
		*it = std::toupper(*it);
	}
	processed.insert(0, "HTTP_");
	return processed;
}

void	EventHandler::handle_environment(const Request& req, const std::string& arg)
{
	environ = NULL;
	setenv("PATH_INFO", arg.c_str(), 1);
	setenv("REQUEST_METHOD", req.getMethod().c_str(), 1);
	if (!req.getQueryString().empty())
		setenv("QUERY_STRING", req.getQueryString().c_str(),1);
	try
	{
		// Takes all HTTP request headers (including "Cookie"), converts them into environment variables (e.g., "HTTP_COOKIE"), and sets them with setenv.
		for (std::multimap<std::string, std::string>::const_iterator it = req.getHeaders().begin(); it != req.getHeaders().end(); it++)
		{
			std::string	s(process_header_field(it->first));
			setenv(s.c_str(), it->second.c_str(), 1);
		}
		if (req.getMethod() == "POST")
		{
			setenv("CONTENT_TYPE", req.getHeaderValue("Content-Type").c_str(), 1);
			setenv("CONTENT_LENGTH", req.getHeaderValue("Content-Length").c_str(), 1);
		}
		setenv("SERVER_NAME", req.getHeaderValue("Host").c_str(), 1);
	}
	catch (const std::exception &e)
	{std::cerr << "[Log] setenv, can ignore." << std::endl;}
}

// void	alarm_handler(int _sig) { (void)_sig; throw (1); }

// fork process: child execve's script
// return true if success, otherwise false
CgiResult	EventHandler::startCGI(int clientFd, std::vector<std::string> arguments)
{
	pid_t	pid;
	int		fd[2];
	int		fd_body[2];
	Request	req(_clients.at(clientFd)->_requestBuffer);

	if (pipe(fd) == -1 || pipe(fd_body) == -1)
	{
		std::cerr << "Error: Could not establish pipe for CGI output.\n";
		return ERROR;
	}
	pid = fork();
	if (pid == -1)
	{
		std::cerr << "Error: Could not fork process in CGI output.\n";
		close_all(fd, fd_body);
		return ERROR;
	}
	if (pid == 0)
	{
		// setPipe(fd, STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_body[0], STDIN_FILENO);
		close_all(fd, fd_body);
		char *const	args[] =
		{
			const_cast<char *>(arguments[0].c_str()),
			const_cast<char *>(arguments[1].c_str()),
			NULL
		};

		handle_environment(req, arguments[0]);
		// signal(SIGALRM, alarm_handler);
		// alarm(TIMEOUT_TIME);
		execve(arguments.front().c_str(), args, environ);
		std::cerr << "Error: could not execute cgi script\n";
		throw (1);
	}
	else
	{
		/* To fix:
		 *	This write is not checked by epoll nor protected (removing client upon error).
		 *	It writes the info to CGI, so don't have to manage the client.
		*/
		write(fd_body[1], req.getBody().c_str(), req.getBody().size());
		close(fd[1]);
		close(fd_body[0]);
		close(fd_body[1]);
		time_t	start_time = std::time(NULL);
		while (1)
		{
			int	status;
			pid_t	result = waitpid(pid, &status, WNOHANG);
			if (result < 0)
			{
				std::cerr << "WAITPID FAILED: its ok though" << std::endl;
				return NOTFOUND;
				//throw (1);
			}
			else if (result == 0)
			{
				if (std::time(NULL) - start_time >= TIMEOUT_TIME)
				{
					std::cout << "Child timeout after: " << TIMEOUT_TIME << std::endl;
					kill(pid, SIGTERM);
					waitpid(pid, NULL, 0);
					return TIMEOUT;
				}
			}
			else
			{
				bool code = result < 0 || !WIFEXITED(status) || WEXITSTATUS(status) != 0;

				std::cout << "Response sent to client.\n";
				if (!code)
				{
					addToEpoll(fd[0]);
					_cgiManager.addCgiProcess(clientFd, fd[0], pid);
					_openConns[fd[0]] = EP_CGI;
					return SUCCESS;
				}
				else
				{
					close(fd[0]);
					return ERROR;
				}
			}
		}
	}
	return ERROR;
}