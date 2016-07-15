/* This is a http server
 * DATE: 20160707 */


#include <iostream>
#include "server.h"

int main(int argc, char* argv[])
{
	http_server ts;
	ts.recv_msg();
	return 0;
}
