#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "config.pb.h"
#include "login_all.pb.h"
#include "configfiles.pb.h"


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
		for (int i = 0; i < configfile.config_size (); ++i, ++i)
		{
			const qiuwanli::Config& config = configfile.config (i);
			const qiuwanli::Config& config1 = configfile.config (i + 1);
			std::string value = config1.valuestring ();

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
//
//void outdownlogfiles ()
//{
//	qiuwanli::
//	std::fstream input3 ("config", std::ios::in | std::ios::binary);
//	if (!input3)
//		std::cout << "Fail!" << std::endl;
//
//	if (!configfile.ParseFromIstream (&input3))
//	{	//打开失败
//		std::cout << "ParseFromIstream Fail!" << std::endl;
//		input3.close ();
//	}
//	else {	//解析配置文件
//		std::cout << "Size:" << configfile.config_size () << std::endl;
//		for (int i = 0; i < configfile.config_size (); ++i, ++i)
//		{
//			const qiuwanli::Config& config = configfile.config (i);
//			const qiuwanli::Config& config1 = configfile.config (i + 1);
//			std::string value = config1.valuestring ();
//
//			switch ((qiuwanli::Type)config.type ())
//			{
//			case qiuwanli::Type::ThreadNumUp:
//			{
//
//				std::cout << "ThreadNumUp:" << std::endl << atoi (value.c_str ()) << std::endl;
//			}
//			break;
//			case qiuwanli::Type::ThreadNumDown:
//				std::cout << "ThreadNumDown:" << std::endl << atoi (value.c_str ()) << std::endl;
//				break;
//			case qiuwanli::Type::FileUpSpeed:
//				std::wcout << "FileUpSpeed:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
//				break;
//			case qiuwanli::Type::FileDownSpeed:
//				std::wcout << "FileDownSpeed:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
//				break;
//			case qiuwanli::Type::DownFilePath:
//				std::wcout << "DownFilePath:" << std::endl << StringToWstring ((value).c_str ()) << std::endl;
//				break;
//			case qiuwanli::Type::FilePath:
//				std::wcout << "FilePath:" << std::endl << StringToWstring (value).c_str () << std::endl;
//				break;
//			default:	break;
//			}
//		}
//		input3.close ();
//	}
//}


int main ()
{
	std::cout << "生成 Config Files:" << std::endl;
	outconfigfiles ();
	std::cout << "生成 Downlog files:" << std::endl;
	//outdownlogfiles ();
	return 0;
}