#include <iostream>
#include <boost/filesystem.hpp>
#include "stdafx.h"
#include "Utilitys/MD5.hpp"
#include "datadefine.h"


/**
* 获得文件的绝对路径，保存为文本格式(ZH_CN编码待解决)
* 计算文件的MD5和文件大小
* @param 	p 		文件路径
* @param	file 	文件指针
*/
void pathAll (boost::filesystem::path p, boost::filesystem::ofstream & file)
{
	//try 当访问到无法访问的目录时，跳过//
	try
	{
		if (exists (p))
		{
			if (is_regular_file (p))
				std::cout << p << " size is " << boost::filesystem::file_size (p) << '\n';

			else if (is_directory (p))
			{
				std::cout << p << " is a directory containing:\n";

				for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator (p))
				{
					if (!is_regular_file (x))
					{
						file << std::endl << "DIR:" << x.path ().generic() << std::endl;
						pathAll (x, file);
					}
					else
					{
						std::cout << "    " << x.path () << '\n';
						//获取文件路径，将文件的Size和MD5值计算出来并保存下来
						getFileMD5 (x.path ().string ().c_str (), buffer);
						file << "name:" << x.path ().filename () << std::endl << "Size:" << file_size (x) << "		MD5:" << buffer << std::endl;
					}
				}
			}
			else
				std::cout << p << " exists, but is not a regular file or directory\n";
		}
		else
			std::cout << p << " does not exist\n";
	}

	catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what () << '\n';
	}
}

//dir
int main1 (int argc, char* argv[])
{
	if (argc < 1)
	{
		std::cout << "Usage: tut3 path\n";
		return 1;
	}

	boost::filesystem::path p (argv[1]);
	try
	{
		if (exists (p))
		{
			if (is_regular_file (p))
				std::cout << p << " size is " << boost::filesystem::file_size (p) << '\n';

			else if (is_directory (p))
			{
				std::cout << p << " is a directory containing:\n";
				boost::filesystem::path p (R"(d:\)");
				boost::filesystem::ofstream f ("www1.txt");
				pathAll (p, f);
			}
			else
				std::cout << p << " exists, but is not a regular file or directory\n";
		}
		else
			std::cout << p << " does not exist\n";
	}

	catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what () << '\n';
	}

	return 0;
}

