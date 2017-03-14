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
class utilty 
{
public:
	void sender (asio::io_service &io, const char*	ip_address, unsigned	port, const char* filename)
	{
		typedef asio::ip::tcp TCP;

		FILE *fp;
		fopen_s (&fp, filename, "rb");
		if (fp == NULL) {
			std::cerr << "cannot open file\n";
			return;
		}

		//使用智能指针，防止程序出现异常时，fclose未被调用。
		boost::shared_ptr<FILE> file_ptr (fp, fclose);

		clock_t cost_time = clock ();

		const size_t k_buffer_size = 32 * 1024;
		char buffer[k_buffer_size];
		File_info file_info;

		int filename_size = strlen (filename) + 1;
		size_t file_info_size = sizeof (file_info);
		size_t total_size = file_info_size + filename_size;
		if (total_size > k_buffer_size) {
			std::cerr << "File name is too long";
			return;
		}
		file_info.filename_size = filename_size;

		fseek (fp, 0, SEEK_END);
		file_info.filesize = ftell (fp);
		rewind (fp);

		memcpy (buffer, &file_info, file_info_size);
		memcpy (buffer + file_info_size, filename, filename_size);

		TCP::socket socket (io);
		socket.connect (TCP::endpoint (asio::ip::address_v4::from_string (ip_address), port));

		std::cout << "Sending file : " << filename << "\n";
		size_t len = total_size;
		unsigned long long total_bytes_read = 0;
		while (true) {
			socket.send (asio::buffer (buffer, len), 0);
			if (feof (fp)) break;
			len = fread (buffer, 1, k_buffer_size, fp);
			total_bytes_read += len;
		}

		//计算时间、大小和速度//
		cost_time = clock () - cost_time;
		if (cost_time == 0) cost_time = 1;
		double speed = total_bytes_read * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / cost_time;
		std::cout << "cost time: " << cost_time / (double)CLOCKS_PER_SEC << " s "
			<< "  transferred_bytes: " << total_bytes_read << " bytes\n"
			<< "speed: " << speed << " MB/s\n\n";
	}

	std::wstring StringToWstring (const std::string& str)
	{
		int size_needed = MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), NULL, 0);
		std::wstring wstrTo (size_needed, 0);
		MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), &wstrTo[0], size_needed);
		return wstrTo;
	}
};
	
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
