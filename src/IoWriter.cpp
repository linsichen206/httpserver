#include "IoWriter.h"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/mman.h>
#include <cerrno>
#include <iostream>

/*namespace
{
void throw(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}*/

ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nwritten;
	char *bufp = reinterpret_cast<char*>(usrbuf);

	while (nleft > 0)
	{
		if ((nwritten = write(fd, bufp, nleft)) <= 0)
		{
			if (errno == EINTR) /* interrupted by sig handler return */
				nwritten = 0; /* and call write() again */
			else
				return -1; /* errorno set by write() */
		}
		nleft -= nwritten;
		bufp += nwritten;
	}
	return n;
}

void Rio_writen(int fd, void *usrbuf, size_t n)
{
	if (rio_writen(fd, usrbuf, n) != n)
		throw("Rio_writen error");
}

int Open(const char *pathname, int flags, mode_t mode)
{
	int rc;

	if ((rc = open(pathname, flags, mode)) < 0)
		throw("Open error");
	return rc;
}

void Close(int fd)
{
	int rc;

	if ((rc = close(fd)) < 0)
		throw("Close error");
}

void* Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	void *ptr;

	if ((ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1))
		throw("mmap error");
	return (ptr);
}

void Munmap(void *start, size_t length)
{
	if (munmap(start, length) < 0)
		throw("munmap error");
}


IoWriter::IoWriter(int fd) : fileDescriptor(fd)
{

}

void IoWriter::writeString(const string& str)
{
	Rio_writen(fileDescriptor, const_cast<char*>(str.c_str()), str.length());
}

void IoWriter::writeFile(const string& fileName, int filesSize)
{
	int srcfd;
	char *srcp;
	srcfd = Open(const_cast<char*>(fileName.c_str()), O_RDONLY, 0);
	srcp = reinterpret_cast<char*>(Mmap(0, filesSize, PROT_READ, MAP_PRIVATE,srcfd, 0));
	Close(srcfd);
	Rio_writen(fileDescriptor, srcp, filesSize);
	Munmap(srcp, filesSize);
}
