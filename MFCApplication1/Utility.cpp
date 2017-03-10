#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost;

#include "Utilitys/MD5.hpp"
#include "datadefine.h"

/**
* ����ļ��ľ���·��������Ϊ�ı���ʽ(ZH_CN��������)
* �����ļ���MD5���ļ���С
* @param 	p 		�ļ�·��
* @param	file 	�ļ�ָ��
*/
void pathAll (filesystem::path p, filesystem::ofstream & file)
{
	//try �����ʵ��޷����ʵ�Ŀ¼ʱ������//
	try
	{
		if (exists (p))
		{
			if (is_regular_file (p))
				std::cout << p << " size is " << filesystem::file_size (p) << '\n';

			else if (is_directory (p))
			{
				std::cout << p << " is a directory containing:\n";

				for (filesystem::directory_entry& x : filesystem::directory_iterator (p))
				{
					if (!is_regular_file (x))
					{
						file << std::endl << "DIR:" << x.path ().generic() << std::endl;
						pathAll (x, file);
					}
					else
					{
						std::cout << "    " << x.path () << '\n';
						//��ȡ�ļ�·�������ļ���Size��MD5ֵ�����������������
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

	catch (const filesystem::filesystem_error& ex)
	{
		std::cout << ex.what () << '\n';
	}
}

//dir
int main (int argc, char* argv[])
{
	if (argc < 1)
	{
		std::cout << "Usage: tut3 path\n";
		return 1;
	}

	filesystem::path p (argv[1]);
	try
	{
		if (exists (p))
		{
			if (is_regular_file (p))
				std::cout << p << " size is " << filesystem::file_size (p) << '\n';

			else if (is_directory (p))
			{
				std::cout << p << " is a directory containing:\n";
				filesystem::path p (R"(d:\)");
				filesystem::ofstream f ("www1.txt");
				pathAll (p, f);
			}
			else
				std::cout << p << " exists, but is not a regular file or directory\n";
		}
		else
			std::cout << p << " does not exist\n";
	}

	catch (const filesystem::filesystem_error& ex)
	{
		std::cout << ex.what () << '\n';
	}

	return 0;
}
