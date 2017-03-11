#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP

//#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <locale.h> 

namespace qiuwanli
{
#define  _CRT_SECURE_NO_WARNINGS
	//using namespace std;
	//std::string WstringToString (const std::wstring& ws)
	//{
	//	std::string curLocale = setlocale (LC_ALL, NULL); // curLocale = "C";
	//	setlocale (LC_ALL, "chs");
	//	const wchar_t* _Source = ws.c_str ();
	//	size_t _Dsize = 2 * ws.size () + 1;
	//	char *_Dest = new char[_Dsize];
	//	memset (_Dest, 0, _Dsize);
	//	wcstombs (_Dest, _Source, _Dsize);
	//	std::string result = _Dest;
	//	delete[]_Dest;
	//	setlocale (LC_ALL, curLocale.c_str ());
	//	return result;
	//}
	//std::wstring StringToWstring (const std::string& s)
	std::wstring StringToWstring (const std::string& str)
	{
		int size_needed = MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), NULL, 0);
		std::wstring wstrTo (size_needed, 0);
		MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), &wstrTo[0], size_needed);
		return wstrTo;
	}
}	//END namespace qiuwanli


//int main ()
//{
//	std::string str = "我是SunboyL。";
//	std::wstring str1 = StringToWstring (str);// string转换为wstring
//
//	str1 = L"我是不是SunboyL。";
//	str = WstringToString (str1);// wstring转换为string
//	return 0;
//}
#endif //End MY_UTILITY_HPP


// 需包含locale、string头文件、使用setlocale函数。
//std::wstring StringToWstring (const std::string str)
//{// string转wstring
//	unsigned len = str.size () * 2;// 预留字节数
//	setlocale (LC_CTYPE, "");     //必须调用此函数
//	wchar_t *p = new wchar_t[len];// 申请一段内存存放转换后的字符串
//	mbstowcs (p, str.c_str (), len);// 转换
//	std::wstring str1 (p);
//	delete[] p;// 释放申请的内存
//	return str1;
//}

//std::string WstringToString (const std::wstring str)
//{// wstring转string
//	unsigned len = str.size () * 4;
//	setlocale (LC_CTYPE, "");
//	char *p = new char[len];
//	wcstombs (p, str.c_str (), len);
//	std::string str1 (p);
//	delete[] p;
//	return str1;
//}
