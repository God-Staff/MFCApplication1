#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP


//#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <locale> 
#include <codecvt>
#include <iostream>
#include <cstdio>
#include <boost/shared_ptr.hpp>
#include "fileinfo.hpp"
//#include <boost/asio.hpp>

namespace qiuwanli
{
	//void sender (asio::io_service &io, const char*	ip_address, unsigned	port, const char* filename)
	//{
	//	typedef asio::ip::tcp TCP;

	//	FILE *fp;
	//	fopen_s (&fp, filename, "rb");
	//	if (fp == NULL) {
	//		std::cerr << "cannot open file\n";
	//		return;
	//	}

	//	//使用智能指针，防止程序出现异常时，fclose未被调用。
	//	boost::shared_ptr<FILE> file_ptr (fp, fclose);

	//	clock_t cost_time = clock ();

	//	const size_t k_buffer_size = 32 * 1024;
	//	char buffer[k_buffer_size];
	//	File_info file_info;

	//	int filename_size = strlen (filename) + 1;
	//	size_t file_info_size = sizeof (file_info);
	//	size_t total_size = file_info_size + filename_size;
	//	if (total_size > k_buffer_size) {
	//		std::cerr << "File name is too long";
	//		return;
	//	}
	//	file_info.filename_size = filename_size;

	//	fseek (fp, 0, SEEK_END);
	//	file_info.filesize = ftell (fp);
	//	rewind (fp);

	//	memcpy (buffer, &file_info, file_info_size);
	//	memcpy (buffer + file_info_size, filename, filename_size);

	//	TCP::socket socket (io);
	//	socket.connect (TCP::endpoint (asio::ip::address_v4::from_string (ip_address), port));

	//	std::cout << "Sending file : " << filename << "\n";
	//	size_t len = total_size;
	//	unsigned long long total_bytes_read = 0;
	//	while (true) {
	//		socket.send (asio::buffer (buffer, len), 0);
	//		if (feof (fp)) break;
	//		len = fread (buffer, 1, k_buffer_size, fp);
	//		total_bytes_read += len;
	//	}

	//	cost_time = clock () - cost_time;
	//	if (cost_time == 0) cost_time = 1;
	//	double speed = total_bytes_read * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / cost_time;
	//	std::cout << "cost time: " << cost_time / (double)CLOCKS_PER_SEC << " s "
	//		<< "  transferred_bytes: " << total_bytes_read << " bytes\n"
	//		<< "speed: " << speed << " MB/s\n\n";
	//}

	//std::wstring StringToWstring (const std::string& str)
	//{
	//	int size_needed = MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), NULL, 0);
	//	std::wstring wstrTo (size_needed, 0);
	//	MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), &wstrTo[0], size_needed);
	//	return wstrTo;
	//}
}//end namespace 

#endif //End MY_UTILITY_HPP
/*

	bool WideStringToString (const std::wstring& src, std::string &str)
	{
		std::locale sys_locale ("");

		const wchar_t* data_from = src.c_str ();
		const wchar_t* data_from_end = src.c_str () + src.size ();
		const wchar_t* data_from_next = 0;

		int wchar_size = 4;
		char* data_to = new char[(src.size () + 1) * wchar_size];
		char* data_to_end = data_to + (src.size () + 1) * wchar_size;
		char* data_to_next = 0;

		memset (data_to, 0, (src.size () + 1) * wchar_size);

		typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
		mbstate_t out_state = { 0 };
		auto result = std::use_facet<convert_facet> (sys_locale).out (
			out_state, data_from, data_from_end, data_from_next,
			data_to, data_to_end, data_to_next);
		if (result == convert_facet::ok)
		{
			str = data_to;
			delete[] data_to;
			return true;
		}
		delete[] data_to;
		return false;
	}

	bool StringToWideString (const std::string& src, std::wstring &wstr)
	{
		std::locale sys_locale ("");
		const char* data_from = src.c_str ();
		const char* data_from_end = src.c_str () + src.size ();
		const char* data_from_next = 0;

		wchar_t* data_to = new wchar_t[src.size () + 1];
		wchar_t* data_to_end = data_to + src.size () + 1;
		wchar_t* data_to_next = 0;

		wmemset (data_to, 0, src.size () + 1);

		typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
		mbstate_t in_state = { 0 };
		auto result = std::use_facet<convert_facet> (sys_locale).in (
			in_state, data_from, data_from_end, data_from_next,
			data_to, data_to_end, data_to_next);
		if (result == convert_facet::ok)
		{
			wstr = data_to;
			delete[] data_to;
			return true;
		}
		delete[] data_to;
		return false;
	}


	bool WCharStringToUTF8String (const std::wstring &wstr, std::string &u8str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		u8str = conv.to_bytes (wstr);
		return true;
	}

	bool UTF8StringToWCharString (const std::string &u8str, std::wstring &wstr)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t> > conv;
		wstr = conv.from_bytes (u8str);
		return true;
	}
*/


//std::string raw_string = "汉字 this is string"; //GBK to UFT8 
//std::string utf8_string1 = boost::locale::conv::to_utf(raw_string,"GBK");
//std::string utf8_string2 = boost::locale::conv::between(raw_string, "UTF-8", "GBK"); // UFT8 to GBK 
//std::string gbk_string1 = boost::locale::conv::from_utf( utf8_string1, "GBK" ); 
//std::string gbk_string2 = boost::locale::conv::between(utf8_string1,"GBK","UTF-8"); //宽字符处理使用 
//std::wstring和boost::locale::conv::to_utf boost::locale::conv::between不支持
//std::wstring utf16->utf8 boost::locale::conv::utf_to_utf()； 由于utf16 和 utf8都是unicode编码，所以函数名叫utf_to_utf。

//int main ()
//{
//	std::string str = "我是SunboyL。";
//	std::wstring str1 = StringToWstring (str);// string转换为wstring
//
//	str1 = L"我是不是SunboyL。";
//	str = WstringToString (str1);// wstring转换为string
//	return 0;
//}



// 需包含locale、string头文件、使用setlocale函数。
//std::wstring StringToWstring (const std::string str)
//{// string转wstring
//	unsigned len = str.size () * 2;// 预留字节数
//	setlocale (LC_CTYPE, "");     //必须调用此函数
//	wchar_t *p = new wchar_t[len];// 申请一段内存存放转换后的字符串
//	mbstowcs (p, str.c_str (), len);// 转换
//	std::wstring str1 (p);
//	delete[] p;// 释放申请的内存
//	return str1;
//}

//std::string WstringToString (const std::wstring str)
//{// wstring转string
//	unsigned len = str.size () * 4;
//	setlocale (LC_CTYPE, "");
//	char *p = new char[len];
//	wcstombs (p, str.c_str (), len);
//	std::string str1 (p);
//	delete[] p;
//	return str1;
//}


//using namespace std;
//std::string WstringToString (const std::wstring& ws)
//{
//	std::string curLocale = setlocale (LC_ALL, NULL); // curLocale = "C";
//	setlocale (LC_ALL, "chs");
//	const wchar_t* _Source = ws.c_str ();
//	size_t _Dsize = 2 * ws.size () + 1;
//	char *_Dest = new char[_Dsize];
//	memset (_Dest, 0, _Dsize);
//	wcstombs (_Dest, _Source, _Dsize);
//	std::string result = _Dest;
//	delete[]_Dest;
//	setlocale (LC_ALL, curLocale.c_str ());
//	return result;
//}
//std::wstring StringToWstring (const std::string& s)
