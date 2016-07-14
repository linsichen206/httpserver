/*This is an alpha version
 *
 *
 *
 *
 *
 */

//HTTPResponse.h
#include<iostream>
using namespace std;

class HTTPResponse
{
public:
	HTTPResponse();
	~HTTPResponse();
	void Requestparse(char* buf, HTTPRequest* request);
	void parse_uri(char * uri);
	void DealGET(char*buf, char * filename);	
};
