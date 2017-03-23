#include <iostream>
#include <fstream>
#include "login_all.pb.h"
#include "configfiles.pb.h"
#include "config.pb.h"


//生成config配置文件
void makesetfiles ()
{
	//ConfigSet File
	std::fstream output1 ("config", std::ios::out | std::ios::trunc | std::ios::binary);
	qiuwanli::ConfigFile ff;

	ff.add_config ()->set_type (qiuwanli::Type::DownFilePath);
	ff.add_config ()->set_valuestring ("C:\\Users\\God-S\\Downloads");

	ff.add_config ()->set_type (qiuwanli::Type::FilePath);
	ff.add_config ()->set_valuestring ("C:\\Users\\God-S\\Favorites");

	ff.add_config ()->set_type (qiuwanli::Type::FilePath);
	ff.add_config ()->set_valuestring ("C:\\Users\\God-S");

	ff.add_config ()->set_type (qiuwanli::Type::ThreadNumDown);
	ff.add_config ()->set_valuestring ("2");

	ff.add_config ()->set_type (qiuwanli::Type::ThreadNumUp);
	ff.add_config ()->set_valuestring ("3");

	ff.add_config ()->set_type (qiuwanli::Type::FileUpSpeed);
	ff.add_config ()->set_valuestring ("100Mbps");

	ff.add_config ()->set_type (qiuwanli::Type::FileDownSpeed);
	ff.add_config ()->set_valuestring ("10Mbps");

	if (!ff.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}
	ff.Clear ();
	output1.close ();
}

void setfiles ()
{
	std::fstream output1 ("config.ini", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::setfiles setfile;
	setfile.add_map_field ()->set_key (12);
	setfile.add_map_field ()->set_value ("123");
	if (!setfile.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}
	setfile.Clear ();
	setfile.add_map_field ()->set_key (123);
	setfile.add_map_field ()->set_value ("1233");
	if (!setfile.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}
	setfile.Clear ();

	setfile.add_map_field ()->set_key (1234);
	setfile.add_map_field ()->set_value ("12334");
	if (!setfile.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}
	setfile.Clear ();

	setfile.add_map_field ()->set_key (12345);
	setfile.add_map_field ()->set_value ("123354");
	if (!setfile.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}
	setfile.Clear ();

	setfile.add_map_field ()->set_key (123456);
	setfile.add_map_field ()->set_value ("1233456");

	if (!setfile.SerializeToOstream (&output1)) {
		std::cerr << "Failed to write Config:" << std::endl;
	}

}

//初始化配置文件//
int main ()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	makesetfiles ();
	setfiles ();

	google::protobuf::ShutdownProtobufLibrary ();
	return 0;
}