//www.cnblogs.com/flyinghearts
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "fileinfo.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <fstream>

class Session : public boost::enable_shared_from_this<Session>
{
public:
	typedef asio::ip::tcp TCP;
	typedef asio::error_code Error;
	typedef boost::shared_ptr<Session> Pointer;
	typedef File_info::Size_type Size_type;

	static void print_asio_error (const Error& error) { std::cerr << error.message () << "\n"; }

	static Pointer create (asio::io_service& io) { return Pointer (new Session (io)); }

	TCP::socket& socket () { return socket_; }

	~Session ()
	{
		if (fileout)
			fileout.close ();
		clock_ = clock () - clock_;
		Size_type bytes_writen = total_bytes_writen_;
		if (clock_ == 0) clock_ = 1;
		double speed = bytes_writen * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / clock_;
		std::cout << "cost time: " << clock_ / (double)CLOCKS_PER_SEC << " s  "
			<< "bytes_writen: " << bytes_writen << " bytes\n"
			<< "speed: " << speed << " MB/s\n\n";
	}

	void start ()
	{
		clock_ = clock ();
		std::cout << "client: " << socket_.remote_endpoint ().address () << "\n";
		socket_.async_receive (
			asio::buffer (reinterpret_cast<char*>(&file_info_), sizeof (file_info_)),
			boost::bind (&Session::handle_header, shared_from_this (), asio::placeholders::error));
	}

private:
	Session (asio::io_service& io) : socket_ (io),total_bytes_writen_ (0) { }

	void handle_header (const Error& error)
	{
		if (error) return print_asio_error (error);
		size_t filename_size = file_info_.filename_size;
		if (filename_size > k_buffer_size) {
			std::cerr << "Path name is too long!\n";
			return;
		}
		//����async_read, ������async_read_some����ֹ·��������ʱ��һ�ν��ղ���
		asio::async_read (socket_, asio::buffer (buffer_, file_info_.filename_size),
			boost::bind (&Session::handle_file, shared_from_this (), asio::placeholders::error));
	}

	void handle_file (const Error& error)
	{
		if (error) return print_asio_error (error);
		const char *basename = buffer_ + file_info_.filename_size - 1;
		while (basename >= buffer_ && (*basename != '\\' && *basename != '/')) --basename;
		++basename;

		std::cout << "Open file: " << basename << " (" << buffer_ << ")\n";

		fileout.open ("sdf", std::ios::binary|std::ios::app| std::ios::in | std::ios::out );
		//fp_ = fopen (basename, "wb");
		if (fileout) {
			std::cerr << "Failed to open file to write\n";
		}
		receive_file_content ();
	}

	void receive_file_content ()
	{
		socket_.async_receive (asio::buffer (buffer_, k_buffer_size),
			boost::bind (&Session::handle_write, shared_from_this (), asio::placeholders::error,
				asio::placeholders::bytes_transferred));
	}

	void handle_write (const Error& error, size_t bytes_transferred)
	{
		if (error) {
			if (error != asio::error::eof) return print_asio_error (error);
			Size_type filesize = file_info_.filesize;
			if (total_bytes_writen_ != filesize)
				std::cerr << "Filesize not matched! " << total_bytes_writen_
				<< "/" << filesize << "\n";
			return;
		}
		fileout<<buffer_;
		total_bytes_writen_ += bytes_transferred;
		//total_bytes_writen_ += fwrite (buffer_, 1, bytes_transferred, fp_);
		receive_file_content ();
	}

	clock_t clock_;
	TCP::socket socket_;
	//FILE *fp_;
	std::fstream fileout;
	File_info file_info_;
	Size_type total_bytes_writen_;
	static const unsigned k_buffer_size = 1024 * 32;
	char buffer_[k_buffer_size];
};

class Tcp_server
{
public:
	typedef asio::ip::tcp TCP;
	typedef asio::error_code Error;

	Tcp_server (asio::io_service& io, unsigned port) :
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
			boost::bind (&Tcp_server::handle_accept, this, session, asio::placeholders::error));
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
	asio::io_service io;
	Tcp_server receiver (io, 9999);
	io.run ();
}

