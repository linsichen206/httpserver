#include "IoWriter.h"
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
	ssize_t nwritten = 0;
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
//fsync(fd);
//
//		printf("msg[%s],nwriten[%d],nleft[%d]",bufp,nwritten,nleft-nwritten);
		nleft -= nwritten;
		bufp += nwritten;
	}

	return n;
}

void Rio_writen(int fd, void *usrbuf, size_t n)
{
	if (rio_writen(fd, usrbuf, n) != n){
		cout<<"Rio_writen error"<<endl;
		cout<<errno<<endl;
	}
}

int Open(const char *pathname, int flags, mode_t mode)
{
	int rc;

	if ((rc = open(pathname, flags, mode)) < 0){
		cout<<"Open error"<<endl;
		cout<<errno<<endl;
	}
	return rc;
}

void Close(int fd)
{
	int rc;

	if ((rc = close(fd)) < 0){
		cout<<"Close error"<<endl;	
		cout<<errno<<endl;
	}
}

void* Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
	void *ptr;

	if ((ptr = mmap(addr, len, prot, flags, fd, offset)) == ((void *) -1)){
		cout<<"mmap error"<<endl;
		cout<<errno<<endl;
	}
	return (ptr);
}

void Munmap(void *start, size_t length)
{
	if (munmap(start, length) < 0){
		cout<<"munmap error"<<endl;
		cout<<errno<<endl;
	}
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
	//int len = lseek(srcfd,0,SEEK_END);
	//char *p = (char *)malloc(len + 1);
	//bzero(p,len+1);
	//lseek(srcfd,0,SEEK_SET);
	//int ret = read(srcfd,p,len);
	Close(srcfd);
	//write(fileDescriptor,p,filesSize);
	Rio_writen(fileDescriptor, srcp, filesSize);
	Munmap(srcp, filesSize);
}

ssize_t IoWriter::SendFile(const string fileName)
{
         ifstream in(fileName.c_str(),std::ios::binary);
         in.seekg(0, std::ios::end);
         
	 std::streampos ps = in.tellg();
         int pos = 0;
	 //int64_t len=ps-pos;
         if(pos!=0){
         //    setStatusCode("206 Partial Content");
         }
         //setContentType("application/octet-stream");
         //setContentLength(len);
         //string content="bytes";
         //content+=" "+Utils::toString(pos)+"-"+Utils::toString((int64_t)ps-1)+"/"+Utils::toString(len);
         //setContentRange(content);
         //std::string header=getHeader();
         //std::cout<<header<<std::endl;
         //s.server_write(confd,(char*)header.c_str(),header.size());
         in.seekg(pos,std::ios::beg);
         char buf[1024];
         ssize_t n=0;
         while(!in.eof()){
             in.read(buf,1024);
             n+=write(fileDescriptor,buf,in.gcount());
         }
         //close(fd);
         return n;
}
