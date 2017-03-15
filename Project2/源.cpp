#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <boost/shared_ptr.hpp>
#include "fileinfo.hpp"
#include "asio.hpp"


void sender (asio::io_service& io, const char* ip_address, unsigned port, const char* filename)//,unsigned char msg_type/*��Ϣ����*/)
{
	typedef asio::ip::tcp TCP;

	FILE *fp = fopen (filename, "rb");
	if (fp == NULL) {
		std::cerr << "cannot open file\n";
		return;
	}

	//ʹ������ָ�룬��ֹ��������쳣ʱ��fcloseδ�����á�
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
	//file_info.msg_type = msg_type;			//��Ϣ����

	fseek (fp, 0, SEEK_END);
	file_info.filesize = ftell (fp);
	rewind (fp);

	//����Ҫ�����ļ���Ϣ+�ļ�����buffer
	memcpy (buffer, &file_info, file_info_size);
	memcpy (buffer + file_info_size, filename, filename_size);

	TCP::socket socket (io);
	socket.connect (TCP::endpoint (asio::ip::address_v4::from_string (ip_address), port));

	std::cout << "Sending file : " << filename << "\n";
	size_t len = total_size;
	unsigned long long total_bytes_read = 0;
	while (true) {
		//��һ���Ȱ��ļ�ͷ��Ϣ���͹�ȥ//֮���͵������ݰ�
		socket.send (asio::buffer (buffer, len), 0);
		if (feof (fp)) break;
		len = fread (buffer, 1, k_buffer_size, fp);
		total_bytes_read += len;
	}

	cost_time = clock () - cost_time;
	if (cost_time == 0) cost_time = 1;
	double speed = total_bytes_read * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / cost_time;
	std::cout << "cost time: " << cost_time / (double)CLOCKS_PER_SEC << " s "
		<< "  transferred_bytes: " << total_bytes_read << " bytes\n"
		<< "speed: " << speed << " MB/s\n\n";
}

//�������ýӿ� exeName IP Port files1 files2 ...
int main (int args, char* argc[])
{
	if (args < 4) {
		std::cerr << "Usage: " << argc[0] << " ip_address  filename1 filename2 ...\n";
		return 1;
	}

	asio::io_service io;
	for (int i = 3; i < args; ++i) {
		try { sender (io, argc[1], 9999, argc[i]); }
		catch (std::exception& err) {
			std::cerr << err.what () << "\n";
		}
	}
}