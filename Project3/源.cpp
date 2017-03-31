//www.cnblogs.com/flyinghearts
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include "fileinfo.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <fstream>
#include "login_all.pb.h"
#include "boost/regex.hpp"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/thread.hpp>

class Session : public boost::enable_shared_from_this<Session> 
{
public:
	typedef boost::asio::ip::tcp TCP;
	typedef boost::system::error_code Error;
	typedef boost::shared_ptr<Session> Pointer;
	typedef File_info::Size_type Size_type;

	static void print_asio_error (const Error& error) 
	{ 
		std::cerr << error.message () << "\n"; 
	}

	static Pointer create (boost::asio::io_service& io) 
	{ 
		return Pointer (new Session (io)); 
	}

	TCP::socket& socket () { return socket_; }

	~Session ()
	{
		if (fp_) fclose (fp_);
		clock_ = clock () - clock_;
		Size_type bytes_writen = total_bytes_writen_;
		if (clock_ == 0) clock_ = 1;
		double speed = bytes_writen * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / clock_;
		std::cout << "cost time: " << clock_ / (double)CLOCKS_PER_SEC << " s  "
			<< "bytes_writen: " << bytes_writen << " bytes\n"
			<< "speed: " << speed << " MB/s\n\n";

		//���ļ��������ʱ�����ļ��������ļ�����
		qiuwanli::user u;
		std::fstream input ("login", std::ios::in | std::ios::binary);
		u.ParseFromIstream (&input);
		std::cout << u.user_id () << std::endl << u.user_type () << std::endl <<
			u.user_password_md5 () << std::endl << u.login_code () << std::endl <<
			u.user_name () << std::endl << u.user_client_uuid () << std::endl;
	}

	void start ()
	{
		clock_ = clock ();
		std::cout << "client: " << socket_.remote_endpoint ().address () << "\n";
		socket_.async_receive (
			boost::asio::buffer (reinterpret_cast<char*>(&file_info_), sizeof (file_info_)),
			boost::bind (&Session::handle_header, shared_from_this (), boost::asio::placeholders::error));
	}

private:
	Session (boost::asio::io_service& io) : 
		socket_ (io), fp_ (NULL), total_bytes_writen_ (0) 
	{ }

	void handle_header (const Error& error)
	{
		if (error) return print_asio_error (error);
		size_t filename_size = file_info_.filename_size;
		if ((filename_size) > k_buffer_size) {
			std::cerr << "Path name is too long!\n";
			return;
		}
		//����async_read, ������async_read_some����ֹ·��������ʱ��һ�ν��ղ���
		boost::asio::async_read (socket_, boost::asio::buffer (buffer_, file_info_.filename_size),
			boost::bind (&Session::handle_file, shared_from_this (), boost::asio::placeholders::error));
	}

