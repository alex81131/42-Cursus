#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>

int		count = 0, max_fd = 0;
int		id[65536];
char	*msg[65536];

fd_set	rfds, wfds, afds;
char	buf_read[1001], buf_write[42];

/* * * START copy-paste from given main * * */
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}
// extract_message(char **buf, char **msg):
// 	Get_Next_line from "buf", returning the line "msg".

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}
/* * * END copy-paste * * */

void	fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int	create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (max_fd < 0)
		fatal_error();
	FD_SET(max_fd, &afds);
	return max_fd;
}
// socket(AF_INET, SOCK_STREAM, 0):
// 	Specifies the address family as IPv4, and the socket type as a stream socket, which uses TCP.
// FD_SET(max_fd, &afds):
// 	Sets max_fd as an afds.

// max_fd is used to track all the fds.
// 	一開始的 max_fd 是 socket fd (sockfd, we have only one socket)。
// 	在"register_client"中接受客戶時會有其他的fd，若比sockfd大，
// 	則會更新max_fd，來方便確認所有已使用的fd，儘管每次新增的fd不一定是連續的。

void	notify_other(int author, char *str)
{
	for (int	fd = 0; fd <= max_fd; fd++)
		if (FD_ISSET(fd, &wfds) && fd != author)
			send(fd, str, strlen(str), 0);
}

void	register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	id[fd] = count++;
	msg[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "server: client %d just arrived\n", id[fd]);
	notify_other(fd, buf_write);
}
// sprintf: [stdio] string print formatted
// 	printf into a designated string instead of directly onto stdout.

void	remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", id[fd]);
	notify_other(fd, buf_write);
	free(msg[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}
// FD_CLR(fd, &afds): [sys/select] fd clear
// 	Removes the fd from the set afds.

void	send_msg(int fd)
{
	char	*line;

	while (extract_message(&(msg[fd]), &line))
	{
		sprintf(buf_write, "client %d: ", id[fd]);
		notify_other(fd, buf_write);
		notify_other(fd, line);
		free(line);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	FD_ZERO(&afds);
	int	sockfd = create_socket();

	/* * * START copy-paste from main * * */
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));	// Replace 8080.

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))
		fatal_error();
	if (listen(sockfd, SOMAXCONN))	// The main uses 10, SOMAXCONN is 180 on my machine.
		fatal_error();
	/* * * END copy-paste * * */

	while (1)
	{
		rfds = wfds = afds;		// Copy afds to rfds and wfds.
		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			fatal_error();
		for (int	fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue ;		// Skip the unreadable fds.
			if (fd == sockfd)	// Server: new connections
			{
				socklen_t	addr_len = sizeof(servaddr);
				int			client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
				if (client_fd >= 0)
				{
					register_client(client_fd);
					break ;
				}
			}
			else	// Server receives new data from clients.
			{
				int	read_bytes = recv(fd, buf_read, 1000, 0);
				if (read_bytes <= 0)
				{
					remove_client(fd);
					break ;
				}
				buf_read[read_bytes] = '\0';
				msg[fd] = str_join(msg[fd], buf_read);
				send_msg(fd);
			}
		}
	}
	return 0;
}
// gcc -Wall -Wextra -Werror *.c
// 	Server:		./a.out 8080
// 	1st client:	nc localhost 8080
// 	2nd client:	nc localhost 8080
// 	...

// SOMAXCONN: Socket Maximum Connections
// 	Maximum number of pending connections that can be queued for a listening socket.

// select(max_fd + 1, &rfds, &wfds, NULL, NULL): manage all fds and check which are readable/writable.
// 	+ 1: starts from 0.

// unreadable fds:
// 	1. sockfd:		no new clients
// 	2. client_fd:	no new data to read
// 	3. others:		unassigned or closed fds

// ssize_t recv(int client_fd, void *buf/storage, size_t length, int flags)
// 	returns the size read:
// 	1. active client: always > 0
// 	2. client closed: = 0
// 	3. error: < 0

// msg[fd] = str_join(msg[fd], buf_read):
// 	each client has a msg string to store the data to be sent to the server.
// 	msg[fd] is initialized upon "register_client".
// Whenever a client talks to the server, the server broadcasts it.
// 	Therefore, to some extent, the clients talk to each other.