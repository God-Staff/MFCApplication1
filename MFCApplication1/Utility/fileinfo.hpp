#ifndef _FILE_INFO_H_
#define _FILE_INFO_H_

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

using namespace boost::asio;
using boost::system::error_code;


struct File_info {
	typedef unsigned long long Size_type;
	Size_type filesize;
	size_t filename_size;
	File_info () : filesize (0), filename_size (0){}
};

#endif