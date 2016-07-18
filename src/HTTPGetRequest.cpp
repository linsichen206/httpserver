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
	//if(uri[uri.length() - 1] == '/')
	//	uri += "index.html";
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
	parse_uri();
	cout<<uri<<endl;
	HTTPResponse Res(fileDescriptor,uri);
	Res.run();
}
