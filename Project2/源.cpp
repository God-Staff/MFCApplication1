#include <iostream>
#include <cstdio>
#include <cstring>
#include <boost/shared_ptr.hpp>
#include "fileinfo.hpp"
//#include "login_all.pb.h"

#include <fstream>

//发送文件数据块
void sender (asio::io_service& io, const char* ip_address, unsigned port, const char* filename)
{
	typedef asio::ip::tcp TCP;

	std::ifstream infile (filename,std::ios::binary);
	if (!infile)
	{
		return;
	}
	//使用智能指针，防止程序出现异常时，fclose未被调用。
	//boost::shared_ptr<std::fstream> file_ptr (&infile, fclose);

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

	//get File size
	infile.seekg (0, std::ios::end);
	file_info.filesize = infile.tellg ();
	infile.seekg (0);
	
	std::cout << file_info.filesize << std::endl;

	memcpy (buffer, &file_info, file_info_size);
	memcpy (buffer + file_info_size, filename, filename_size);

	TCP::socket socket (io);
	socket.connect (TCP::endpoint (asio::ip::address_v4::from_string (ip_address), port));

	std::cout << "Sending file : " << filename << "\n";
	size_t len = total_size;
	unsigned long long total_bytes_read = 0;
	while (true) {
		socket.send (asio::buffer (buffer, len), 0);
		if (infile.eof ())
			break;
		//读取File
		infile.read (buffer, k_buffer_size);
		//len = fread (buffer, 1, k_buffer_size, fp);
		//total_bytes_read += len;
	}
	
	infile.close ();

	cost_time = clock () - cost_time;
	if (cost_time == 0) cost_time = 1;
	double speed = total_bytes_read * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / cost_time;
	std::cout << "cost time: " << cost_time / (double)CLOCKS_PER_SEC << " s "
		<< "  transferred_bytes: " << total_bytes_read << " bytes\n"
		<< "speed: " << speed << " MB/s\n\n";
}

int main (int args, char* argc[])
{
  	if (args < 3) {
  		std::cerr << "Usage: " << argc[0] << " ip_address  filename1 filename2 ...\n";
  		return 1;
  	}
  
  	asio::io_service io;
  	for (int i = 2; i < args; ++i) {
  		try { 
  			sender (io, argc[1], 9999, argc[i]); 
  		} catch (std::exception& err) {
  			std::cerr << err.what () << "\n";
  		}
  	}
}
  //
  ////发送文件
  //void func ()
  //{
  //	//文件的输入输出
  //	std::fstream InandOut ("login.ini", std::ios::out | std::ios::in | std::ios::trunc | std::ios::binary);
  //
  //
  //	InandOut << "" << std::endl;
  //}
  //
  ////连接控制
  //
  ////绑定连接
  //
  ////对象序列化输出到文件
  //template<typename T0,typename T1>
  //Path Obj2Files (T0 Obj,T1 filename)
  //{
  //	//将对象序列化到文件流
  //	fstream output (filename, ios::out | ios::trunc | ios::binary);
  //	if (!Obj.SerializeToOstream (&output)) {
  //		cerr << "Failed to write address book." << endl;
  //		return nullptr;
  //	}
  //	return std::move (output);
  //}
