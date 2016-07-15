/* This is an alpha version
 *
 *
 *
 *
 *
 */

//HTTPGetRequest.cpp
//
#include "HTTPGetRequest.h"
#include "HTTPResponse.h"

HTTPGetRequest :: HTTPGetRequest(int fd, string uri): fileDescriptor(fd), uri(uri)
{}

bool HTTPGetRequest :: parse_uri()
{
	string content = geturi();
	uri = "test" + content;
	//cwd = (string*)getcwd();
	//uri = cwd + content;
//	if	
	return true;
}

const string HTTPGetRequest::geturi() const
{
	return uri;
}
int HTTPGetRequest::getfd() const
{
	return fileDescriptor;
}
void HTTPGetRequest :: run()
{
	//cout<<"Running"<<endl;
	HTTPResponse Res(fileDescriptor,uri);
	Res.run();
}
