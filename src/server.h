/* This is the http server
 * DATE: 20160707 */

#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXSIZE 4096
#define DEFAULT_PORT 9452
using namespace std;
class http_server
{
private:
	int socket_fd, accept_fd;
	sockaddr_in myserver;
	sockaddr_in remote_addr;
public:
	http_server();
	int recv_msg();
};
