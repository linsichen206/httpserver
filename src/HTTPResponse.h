/*This is an alpha version
 *
 *
 *
 *
 *
 */

//HTTPResponse.h
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <sstream>
//#define MAXURILINE 50;
using namespace std;

class HTTPResponse
{
public:
	HTTPResponse(int fd, string uri);
	//~HTTPResponse();
	void responderror(const string errnum, const string msg, const string longmsg);
	void run();
	//void Requestparse(char* buf, HTTPRequest* request);	
private:
	void respond();
	int getfd() const;
	const string getfilename();
	const string getfiletype();
	struct stat& getStat();
	const string typetostr(string::size_type sizeType);
	const string buildreserrorheaders(const string errnum, const string msg);
	const string buildreserrorbody(const string errnum,const string msg, const string longmsg);
	const string buildresheaders();
	struct stat sbuf;
	int fileDescriptor;
	string filename;
};
