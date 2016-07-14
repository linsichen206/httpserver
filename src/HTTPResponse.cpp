/*This is an alpha version
 *
 *
 *
 *
 */


//HTTPResponse.cpp

#include "HTTPResponse.h"
#include "ERRORHEAD.h"

HTTPResponse :: HTTPResponse(int fd, string uri): fileDescriptor(fd),filename(uri){

};

void HTTPResponse::run()
{
	try{
		respond();
	}
	catch (ERROR& err){
		return this->responderror(err.errnum, err.msg, err.longmsg);
	}
	catch (runtime_error& err){
		return this->responderror("500","Server internal error",err.what());
	}
}

void HTTPResponse::responderror(const string errnum, const string msg, const string longmsg){
		//	
	}

const string HTTPResponse::buildreserrorheaders(const string errnum, const string msg){
	return "HTTP/1.0 "+errnum+" "+msg+"\r\n"+string("Content-type: text/html\r\n");

}

const string HTTPResponse::buildreserrorbody(const string errnum,const string msg,const string longmsg){
	string content = "<html><title>Error</title>"
			+string("<body> bgcolor= ffffff >\r\n")
			+": "+msg+"\r\n"+"<p>"+longmsg+": "+filename
			+"<hr><em>The Web server powered by seven</em>\r\n";
	return "Content-length: "+typetostr(content.length())+"\r\n\r\n"
				+content;
}

const string HTTPResponse::typetostr(string::size_type sizeType)
{
	stringstream ss;
	string s;
	ss<<sizeType;
	ss>>s;
	return s;
}

const string HTTPResponse::buildresheaders()
{
	return "HTTP/1.0 200 OK\r\n"+string("Server: Web server by Sven\r\n")
		+string("Content-length: ")+typetostr(getStat().st_size)
		+"\r\n"+"Content-type: "+getfiletype()+"\r\n\r\n";
}

const string HTTPResponse::getfilename()
{
	return filename;
}

int HTTPResponse::getfd() const
{
	return fileDescriptor;
}

struct stat& HTTPResponse::getStat()
{
	return sbuf;
}

const string getfiletype()
{
	string filename = getfilename();
	if(filename.find(".html"))
		return string("text/html");
	else if (filename.find(".gif"))
		return string("image/gif");
	else if (filename.find(".jpg"))
		return string("image/jpeg");
	else
		return string("text/plain");
}


