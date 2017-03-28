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
	//�洢��ʱ��MD5ֵ
	char buffer[128];
public:

	//��ȡ�������к�
	std::string getBios ();
	//��ȡCPU���к�
	std::string  getCPU ();
	//����UUID
	std::string getUuid ();
	//�����ļ�
	void sendFile () ;
	//�����ļ��б�
	void sendFiles () ;
	//������Ϣ
	void sendMsg () ;
	//������������
	void sendHeart ();
	void sender (boost::asio::io_service &io, const char*	ip_address, unsigned	port, const char* filename, const char* msg_type);
	
	std::wstring StringToWstring (const std::string& str);
	std::string & WStringToUTF8String (const std::wstring &wstr);

	bool UTF8StringToWCharString (const std::string &u8str, std::wstring &wstr);
	std::wstring s2ws (const std::string& s);

	/**
	* ����ļ��ľ���·��������Ϊ�ı���ʽ(ZH_CN��������)
	* �����ļ���MD5���ļ���С
	* @param 	p 		�ļ�·��
	* @param	file 	�ļ�ָ��
	*/
	void pathAll (boost::filesystem::path p, boost::filesystem::ofstream & file);

};

//����ļ��б䶯����	

//Ҫ�������ļ���
void MonitorDir (std::string files);
 //�ļ����б�,������ͬ�Ľ��̽��м���
bool watchDirs (std::string &dirs, int  nums);



}//end namespace 

#endif //End MY_UTILITY_HPP

