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
#define MAXMETHODLINE 10
#define MAXURILINE 20
#define MAXSIZE 100

using namespace std;

class HTTPRequest{
public:
	HTTPRequest(int fd);
	virtual ~HTTPRequest();
	void Requestparse(char *);
	const string& geturi() const;
private:
	int fileDescriptor;
	//char buf[MAXSIZE];
	string method;
	string uri;
	void run();
};

