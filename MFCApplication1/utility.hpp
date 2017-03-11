#ifndef MY_UTILITY_HPP
#define MY_UTILITY_HPP

#include <string>
#include <locale.h> 

namespace qiuwanli
{
	// �����locale��stringͷ�ļ���ʹ��setlocale������
	std::wstring StringToWstring (const std::string str)
	{// stringתwstring
		unsigned len = str.size () * 2;// Ԥ���ֽ���
		setlocale (LC_CTYPE, "");     //������ô˺���
		wchar_t *p = new wchar_t[len];// ����һ���ڴ���ת������ַ���
		mbstowcs (p, str.c_str (), len);// ת��
		std::wstring str1 (p);
		delete[] p;// �ͷ�������ڴ�
		return str1;
	}

	std::string WstringToString (const std::wstring str)
	{// wstringתstring
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
//	std::string str = "����SunboyL��";
//	std::wstring str1 = StringToWstring (str);// stringת��Ϊwstring
//
//	str1 = L"���ǲ���SunboyL��";
//	str = WstringToString (str1);// wstringת��Ϊstring
//	return 0;
//}
#endif //End MY_UTILITY_HPP
