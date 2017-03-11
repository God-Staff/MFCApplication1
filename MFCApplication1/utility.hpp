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
