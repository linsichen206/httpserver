/* This is an httpserver 
 * DATE:2016078 */

#include "server.h"
#include "HTTPRequest.h"
//#include "HTTPResponse.h"
http_server::http_server(){
	
	if((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ){
		cout<<"socket() failed"<<endl;
		cout<<"errno = "<<errno<<endl;
	}
	
	//init
	int on =1;
	const char chopt = 1;
	int ret1 = setsockopt(socket_fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));	
	int ret2 = setsockopt(socket_fd,IPPROTO_TCP,TCP_NODELAY,&chopt,sizeof(char));
	memset(&myserver, 0, sizeof(myserver));
	myserver.sin_family = AF_INET;
	myserver.sin_addr.s_addr = htonl(INADDR_ANY);//自动获取本机地址
	myserver.sin_port = htons(DEFAULT_PORT);//监听端口
	
	if( bind(socket_fd, (sockaddr*) &myserver, sizeof(myserver)) < 0 ){
		cout<<"bind() failed"<<endl;
		cout<<"errno = "<<errno<<endl;
	}
	
	if( listen(socket_fd, 10) < 0 ){
		cout<<"listen() failed"<<endl;
		cout<<"errno = "<<errno<<endl;
	}
}

int http_server::recv_msg(){
	
	while(1){
		socklen_t sin_size = sizeof(struct sockaddr_in);
		if( (accept_fd = accept(socket_fd, (struct sockaddr*) &remote_addr, &sin_size)) == -1 ){
			cout<<"Accept error!"<<endl;
			cout<<"errno = "<<errno<<endl;
			continue;
		}
		printf("Receive a connettion from %s\n", (char*) inet_ntoa(remote_addr.sin_addr));
		if(!fork()){
			char buffer[MAXSIZE];
			memset(buffer, 0, MAXSIZE);
			if((read(accept_fd, buffer, MAXSIZE)) < 0) {
		//		throw("Read () error!");
			}else{
				//printf("Received message: %s\n", buffer);
				//break;
				char outbuffer[MAXSIZE];
				HTTPRequest *req = new HTTPRequest(accept_fd);
				req->Requestparse(buffer);
				req->run();
				//HTTPResponse *res = new HTTPResponse();
				//res->Requestparse(outbuffer,req);
				//cout<<outbuffer<<endl;
				//int n = strlen(outbuffer);
				//write(accept_fd,outbuffer,strlen(outbuffer));	
			}
			exit(0);
		}
	//	sleep(1);
		close(accept_fd);
	}
	return 0;
}
 
	
