#include <Windows.h>
#include <iostream>
#include <boost/filesystem.hpp>

#include "Utilitys/MD5.hpp"

/**
* ����ļ��ľ���·��������Ϊ�ı���ʽ(ZH_CN��������)
* �����ļ���MD5���ļ���С
* @param 	p 		�ļ�·��
* @param	file 	�ļ�ָ��
*/
_declspec(dllexport) void pathAll (boost::filesystem::path p, boost::filesystem::ofstream & file)
{
	char buffer[128];
	//try �����ʵ��޷����ʵ�Ŀ¼ʱ������//
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

	catch (const boost::filesystem::filesystem_error& ex)
	{
		std::cout << ex.what () << '\n';
	}
}

/**
 * @brief      ��������
 *
 * @param[in]  <unnamed>  { parameter_description }
 */
_declspec(dllexport) int mainl (int argc, char* argv[])
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

