//
// client.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2016 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CLIENT__
#define CLIENT__

#include <boost/asio.hpp>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/mem_fn.hpp>
#include <iostream>
#include <list>
//#include <boost/mutex>
#include "handler_allocator.hpp"


class stats
{
public:
	stats ();
	void add (size_t bytes_written, size_t bytes_read);
	void print ();

private:
	boost::asio::detail::mutex mutex_;
	size_t total_bytes_written_;
	size_t total_bytes_read_;
};

class session
{
public:
	session (boost::asio::io_service& ios, size_t block_size, stats& s);
	~session ();

	void start (boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
	void stop ();

private:
	void handle_connect (const boost::system::error_code& err);
	void handle_read (const boost::system::error_code& err, size_t length);
	void handle_write (const boost::system::error_code& err, size_t length);
	void close_socket ();

private:
	boost::asio::io_service::strand strand_;
	boost::asio::ip::tcp::socket socket_;
	size_t block_size_;
	char* read_data_;
	size_t read_data_length_;
	char* write_data_;
	int unwritten_count_;
	size_t bytes_written_;
	size_t bytes_read_;
	stats& stats_;
	handler_allocator read_allocator_;
	handler_allocator write_allocator_;
};

class client
{
public:
	client (boost::asio::io_service& ios,
		const boost::asio::ip::tcp::resolver::iterator endpoint_iterator,
		size_t block_size, size_t session_count, int timeout);

	~client ();
	void handle_timeout ();

private:
	boost::asio::io_service& io_service_;
	boost::asio::deadline_timer stop_timer_;
	std::list<session*> sessions_;
	stats stats_;
};

#endif //CLIENT__

//
//int main (int argc, char* argv[])
//{
//	try
//	{
//		if (argc != 7)
//		{
//			std::cerr << "Usage: client <host> <port> <threads> <blocksize> ";
//			std::cerr << "<sessions> <time>\n";
//			return 1;
//		}
//
//		using namespace std; // For atoi.
//		const char* host = argv[1];
//		const char* port = argv[2];
//		int thread_count = atoi (argv[3]);
//		size_t block_size = atoi (argv[4]);
//		size_t session_count = atoi (argv[5]);
//		int timeout = atoi (argv[6]);
//
//		asio::io_service ios;
//
//		asio::ip::tcp::resolver r (ios);
//		asio::ip::tcp::resolver::iterator iter =
//			r.resolve (asio::ip::tcp::resolver::query (host, port));
//
//		client c (ios, iter, block_size, session_count, timeout);
//
//		std::list<asio::thread*> threads;
//		while (--thread_count > 0)
//		{
//			asio::thread* new_thread = new asio::thread (
//				boost::bind (&asio::io_service::run, &ios));
//			threads.push_back (new_thread);
//		}
//
//		ios.run ();
//
//		while (!threads.empty ())
//		{
//			threads.front ()->join ();
//			delete threads.front ();
//			threads.pop_front ();
//		}
//	}
//	catch (std::exception& e)
//	{
//		std::cerr << "Exception: " << e.what () << "\n";
//	}
//
//	return 0;
//}
