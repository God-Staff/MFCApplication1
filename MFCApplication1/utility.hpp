#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP
//#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <locale> 
#include <codecvt>
#include <iostream>
#include <cstdio>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <thread>
#include <windows.h>  
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/filesystem.hpp>
#include "fileinfo.hpp"
#include "MD5.hpp"
#include "MyDataStruct.pb.h"
#include "config.pb.h"
namespace qiuwanli
{
class utilty 
{
private:
	boost::asio::io_service io_ser;
	const char* ip_addre;
	unsigned port;
	typedef boost::asio::ip::tcp TCP;
	//存储临时的MD5值
	char buffer[128];
public:

	//获取主板序列号
	std::string getBios ();
	//获取CPU序列号
	std::string  getCPU ();
	//生成UUID
	std::string getUuid ();
	//发送文件
	void sendFile () ;
	//发送文件列表
	void sendFiles () ;
	//发送消息
	void sendMsg () ;
	//发送心跳连接
	void sendHeart ();
	void sender (boost::asio::io_service &io, const char*	ip_address, unsigned	port, const char* filename, const char* msg_type);
	
	std::wstring StringToWstring (const std::string& str);
	std::string & WStringToUTF8String (const std::wstring &wstr);

	bool UTF8StringToWCharString (const std::string &u8str, std::wstring &wstr);
	std::wstring s2ws (const std::string& s);

	/**
	* 获得文件的绝对路径，保存为文本格式(ZH_CN编码待解决)
	* 计算文件的MD5和文件大小
	* @param 	p 		文件路径
	* @param	file 	文件指针
	*/
	void pathAll (boost::filesystem::path p, boost::filesystem::ofstream & file);

};

//多个文件夹变动监听	

//要监听的文件夹
void MonitorDir (std::string files);
 //文件夹列表,创建不同的进程进行监听
bool watchDirs (std::string &dirs, int  nums);



}//end namespace 

#endif //End MY_UTILITY_HPP

