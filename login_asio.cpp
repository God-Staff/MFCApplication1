//
//用于登陆获取用户信息 
//

#include "datadefine.h"

using asio::ip::tcp;

int main (int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			std::cerr << "Usage: blocking_tcp_echo_client <host> <port>\n";
			return 1;
		}

		asio::io_service io_service;

		tcp::socket s (io_service);
		tcp::resolver resolver (io_service);
		asio::connect (s, resolver.resolve ({ argv[1], argv[2] }));

		//send Data
		std::cout << "Enter message: ";
		char request[max_length];
		std::cin.getline (request, max_length);
		size_t request_length = std::strlen (request);
		asio::write (s, asio::buffer (request, request_length));

		//Get Data
		char reply[max_length];
		size_t reply_length = asio::read (s,
			asio::buffer (reply, request_length));
		std::cout << "Reply is: ";
		std::cout.write (reply, reply_length);
		std::cout << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what () << "\n";
	}

	return 0;
}

//启动定时器，每30s向服务器发送UUID，我在线
void  tcpHeart ()
{

}

//从服务端获取用户个人信息，进行验证
void getUser ()
{

}


