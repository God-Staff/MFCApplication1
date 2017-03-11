#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP

#include <string>
#include <locale.h> 

namespace qiuwanli
{
	// 需包含locale、string头文件、使用setlocale函数。
	std::wstring StringToWstring (const std::string str)
	{// string转wstring
		unsigned len = str.size () * 2;// 预留字节数
		setlocale (LC_CTYPE, "");     //必须调用此函数
		wchar_t *p = new wchar_t[len];// 申请一段内存存放转换后的字符串
		mbstowcs (p, str.c_str (), len);// 转换
		std::wstring str1 (p);
		delete[] p;// 释放申请的内存
		return str1;
	}

	std::string WstringToString (const std::wstring str)
	{// wstring转string
		unsigned len = str.size () * 4;
		setlocale (LC_CTYPE, "");
		char *p = new char[len];
		wcstombs (p, str.c_str (), len);
		std::string str1 (p);
		delete[] p;
		return str1;
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
