/*THis is an alpha version
 *
 *
 *
 *
 *
 */

//HTTPRequest.cpp
//#include <string>
#include "HTTPRequest.h"
//#include "HTTPGetRequest.h"
#include <stdio.h>

HTTPRequest::HTTPRequest(int fd):fileDescriptor(fd) {
	//this->fileDescriptor = fd;
	//
	//Requestparse(buf);
//	fileDescriptor = fd;
}

void HTTPRequest :: Requestparse(char *buf){
	char METHOD[MAXMETHODLINE],URI[MAXURILINE];
	sscanf(buf, "%s %s",METHOD,URI);
	this->method = METHOD;
	this->uri = URI;
	/*string METHOD,FILEPATH,VERSION;
	istringstream ss(this.buffer);
	ss>>METHOD>>FILEPATH>>VERSION;
	uri[0] = METHOD;
	uri[1] = FILEPATH;string _uri = geturi();
	string METHOD = uri[0];
	if(strcmp(METHOD, "GET"))
		strcpy(method, "GET");
	else if(strcmp(METHOD, "POST"))
		strcpy(method, "POST");
	else if(strcmp(METHOD, "HEAD"))
		strcpy(method,"HEAD");
	else
		strcpy(method,"ERRORRequest");
	strcpy(this->URI, URI);*/
}

void HTTPRequest :: run()
{
	if(method == "GET"){
		HTTPGetRequest METHOD_GET(fileDescriptor, uri);
		METHOD_GET.run();
	}
}
