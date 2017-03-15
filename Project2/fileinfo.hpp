#ifndef _FILE_INFO_H_
#define _FILE_INFO_H_

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::asio;
using boost::system::error_code;

enum Msg_type
{
	file,
	msg,
	list,
	heart,
	get
};

struct File_info {
	typedef unsigned long long Size_type;
	Size_type filesize;
	size_t filename_size;
	Msg_type msg_type;
	File_info () : filesize (0), filename_size (0), msg_type (Msg_type::file) {}
};

#endif