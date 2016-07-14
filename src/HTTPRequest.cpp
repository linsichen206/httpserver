/*THis is an alpha version
 *
 *
 *
 *
 *
 */

//HTTPRequest.cpp

#include "HTTPRequest.h"
#include <sstream>

HTTPRequest :: HTTPRequest(char *buffer){
	Requestparse(buffer);	
};

void HTTPRequest :: Requestparse(char* buf){
	char METHOD[5],URI[50];
	sscanf(buf, "%s %s",METHOD,URI);
	/*string METHOD,FILEPATH,VERSION;
	istringstream ss(this.buffer);
	ss>>METHOD>>FILEPATH>>VERSION;
	uri[0] = METHOD;
	uri[1] = FILEPATH;string _uri = geturi();
	string METHOD = uri[0];*/
	if(strcmp(METHOD, "GET"))
		strcpy(method, "GET");
	else if(strcmp(METHOD, "POST"))
		strcpy(method, "POST");
	else if(strcmp(METHOD, "HEAD"))
		strcpy(method,"HEAD");
	else
		strcpy(method,"ERRORRequest");
	strcpy(this->URI, URI);
};

