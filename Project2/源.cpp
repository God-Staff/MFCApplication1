#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <boost/uuid/uuid_io.hpp>

using namespace boost::uuids;

int main ()
{
	nil_generator nil_gen;
	uuid id = nil_gen ();

	_asm {
	mov eax,03h
		xor ecx,ecx
		xor edx,edx
		cpuid
		mov s1,edx
		mov s2,ecx
	}

	/*std::cout << std::boolalpha << id.is_nil () << '\n';

	string_generator string_gen;
	id = string_gen ("CF77C981-F61B-7817-10FF-D916FCC3EAA4");
	std::cout << id.variant () << '\n';*/

	name_generator name_gen (id);
	std::cout << name_gen ("https://www.isharedyou.club") << '\n';

	return 0;
}