/*This is an alpha version
 *
 *
 *
 *
 */


//HTTPResponse.cpp

#include "HTTPResponse.h"
//#include "IoWriter.h"
#include "ERRORHEAD.h"
#include <stdexcept>

HTTPResponse :: HTTPResponse(int fd, string uri): fileDescriptor(fd),filename(uri){

};

void HTTPResponse::run()
{
	try{
		cout<<filename<<endl;
		respond();
	}
	catch (ERROR& err){
		return this->responderror(err.errnum, err.msg, err.longmsg);
	}
	catch (runtime_error& err){
		return this->responderror("500","Server internal error",err.what());
	}
}

void HTTPResponse::responderror(const string errnum, const string msg, const string longmsg){
		//
	IoWriter(getfd()).writeString(buildreserrorheaders(errnum, msg)
		+ buildreserrorbody(errnum, msg, longmsg));
	}

const string HTTPResponse::buildreserrorheaders(const string errnum, const string msg){
	return "HTTP/1.0 "+errnum+" "+msg+"\r\n"+string("Content-type: text/html\r\n");

}

const string HTTPResponse::buildreserrorbody(const string errnum,const string msg,const string longmsg){
	string content = "<html><title>Error</title>"
			+string("<body bgcolor= ffffff >\r\n")
			+errnum+": "+msg+"\r\n"+"<p>"+longmsg+": "+filename
			+"<hr><em>The Web server powered by sven</em>\r\n";
	return "Content-length: "+typetostr(content.length())+"\r\n\r\n"
				+content;
}

const string HTTPResponse::typetostr(string::size_type sizeType)//数据转换
{
	stringstream ss;
	string s;
	ss<<sizeType;
	ss>>s;
	return s;
}
const string HTTPResponse::inttostr(int num)
{
	stringstream ss;
	string s;
	ss<<num;
	ss>>s;
	return s;
}

const string HTTPResponse::buildresheaders()
{
	return "HTTP/1.0 200 OK\r\n"+string("Server: Web server by Sven\r\n")
		+string("Content-length: ")+typetostr(getStat().st_size)
		+"\r\n"+"Content-type: "+getfiletype()+/*"charset = utf-8"*/+"\r\n\r\n";
}

const string HTTPResponse::dir_server(){
	string s= "<html><title> Directory </title>"
		+string("<meta http-equiv=""content-type"" content=""text/html;charset = utf-8""> ")	
		+string("<style type=text/css>a:link{text-decoration:none;}</style>")
		+string("<body bgcolor = ffffff font-family=Times NEw Roman color=#fff font-size=16px>\r\n");
	DIR *dp;
	struct dirent *dirp;
	struct stat buf;
	string dir;	
	if((dp=opendir(filename.c_str()))==NULL)
		cout<<"can not open this directory"<<endl;
	int num=1;
	int length = filename.length();
	if(filename[length] == '/'){
		int pos = filename.rfind('/',length);
		dir = filename.substr(pos+1,length);
//		dir = dir+'/';
	}
	else{
		int pos = filename.find_last_of('/');
		dir = filename.substr(pos+1,length);
		dir += '/';
	}
 	s += "<a href=\"/\">/</a>";
	while((dirp = readdir(dp))!=NULL)
	{
		string name = "test/" + dir + dirp->d_name;
		int i = stat(const_cast<char*>(name.c_str()),&buf);
		if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0)
			continue;
		s = s+"<p><pre>"+inttostr(num++)+" <a href="+dir+dirp->d_name+"> "+dirp->d_name+"</a>" +" " + inttostr(buf.st_size)+" "
			+ TimeChange(sbuf.st_mtime)+"</pre></p><br/>";
		//s = s+inttostr(num++)+" "+dirp->d_name+" "+inttostr(buf.st_size)+" "+TimeChange(buf.st_mtime)+"<br/>";
	}
	closedir(dp);
	s += "</body></html>";
	return s;
	
	
}
const string HTTPResponse::TimeChange(const time_t ti)
{
	string time;
	struct tm* date;
	date = localtime(&ti);
	return asctime(date);
}


const string HTTPResponse::getfilename() 
{
	return filename;
}

int HTTPResponse::getfd() const
{
	return fileDescriptor;
}

struct stat& HTTPResponse::getStat()
{
	return sbuf;
}

const string HTTPResponse::getfiletype()
{
	string filename = getfilename();
	if(filename.find(".html"))
		return string("text/html");
	else if (filename.find(".gif"))
		return string("image/gif");
	else if (filename.find(".jpg"))
		return string("image/jpeg");
	else
		return string("application/octet-stream");
}

void HTTPResponse::respond()
{
	//cout<<"respond"<<endl;
	if(stat(const_cast<char*>(filename.c_str()),&sbuf) < 0)//文件是否存在
		throw ERROR("404","Not found","The Web server couldn't find this file.");
	if(/*!(S_ISREG(sbuf.st_mode))||*/!(S_IRUSR & sbuf.st_mode)){//访问权限
	
		throw ERROR("403","Forbidden","Fobidden this request");
	}	
	IoWriter writer(getfd());
	if(S_ISDIR(sbuf.st_mode)){
	//	dir_server();
//		string s = dir_server();
		writer.writeString(buildresheaders());
		writer.writeString(dir_server());
		cout<<"This is a directory!"<<endl;
		
	}
	else{
	//write
	//cout<<"write"<<endl;
	//cout<<"write files"<<endl;
		writer.writeString(buildresheaders());
		writer.writeFile(getfilename(), getStat().st_size);
	}
}
