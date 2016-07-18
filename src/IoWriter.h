/*This is an alpha version
 *
 *
 * this file is used to write
 *
 *
 */


//IoWriter.h
//
//#ifndef IOWRITER_H_
//#define IOWRITER_H_

#include <string>
using namespace std;
class IoWriter
{
public:
	IoWriter(int fd);
	void writeString(const string& str);
	void writeFile(const string& fileName, int filesSize);
private:
	int fileDescriptor;
};



//#endif
