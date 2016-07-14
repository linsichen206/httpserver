/* This is an alpha version
 *
 *
 *
 *
 *
 *
 *
 */

//ERRORHEAR.h
//

struct ERROR
{
	ERROR(const string& errnum, const string& msg, const string& longmsg):errnum(errnum),msg(msg),longmsg(longmsg)
	{}
	~ERROR()
	{}
	string errnum;
	string msg;
	string longmsg;
};
