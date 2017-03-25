#ifndef _DATADEFINE_H_
#define  _DATADEFINE_H_

#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


//枚举tab类型，便于切换
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


//枚举文件类型，便于设置图标显示
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

#endif // !_DATADEFINE_H_
