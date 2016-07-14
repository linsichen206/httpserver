/*This is an alpha version
 *
 *
 *
 *
 *
 */

#include <string>
#include <stdio.h>
using namespace std;
class HTTPGetRequest
{
public:
	HTTPGetRequest(int fd, string uri);
	~HTTPGetRequest();
	void run();
	bool parse_uri();
private:
	const &string geturi() const;
	int getfd() const;
	int fileDescriptor;
	string uri;

};
