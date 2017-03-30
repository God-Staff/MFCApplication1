#ifndef _DATADEFINE_H_
#define  _DATADEFINE_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "MyDataStruct.pb.h"
#include "utility.hpp"

//ö��tab���ͣ������л�
//enum class tabtype
//{
//	file,
//	down,
//	downlog,
//	shared,
//	setting
//};

#define		ayls_file			10000
#define		ayls_down			01000
#define		ayls_downlog		00100
#define		ayls_shared			00010
#define		ayls_setting		00001


//ö���ļ����ͣ���������ͼ����ʾ
enum class filetype
{
	pdf,
	doc,
	exe,
	zip,
	html,
	text,
	rar,
	iso,
	chm,
	mp4,
	mkv
};

enum { max_length = 1024 };

//��������ѡ�е�Item���� 
const static int max_select_item = 1000;


//���ڴ洢���ؼ�¼����
class downlogstruct
{
public:
	downlogstruct (std::string  str11, std::string  str22, std::string  str33, std::string  str44, std::string  str55) :
		str1 (str11), str2 (str22), str3 (str33), str4 (str44), str5 (str55) {}
	std::string  str1;
	std::string  str2;
	std::string  str3;
	std::string  str4;
	std::string  str5;

};

#endif // !_DATADEFINE_H_
