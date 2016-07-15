/* This is the alpha version
 *
 *
 *
 *
 *
 */

//Requset.h
#include <iostream>
#include <string>
#include "HTTPGetRequest.h"
#define MAXMETHODLINE 10
#define MAXURILINE 20
//#define MAXSIZE 100

using namespace std;

class HTTPRequest{
public:
	HTTPRequest(int fd);
	~HTTPRequest();
	void Requestparse(char *);
	const string& geturi() const;
	void run();
private:
	int fileDescriptor;
	//char buf[MAXSIZE];
	string method;
	string uri;
//	void run();
};

