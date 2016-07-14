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
#define MAXURILINE 50;
using namespace std;

class HTTPResponse
{
public:
	HTTPResponse();
	~HTTPResponse();
	//void Requestparse(char* buf, HTTPRequest* request);
	void parse_uri(char * uri);
	void DealGET(char*buf, char * filename);	
private:
	int fileDescriptor;
	string filename;
};
