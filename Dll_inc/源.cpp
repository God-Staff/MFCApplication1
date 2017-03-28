#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "config.pb.h"
#include "MyDataStruct.pb.h"
#include <boost/uuid/name_generator.hpp>
#include <boost/uuid/sha1.hpp>
#include <boost/uuid/string_generator.hpp>
#include <boost/lexical_cast.hpp>

std::wstring StringToWstring (const std::string& str)
{
	int size_needed = MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), NULL, 0);
	std::wstring wstrTo (size_needed, 0);
	MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), &wstrTo[0], size_needed);
	return wstrTo;
}

void outconfigfiles ()
{
	qiuwanli::ConfigFile configfile;
	std::fstream input3 ("config", std::ios::in | std::ios::binary);
	if (!input3)
		std::cout << "Fail!" << std::endl;

	if (!configfile.ParseFromIstream (&input3)){	//打开失败
		std::cout << "ParseFromIstream Fail!" << std::endl;
		input3.close ();
	}
	else {	//解析配置文件
		std::cout << "Size:" << configfile.config_size () << std::endl;
		for (int i = 0; i < configfile.config_size (); ++i)
		{
			const qiuwanli::Config& config = configfile.config (i);
			//const qiuwanli::Config& config1 = configfile.config (i + 1);
			std::string value = config.valuestring ();

			switch ((qiuwanli::Type)config.type ())
			{
			case qiuwanli::Type::ThreadNumUp:
				std::cout << "ThreadNumUp:" << std::endl << atoi (value.c_str ()) << std::endl;
				break;
			case qiuwanli::Type::ThreadNumDown:
				std::cout << "ThreadNumDown:" << std::endl << atoi (value.c_str ()) << std::endl;
				break;
			case qiuwanli::Type::FileUpSpeed:
				std::wcout << "FileUpSpeed:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
				break;
			case qiuwanli::Type::FileDownSpeed:
				std::wcout << "FileDownSpeed:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
				break;
			case qiuwanli::Type::DownFilePath:
				std::wcout << "DownFilePath:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
				break;
			case qiuwanli::Type::FilePath:
				std::wcout << "FilePath:" << std::endl << StringToWstring (value).c_str () << std::endl;
				break;
			default:	break;
			}
		}
		input3.close ();
	}
}

void outdownlogfiles ()
{
	qiuwanli::FileDownLogFile configfile;
	std::fstream input3 ("downlog", std::ios::in | std::ios::binary);
	if (!input3)
		std::cout << "Fail!" << std::endl;

	if (!configfile.ParseFromIstream (&input3)) {	//打开失败
		std::cout << "ParseFromIstream Fail!" << std::endl;
		input3.close ();
	}
	else {	//解析配置文件
		std::cout << "Size:" << configfile.filelog_size() << std::endl;
		for (int i = 0; i < configfile.filelog_size (); ++i)
		{
			const qiuwanli::FileDownLog& config = configfile.filelog (i);
			//const qiuwanli::FileDownLog& config1 = configfile.filelog (i + 1);
			//std::string value = config1.valuestring ();
			std::cout << config.filename () << std::endl; 
			std::cout << config.filepath () << std::endl;
			std::cout << config.filesize () << std::endl;
			std::cout << config.downtime () << std::endl; 
			std::cout << config.status () << std::endl;
		}
		input3.close ();
	}
}

