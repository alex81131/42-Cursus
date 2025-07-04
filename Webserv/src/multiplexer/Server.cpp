#include "Server.hpp"

// Erros need to be compiled first.
class	Server::socketCreationFailure: public std::exception
{
	public:
		const char* what() const throw()
		{return "Error: Can not create socket.\n";}
};

class	Server::socketBindFailure: public std::exception
{
	public:
		const char* what() const throw()
		{return "Error: Can not bind socket.\n";}
};

class	Server::socketListenFailure: public std::exception
{
	public:
		const char* what() const throw()
		{return "Error: Can not listen on port.\n";}
};

Server::Server(Config& config):
	_config(config),
	_maxClients(MAX_CLIENTS),
	_maxEvents(MAX_EVENTS)
{
	int	enable = 1;
	const addrinfo*	addr = config.get_addr();

	_sockFd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, addr->ai_protocol);
	if (_sockFd == -1)
		throw socketCreationFailure();
	if (setsockopt(_sockFd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) == -1)
		throw socketCreationFailure();
	if (setsockopt(_sockFd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(enable)) == -1)
		throw socketCreationFailure();
	if (bind(_sockFd, addr->ai_addr, addr->ai_addrlen) < 0)
		throw socketBindFailure();
	if (listen(_sockFd, 5) < 0)
		throw socketListenFailure();
}

Server::Server(const Server& s):
	_config(s._config),
	_maxClients(s._maxClients),
	_maxEvents(s._maxEvents)
{_sockFd = dup(s._sockFd);}

Server&	Server::operator=(const Server& other)
{
	if (this != &other)
	{
		_sockFd = dup(other._sockFd);
		_maxClients = other._maxClients;
	}
	return *this;
}

Server::~Server()
{
	if (_sockFd != -1)
		close(_sockFd);
}

int	Server::getSockFd() const
{return _sockFd;}

int	Server::getMaxClients() const
{return _maxClients;}

int	Server::getMaxEvents() const
{return _maxEvents;}

const Config&	Server::getConfig() const
{return _config;}