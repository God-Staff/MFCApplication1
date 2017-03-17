#include <iostream>
#include <fstream>
#include "login_all.pb.h"
#include "config.pb.h"
#include <vector>

//初始化配置文件//
int main ()
{
	//ConfigSet File
	std::fstream output1 ("config", std::ios::out | std::ios::trunc | std::ios::binary);
	qiuwanli::ConfigFile ff;
	ff.Clear ();

	ff.add_config ()->set_type (qiuwanli::Type::FilePath);
	ff.add_config ()->set_value ("C:\\Users\\God-S\\Favorites");
	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

	ff.Clear ();
	ff.add_config ()->set_type (qiuwanli::Type::ThreadNumDown);
	ff.add_config ()->set_value ("2u");
	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

	ff.Clear ();
	ff.add_config ()->set_type (qiuwanli::Type::ThreadNumUp);
	ff.add_config ()->set_value ("3u");
	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

	ff.Clear ();
	ff.add_config ()->set_type (qiuwanli::Type::FileUpSpeed);
	ff.add_config ()->set_value ("100Mbps");
	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

	ff.Clear ();
	ff.add_config ()->set_type (qiuwanli::Type::FileDownSpeed);
	ff.add_config ()->set_value ("100Mbps");
	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

	ff.Clear ();
	ff.add_config ()->set_type (qiuwanli::Type::DownFilePath);
	ff.add_config ()->set_value ("C:\\Users\\God-S\\Downloads");

	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:"<< std::endl;
	}
	output1.close ();

	return 0;
}