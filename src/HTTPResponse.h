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
#include <cstring>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sstream>
#include "IoWriter.h"
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
	const string inttostr(int num);
//	const string dir_server();
	const string buildreserrorheaders(const string errnum, const string msg);
	const string buildreserrorbody(const string errnum,const string msg, const string longmsg);
	const string buildresheaders();
	struct stat sbuf;
	int fileDescriptor;
	string filename;
};