	//�����ܵ������ݿ飬����Ϊ�ļ���+�ļ�����
	void handle_file (const Error& error)
	{
		if (error) 
			return print_asio_error (error);
		const char *base_name_msg = buffer_+file_info_.filename_size - 1;
		while (base_name_msg >= buffer_ && (*base_name_msg != '\\' && *base_name_msg != '/'))
			--base_name_msg;
		++base_name_msg;

		const char *basename = "";
		//const char *msg_type = "";

		//��const char* �ָ�
		std::string str (base_name_msg);
		std::vector<std::string>  vstr;
		boost::split (vstr, str, boost::is_any_of ("+"), boost::token_compress_on);
		basename = vstr[0].c_str ();
		//msg_type = vstr[1].c_str ();;

		std::cout << "base_name_msg:" << base_name_msg << std::endl;
		std::cout << "basename:" << basename << std::endl;
		std::cout << "msg_type:" << vstr[1] << std::endl;

		std::cout << "Open file: " << basename << " (" << buffer_ << ")\n";

		fp_ = fopen (basename, "wb");
		if (fp_ == NULL) {
			std::cerr << "Failed to open file to write\n";
			return;
		}

		switch (std::stoi(vstr[1]))
		{
		case	996:	//�û�ע����Ϣ//
			break;
		case	997:	//ע����//
			break;
		case	998:	//��ȡ��֤��//
			break;
		case	999:	//ʵ����֤��Ϣ//
			break;
		case	1001:	//��½��Ϣ//
			receive_file_content ();
			break;
		case	1002:	//��¼��֤��Ϣ//
			break;
		case	1003:	//�����û���Ϣ��Server//
			break;
		case	1004:	//Servers�����û�����ϸ��Ϣ//
			break;
		case	1005:	//�����û�ʵ����֤��Ϣ//
			break;
		case	1006:   //Servers�����û�ʵ����Ϣ��֤���//
			break;  
		case	1007:   //���ͱ����ļ��б�//
			break;
		case	1008:   //���ͱ����ļ������б�//
			break;
		case	1009:   //�����ļ�ɾ���б�//
			break;
		case	1010:   //���ͷ������ӵ����ݿ飨�����ļ��û����Լ��ļ��б�//
			break;
		case	1011:   //��ȡ�û������б�//
			break;
		case	1012:   //��Ӻ���//
			break;
		case	1013:   //ɾ������//
			break;
		case	1014:   //����ѷ����ļ�����//
			break;
		case	1015:   //�����ļ������б�//
			break;
		case	1016:   //Servers�����ļ���Ӧ��IP��port���û������Լ��û�����֤��Ϣ//
			break;
		case	1017:   //��������//
			break;
		case	1018:   //������û�������//
			break;
		case	1019:   //P2P�����ļ������б�//
			break;
		case	1020:   //��ȡ�û���Ӧ��Server�䷢�ĵ���֤��Ϣ//
			break;
		case	1021:   //�����û���Ӧ����֤��Ϣ//
			break;
		case	1022:   //P2P��֤ȷ�ϣ��������ļ������ڼ������ϢժҪ//
			break;
		case	1023:   //�ļ�����//
			receive_file_content ();
			break;
	
		default:
			break;
		}
		receive_file_content ();
	}

	void receive_file_content ()
	{
		socket_.async_receive (boost::asio::buffer (buffer_, k_buffer_size),
			boost::bind (&Session::handle_write, shared_from_this (), boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}

	void handle_write (const Error& error, size_t bytes_transferred)
	{
		if (error) {
			if (error != boost::asio::error::eof) return print_asio_error (error);
			Size_type filesize = file_info_.filesize;
			if (total_bytes_writen_ != filesize)
				std::cerr << "Filesize not matched! " << total_bytes_writen_
				<< "/" << filesize << "\n";
			return;
		}
		total_bytes_writen_ += fwrite (buffer_, 1, bytes_transferred, fp_);
		receive_file_content ();
	}

	//�����ļ�
	void send_file_content ()
	{
		
	}

	clock_t clock_;
	TCP::socket socket_;
	FILE *fp_;
	File_info file_info_;
	Size_type total_bytes_writen_;
	static const unsigned k_buffer_size = 1024 * 32;
	char buffer_[k_buffer_size];
};

class Tcp_server
{
public:
	typedef boost::asio::ip::tcp TCP;
	typedef boost::system::error_code Error;

	Tcp_server (boost::asio::io_service& io, unsigned port) :
		acceptor_ (io, TCP::endpoint (TCP::v4 (), port))
	{
		start_accept ();
	}

	static void print_asio_error (const Error& error) { std::cerr << error.message () << "\n"; }

private:
	void start_accept ()
	{
		Session::Pointer session = Session::create (acceptor_.get_io_service ());
		acceptor_.async_accept (session->socket (),
			boost::bind (&Tcp_server::handle_accept, this, session, boost::asio::placeholders::error));
	}

	void handle_accept (Session::Pointer session, const Error& error)
	{
		if (error) return print_asio_error (error);
		session->start ();
		start_accept ();
	}

	TCP::acceptor acceptor_;
};


int main ()
{
	std::cout << "Auto receive files and save then in current directory.\n";
	boost::asio::io_service io;
	Tcp_server receiver (io, 9999);

	io.run ();
}