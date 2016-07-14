/* This is the alpha version
 *
 *
 *
 *
 *
 */

//Requset.h
#define MAXMETHODLINE 10
#define MAXURILINE 50


class HTTPRequest{
public:
	HTTPRequest(char *);
	~HTTPRequest();
	void Requestparse(char *);
	char method[MAXMETHODLINE];
	char URI[MAXURILINE];
};

