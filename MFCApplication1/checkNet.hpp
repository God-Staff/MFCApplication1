#ifndef CHECK_NET_HPP
#define CHECK_NET_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <boost/thread.hpp>

class HeartBeatService
{
public:
	HeartBeatService (boost::asio::io_service* p_io_service, unsigned int interval) :
		p_io_service_ (p_io_service),
		interval_ (interval),  // second
		timer_ (new boost::asio::deadline_timer (*p_io_service)),
		flag_ (false)
	{}
	HeartBeatService (const HeartBeatService& other) :
		p_io_service_ (other.p_io_service_),
		interval_ (other.interval_),
		timer_ (new boost::asio::deadline_timer (*other.p_io_service_)),
		flag_ (other.flag_)
	{}
	~HeartBeatService ()
	{
		delete timer_;
	}
	// Schedule the timer for the first time
	// The timer will fire after interval_ from io_service start run
	bool start ()
	{
		timer_->expires_from_now (interval_);
		timer_->async_wait (boost::bind (&HeartBeatService::check, this, boost::asio::placeholders::error));
	}

	// 远端调用， reset flag
	void reset ()
	{
		flag_ = false;
	}
	bool getFlag ()  // For test
	{
		return flag_;
	}

private:
	void check (const boost::system::error_code& e)  // timer 定时检查, 并设置标志
	{
		if (e)
		{
			// TODO print error message
			return;
		}
		if (flag_)
		{
			//TODO notify the controller offline!
			std::cerr << "TimeOut warning! The connection is lost!";
		}
		else
		{
			timer_->expires_at (timer_->expires_at () + interval_);
			timer_->async_wait (boost::bind (&HeartBeatService::check, this, boost::asio::placeholders::error));
			flag_ = true;
		}
	}
	boost::asio::io_service* p_io_service_;
	boost::posix_time::seconds interval_; // 超时时间
	boost::asio::deadline_timer* timer_;  // not copyable, so use pointer
	bool flag_;
};

#endif //CHECK_NET_HPP
