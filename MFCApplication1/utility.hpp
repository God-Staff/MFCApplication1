#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP

//#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <locale.h> 
#include <codecvt>

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


	bool WideStringToString (const std::wstring& src, std::string &str)
	{
		std::locale sys_locale ("");

		const wchar_t* data_from = src.c_str ();
		const wchar_t* data_from_end = src.c_str () + src.size ();
		const wchar_t* data_from_next = 0;

		int wchar_size = 4;
		char* data_to = new char[(src.size () + 1) * wchar_size];
		char* data_to_end = data_to + (src.size () + 1) * wchar_size;
		char* data_to_next = 0;

		memset (data_to, 0, (src.size () + 1) * wchar_size);

		typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
		mbstate_t out_state = { 0 };
		auto result = std::use_facet<convert_facet> (sys_locale).out (
			out_state, data_from, data_from_end, data_from_next,
			data_to, data_to_end, data_to_next);
		if (result == convert_facet::ok)
		{
			str = data_to;
			delete[] data_to;
			return true;
		}
		delete[] data_to;
		return false;
	}

	bool StringToWideString (const std::string& src, std::wstring &wstr)
	{
		std::locale sys_locale ("");
		const char* data_from = src.c_str ();
		const char* data_from_end = src.c_str () + src.size ();
		const char* data_from_next = 0;

		wchar_t* data_to = new wchar_t[src.size () + 1];
		wchar_t* data_to_end = data_to + src.size () + 1;
		wchar_t* data_to_next = 0;

		wmemset (data_to, 0, src.size () + 1);

		typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
		mbstate_t in_state = { 0 };
		auto result = std::use_facet<convert_facet> (sys_locale).in (
			in_state, data_from, data_from_end, data_from_next,
			data_to, data_to_end, data_to_next);
		if (result == convert_facet::ok)
		{
			wstr = data_to;
			delete[] data_to;
			return true;
		}
		delete[] data_to;
		return false;
	}


	bool WCharStringToUTF8String (const std::wstring &wstr, std::string &u8str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		u8str = conv.to_bytes (wstr);
		return true;
	}

	bool UTF8StringToWCharString (const std::string &u8str, std::wstring &wstr)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t> > conv;
		wstr = conv.from_bytes (u8str);
		return true;
	}

}	//END namespace qiuwanli


//std::string raw_string = "���� this is string"; //GBK to UFT8 
//std::string utf8_string1 = boost::locale::conv::to_utf(raw_string,"GBK");
//std::string utf8_string2 = boost::locale::conv::between(raw_string, "UTF-8", "GBK"); // UFT8 to GBK 
//std::string gbk_string1 = boost::locale::conv::from_utf( utf8_string1, "GBK" ); 
//std::string gbk_string2 = boost::locale::conv::between(utf8_string1,"GBK","UTF-8"); //���ַ�����ʹ�� 
//std::wstring��boost::locale::conv::to_utf boost::locale::conv::between��֧��
//std::wstring utf16->utf8 boost::locale::conv::utf_to_utf()�� ����utf16 �� utf8����unicode���룬���Ժ�������utf_to_utf��

//int main ()
//{
//	std::string str = "����SunboyL��";
//	std::wstring str1 = StringToWstring (str);// stringת��Ϊwstring
//
//	str1 = L"���ǲ���SunboyL��";
//	str = WstringToString (str1);// wstringת��Ϊstring
//	return 0;
//}
#endif //End MY_UTILITY_HPP


// �����locale��stringͷ�ļ���ʹ��setlocale������
//std::wstring StringToWstring (const std::string str)
//{// stringתwstring
//	unsigned len = str.size () * 2;// Ԥ���ֽ���
//	setlocale (LC_CTYPE, "");     //������ô˺���
//	wchar_t *p = new wchar_t[len];// ����һ���ڴ���ת������ַ���
//	mbstowcs (p, str.c_str (), len);// ת��
//	std::wstring str1 (p);
//	delete[] p;// �ͷ�������ڴ�
//	return str1;
//}

//std::string WstringToString (const std::wstring str)
//{// wstringתstring
//	unsigned len = str.size () * 4;
//	setlocale (LC_CTYPE, "");
//	char *p = new char[len];
//	wcstombs (p, str.c_str (), len);
//	std::string str1 (p);
//	delete[] p;
//	return str1;
//}
