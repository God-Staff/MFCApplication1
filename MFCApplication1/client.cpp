#include "stdafx.h"

#include "client.hpp"
//
//stats::stats ()
//		: mutex_ (),
//		total_bytes_written_ (0),
//		total_bytes_read_ (0)
//	{
//	}
//
//	void stats::add (size_t bytes_written, size_t bytes_read)
//	{
//		asio::detail::mutex::scoped_lock lock (mutex_);
//		total_bytes_written_ += bytes_written;
//		total_bytes_read_ += bytes_read;
//	}
//
//	void stats::print ()
//	{
//		asio::detail::mutex::scoped_lock lock (mutex_);
//		std::cout << total_bytes_written_ << " total bytes written\n";
//		std::cout << total_bytes_read_ << " total bytes read\n";
//	}
//
//	session::session (asio::io_service& ios, size_t block_size, stats& s)
//		: strand_ (ios),
//		socket_ (ios),
//		block_size_ (block_size),
//		read_data_ (new char[block_size]),
//		read_data_length_ (0),
//		write_data_ (new char[block_size]),
//		unwritten_count_ (0),
//		bytes_written_ (0),
//		bytes_read_ (0),
//		stats_ (s)
//	{
//		for (size_t i = 0; i < block_size_; ++i)
//			write_data_[i] = static_cast<char>(i % 128);
//	}
//
//	session::~session ()
//	{
//		stats_.add (bytes_written_, bytes_read_);
//
//		delete[] read_data_;
//		delete[] write_data_;
//	}
//
//	void session::start (asio::ip::tcp::resolver::iterator endpoint_iterator)
//	{
//		asio::async_connect (socket_, endpoint_iterator,
//			strand_.wrap (boost::bind (&session::handle_connect, this,
//				asio::placeholders::error)));
//	}
//
//	void session::stop ()
//	{
//		strand_.post (boost::bind (&session::close_socket, this));
//	}
//
//	void session::handle_connect (const asio::error_code& err)
//	{
//		if (!err)
//		{
//			asio::error_code set_option_err;
//			asio::ip::tcp::no_delay no_delay (true);
//			socket_.set_option (no_delay, set_option_err);
//			if (!set_option_err)
//			{
//				++unwritten_count_;
//				async_write (
//					socket_, asio::buffer (write_data_, block_size_),
//					strand_.wrap (
//						make_custom_alloc_handler (
//							write_allocator_,
//							boost::bind (&session::handle_write, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//				socket_.async_read_some (
//					asio::buffer (read_data_, block_size_),
//					strand_.wrap (
//						make_custom_alloc_handler (
//							read_allocator_,
//							boost::bind (&session::handle_read, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//			}
//		}
//	}
//
//	void session::handle_read (const asio::error_code& err, size_t length)
//	{
//		if (!err)
//		{
//			bytes_read_ += length;
//
//			read_data_length_ = length;
//			++unwritten_count_;
//			if (unwritten_count_ == 1)
//			{
//				std::swap (read_data_, write_data_);
//				async_write (socket_, asio::buffer (write_data_, read_data_length_),
//					strand_.wrap (
//						make_custom_alloc_handler (write_allocator_,
//							boost::bind (&session::handle_write, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//				socket_.async_read_some (asio::buffer (read_data_, block_size_),
//					strand_.wrap (
//						make_custom_alloc_handler (read_allocator_,
//							boost::bind (&session::handle_read, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//			}
//		}
//	}
//
//	void session::handle_write (const asio::error_code& err, size_t length)
//	{
//		if (!err && length > 0)
//		{
//			bytes_written_ += length;
//
//			--unwritten_count_;
//			if (unwritten_count_ == 1)
//			{
//				std::swap (read_data_, write_data_);
//				async_write (socket_, asio::buffer (write_data_, read_data_length_),
//					strand_.wrap (
//						make_custom_alloc_handler (write_allocator_,
//							boost::bind (&session::handle_write, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//				socket_.async_read_some (asio::buffer (read_data_, block_size_),
//					strand_.wrap (
//						make_custom_alloc_handler (read_allocator_,
//							boost::bind (&session::handle_read, this,
//								asio::placeholders::error,
//								asio::placeholders::bytes_transferred))));
//			}
//		}
//	}
//
//	void session::close_socket ()
//	{
//		socket_.close ();
//	}
//
//
//	client::client (asio::io_service& ios,
//		const asio::ip::tcp::resolver::iterator endpoint_iterator,
//		size_t block_size, size_t session_count, int timeout)
//		: io_service_ (ios),
//		stop_timer_ (ios),
//		sessions_ (),
//		stats_ ()
//	{
//		stop_timer_.expires_from_now (boost::posix_time::seconds (timeout));
//		stop_timer_.async_wait (boost::bind (&client::handle_timeout, this));
//
//		for (size_t i = 0; i < session_count; ++i)
//		{
//			session* new_session = new session (io_service_, block_size, stats_);
//			new_session->start (endpoint_iterator);
//			sessions_.push_back (new_session);
//		}
//	}
//
//	client::~client ()
//	{
//		while (!sessions_.empty ())
//		{
//			delete sessions_.front ();
//			sessions_.pop_front ();
//		}
//
//		stats_.print ();
//	}
//
//	void client::handle_timeout ()
//	{
//		std::for_each (sessions_.begin (), sessions_.end (),
//			boost::mem_fn (&session::stop));
//	}
//