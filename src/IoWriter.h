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

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/mman.h>
#include <cerrno>
#include <fstream>
#include <iostream>

using namespace std;
class IoWriter
{
public:
	IoWriter(int fd);
	void writeString(const string& str);
	void writeFile(const string& fileName, int filesSize);
	ssize_t SendFile(const string filenName);
private:
	int fileDescriptor;
};



//#endif
