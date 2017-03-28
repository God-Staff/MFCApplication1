#include <boost/unordered_set.hpp>
#include <iostream>
#include <string>

#include <boost/unordered_map.hpp>
#include <boost/unordered/unordered_map_fwd.hpp>
#include <boost/noncopyable.hpp>
#include <vector>

template<typename T>
inline void hash_combine (std::size_t& seed, const T& val)
{
	seed ^= std::hash<T> ()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template<typename T>
inline void hash_val (std::size_t& seed, const T& val)
{
	hash_val (seed, val);
}
template<typename T, typename ...Types>
inline void hash_val (std::size_t& seed, const T& val, const Types& ...args)
{
	hash_combine (seed, val);
	hash_val (seed, args...);
}
template<typename ...Types>
inline std::size_t hash_val (const Types&... args)
{
	std::size_t seed = 0;
	hash_val (seed, args...);
	return seed;
}


//用于存储下载记录的类
class downlogstruct
{
public:
	downlogstruct (const std::string  &str11, const std::string  &str22, const std::string  &str33,
		const std::string  &str44, const std::string  &str55) :
		str1 (str11), str2 (str22), str3 (str33), str4 (str44), str5 (str55) {}
	std::string  str1;
	std::string  str2;
	std::string  str3;
	std::string  str4;
	std::string  str5;
	friend class consthash;
	friend class consthash2;
};
class consthash {
public:
	size_t operator()(const downlogstruct& log)
	{
		return hash_val (log.str1,log.str2);
	}
};

boost::unordered_set< downlogstruct> map_defau;

int main ()
{
	downlogstruct  ss("qwer", "qwer", "qwer", "qwer", "qwer");
	
	map_defau.insert (ss);

	return 0;
}