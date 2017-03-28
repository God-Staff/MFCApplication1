#include <iostream>
#include <windows.h>
#include <string>
#include <boost/uuid/string_generator.hpp>
#include <boost/uuid/name_generator.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <intrin.h>

int main ()
{
	int dd[4];
	__cpuid (dd, 4);
	std::cout << dd[0] << std::endl;
	std::cout << dd[1] << std::endl;
	std::cout << dd[2] << std::endl;
	std::cout << dd[3] << std::endl;

	boost::uuids::uuid dns_namespace_uuid;
	boost::uuids::name_generator gen (dns_namespace_uuid);
	boost::uuids::uuid u = gen (std::to_string (dd[0]));
	std::string uuid=boost::lexical_cast<std::string>(u);
	std::cout << uuid;
	return 0;
}