//获取CPU序列号
std::string getCPU ()
{
	char *lpszCpu;
	const long MAX_COMMAND_SIZE = 10000; // 命令行输出缓冲大小     
	WCHAR szFetCmd[] = L"wmic cpu get processorid"; // 获取CPU序列号命令行    
	const std::string strEnSearch = "ProcessorId"; // CPU序列号的前导信息  

	BOOL   bret = FALSE;
	HANDLE hReadPipe = NULL; //读取管道  
	HANDLE hWritePipe = NULL; //写入管道      
	PROCESS_INFORMATION pi;   //进程信息      
	STARTUPINFO         si;   //控制命令行窗口信息  
	SECURITY_ATTRIBUTES sa;   //安全属性  

	char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // 放置命令行结果的输出缓冲区  
	std::string          strBuffer;
	unsigned long   count = 0;
	long            ipos = 0;

	memset (&pi, 0, sizeof (pi));
	memset (&si, 0, sizeof (si));
	memset (&sa, 0, sizeof (sa));

	pi.hProcess = NULL;
	pi.hThread = NULL;
	si.cb = sizeof (STARTUPINFO);
	sa.nLength = sizeof (SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//1.0 创建管道  
	bret = CreatePipe (&hReadPipe, &hWritePipe, &sa, 0);
	if (!bret)
		goto END;

	//2.0 设置命令行窗口的信息为指定的读写管道  
	GetStartupInfo (&si);
	si.hStdError = hWritePipe;
	si.hStdOutput = hWritePipe;
	si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	//3.0 创建获取命令行的进程  
	bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	if (!bret)
		goto END;

	//4.0 读取返回的数据  
	WaitForSingleObject (pi.hProcess, 500/*INFINITE*/);
	bret = ReadFile (hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
	if (!bret)
		goto END;

	//5.0 查找CPU序列号  
	bret = FALSE;
	strBuffer = szBuffer;
	ipos = strBuffer.find (strEnSearch);

	if (ipos < 0) // 没有找到  
		goto END;
	else
		strBuffer = strBuffer.substr (ipos + strEnSearch.length ());


	memset (szBuffer, 0x00, sizeof (szBuffer));
	strcpy_s (szBuffer, strBuffer.c_str ());

	//去掉中间的空格 \r \n  
	int j = 0;
	for (int i = 0; i < strlen (szBuffer); i++)
	{
		if (szBuffer[i] != ' ' && szBuffer[i] != '\n' && szBuffer[i] != '\r')
		{
			lpszCpu[j] = szBuffer[i];
			j++;
		}
	}

	bret = TRUE;

END:
	//关闭所有的句柄  
	CloseHandle (hWritePipe);
	CloseHandle (hReadPipe);
	CloseHandle (pi.hProcess);
	CloseHandle (pi.hThread);

	return std::move (lpszCpu);
}

//获取主板序列号
std::string getBios ()
{
	char *lpszBaseBoard;
	const long MAX_COMMAND_SIZE = 10000; // 命令行输出缓冲大小     
	WCHAR szFetCmd[] = L"wmic BaseBoard get SerialNumber"; // 获取主板序列号命令行   
	const std::string strEnSearch = "SerialNumber"; // 主板序列号的前导信息  

	BOOL   bret = FALSE;
	HANDLE hReadPipe = NULL; //读取管道  
	HANDLE hWritePipe = NULL; //写入管道      
	PROCESS_INFORMATION pi;   //进程信息      
	STARTUPINFO         si;   //控制命令行窗口信息  
	SECURITY_ATTRIBUTES sa;   //安全属性  

	char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // 放置命令行结果的输出缓冲区  
	std::string          strBuffer;
	unsigned long   count = 0;
	long            ipos = 0;

	memset (&pi, 0, sizeof (pi));
	memset (&si, 0, sizeof (si));
	memset (&sa, 0, sizeof (sa));

	pi.hProcess = NULL;
	pi.hThread = NULL;
	si.cb = sizeof (STARTUPINFO);
	sa.nLength = sizeof (SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//1.0 创建管道  
	bret = CreatePipe (&hReadPipe, &hWritePipe, &sa, 0);
	if (!bret)
		goto END;

	//2.0 设置命令行窗口的信息为指定的读写管道  
	GetStartupInfo (&si);
	si.hStdError = hWritePipe;
	si.hStdOutput = hWritePipe;
	si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

	//3.0 创建获取命令行的进程  
	bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	if (!bret)
		goto END;

	//4.0 读取返回的数据  
	WaitForSingleObject (pi.hProcess, 500/*INFINITE*/);
	bret = ReadFile (hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
	if (!bret)
		goto END;

	//5.0 查找主板序列号  
	bret = FALSE;
	strBuffer = szBuffer;
	ipos = strBuffer.find (strEnSearch);

	if (ipos < 0) // 没有找到  
		goto END;
	else
		strBuffer = strBuffer.substr (ipos + strEnSearch.length ());

	memset (szBuffer, 0x00, sizeof (szBuffer));
	strcpy_s (szBuffer, strBuffer.c_str ());

	//去掉中间的空格 \r \n  
	int j = 0;
	for (int i = 0; i < strlen (szBuffer); i++)
	{
		if (szBuffer[i] != ' ' && szBuffer[i] != '\n' && szBuffer[i] != '\r')
		{
			lpszBaseBoard[j] = szBuffer[i];
			j++;
		}
	}

	bret = TRUE;

END:
	//关闭所有的句柄  
	CloseHandle (hWritePipe);
	CloseHandle (hReadPipe);
	CloseHandle (pi.hProcess);
	CloseHandle (pi.hThread);

	return std::move (lpszBaseBoard);
}
//生成UUID
std::string getUuid ()
{
	boost::uuids::uuid dns_namespace_uuid;

	boost::uuids::name_generator gen (dns_namespace_uuid);
	boost::uuids::uuid u = gen (getCPU () + getBios ());
	std::string uuid = boost::lexical_cast<std::string>(u);

	return std::move (uuid);
}

int main ()
{
	std::cout << "生成 Config Files:" << std::endl;
	outconfigfiles ();
	std::cout << "生成 Downlog files:" << std::endl;
	outdownlogfiles ();
	std::cout << "UUID:" << getUuid () << std::endl;
	return 0;
}