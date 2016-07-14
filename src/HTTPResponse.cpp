/*This is an alpha version
 *
 *
 *
 *
 */


//HTTPResponse.cpp

#include "HTTPResponse.h"


HTTPResponse :: HTTPResponse(){

};

void HTTPResponse :: Requestparse(char*buf, HTTPRequest* request){
	char filename[100];
	parse_uri(request->URI);
	if(strcmp(request->method,"GET"))
		DealGET(buf,filename);
	else if(strcmp(request->method,"POST"))
	{}//	DealPOST(filename);
	else{}
	//	ERRORRequest;	
};

void HTTPResponse :: parse_uri(char* uri){
	char* cwd;
	char tmpcwd[100];
	cwd = (char*)get_current_dir_name();
	strcpy(tmpcwd,cwd);
	strcat(tmpcwd,"/");
	strcat(tmpcwd,uri); 
};

void HTTPResponse :: DealGET(char*buf, char* filename){
	//char buf[MAXSIZE];
	sprintf(buf, "HTTP/1.0 200 OK\r\n");
	//strcat(buf, " Server:Web Server by Sven Lin\r\n\0");
	sprintf(buf,"Server:Web Server By Sven. ");
	//cout<<buf<<endl;
	//return buf;
};	
 
