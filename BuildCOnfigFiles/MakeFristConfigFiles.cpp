#include <iostream>
#include <fstream>
#include "MyDataStruct.pb.h"
#include "config.pb.h"


void MakeConfigFile (qiuwanli::Config* conf, qiuwanli::Type type, std::string value)
{
	conf->set_type (type);
	conf->set_valuestring (value);
}
//生成config配置文件
void makesetfiles ()
{
	std::fstream output1 ("config", std::ios::out | std::ios::trunc | std::ios::binary);
	qiuwanli::ConfigFile config;
	
	MakeConfigFile (config.add_config (), qiuwanli::Type::DownFilePath, "C:\\Users\\God-S\\Downloads");
	MakeConfigFile (config.add_config (), qiuwanli::Type::FilePath, "C:\\Users\\God-S\\Favorites");
	MakeConfigFile (config.add_config (), qiuwanli::Type::FilePath, "C:\\Users\\God-S");
	MakeConfigFile (config.add_config (), qiuwanli::Type::ThreadNumDown, "3");
	MakeConfigFile (config.add_config (), qiuwanli::Type::ThreadNumUp, "2");
	MakeConfigFile (config.add_config (), qiuwanli::Type::FileUpSpeed, "200");
	MakeConfigFile (config.add_config (), qiuwanli::Type::FileDownSpeed, "300");

	if (!config.SerializeToOstream (&output1))
		std::cerr << "Failed to write Config:" << std::endl;
	output1.close ();
}

//FileDowingLog
void MakeFileDowingLog (qiuwanli::FileDowningLog* downingLog, std::string filename, 
	std::string filesize, std::string downtime, std::string downingStatus, std::string fileSha512)
{
	downingLog->set_filename (filename);
	downingLog->set_filesize (filesize);
	downingLog->set_downtime (downtime);
	downingLog->set_downingstatus (downingStatus);
	downingLog->set_filesha512 (fileSha512);
}

//对DownLog进行封装
void MakeDownlog (qiuwanli::FileDownLog *log, std::string filename, std::string path, 
						std::string size, std::string downtime, std::string status)
{
	log->set_filename (filename);
	log->set_filepath (path);
	log->set_filesize (size);
	log->set_downtime (downtime);
	log->set_status (status);
}
//FileDownLogFile
void FileDownLogFile ()
{
	std::fstream output1 ("downlog", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::FileDownLogFile downlog;
	MakeDownlog (downlog.add_filelog (), "123", "1234", "1234", "1234", "1234");
	MakeDownlog (downlog.add_filelog (), "qwer", "qwer", "qwer", "qwer", "qrwe");
	MakeDownlog (downlog.add_filelog (), "asdf", "asdf", "asdf", "asdf", "asdf");
	MakeDownlog (downlog.add_filelog (), "zxcv", "zxcv", "zxcv", "zxcv", "zxcv");

	if (!downlog.SerializeToOstream (&output1))
		std::cerr << "Failed to write FileDownLogFile:" << std::endl;
	output1.close ();
}


void MakeUser (qiuwanli::Users* user ,std::string id,std::string name, std::string ps, 
					std::string uuid , std::string code, std::string type)
{
	user->set_user_id (id);
	user->set_user_name (name);
	user->set_user_password_md5 (ps);
	user->set_user_client_uuid (uuid);
	user->set_login_code (code);
	user->set_user_type (type);
}



void ServerUserFiles ()
{
	std::fstream output ("ServerUser", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output)
		return;

	qiuwanli::ServerUser user;
	MakeUser (user.add_user, "12345", "卦卦", "1234", "1234", "1234","geren");
	MakeUser (user.add_user, "qwer", "qwer", "qwer", "qwer", "qrwe","");
	MakeUser (user.add_user, "asdf", "asdf", "asdf", "asdf", "asdf","");
	MakeUser (user.add_user, "zxcv", "zxcv", "zxcv", "zxcv", "zxcv","");

	if (!user.SerializeToOstream (&output))
		std::cerr << "Failed to write ServerUser:" << std::endl;
	output.close ();
}

//用于实名认证
void MakeRealUsers (qiuwanli::RealUsers* realuser, std::string id, std::string realname
		, std::string idcard, std::string liveadress, std::string phone, std::string qq
		, std::string mirchat, std::string email, std::string bri, std::string adress)
{
	realuser->set_user_id (id);
	realuser->set_user_name_real (realname);
	realuser->set_user_idcard (idcard);
	realuser->set_user_live_address (liveadress);
	realuser->set_user_phone (phone);
	realuser->set_user_mirchat (mirchat);
	realuser->set_user_email (email);
	realuser->set_user_bri (bri);
	realuser->set_user_address (adress);
}

//用于用户注册
void MakeUserLogin (qiuwanli::userreg* reg, std::string name, std::string ps, std::string phone, std::string code)
{
	reg->set_user_name (name);
	reg->set_user_password_md5 (ps);
	reg->set_user_phone (phone);
	reg->set_reg_code (code);
}


void MakeFileSharedLog (qiuwanli::FilesSharedLog*  Shared, std::string url, std::string ps/*=""*/, 
								 unsigned long long time, unsigned long timelength, std::string type)
{
	Shared->set_shared_url (url);
	Shared->set_shared_ps (ps);
	Shared->set_shared_time (time);
	Shared->set_shared_timelenth (timelength);
	Shared->set_shared_types (type);
}


void MakeFriendList (qiuwanli::MyFriend* friends, std::string friendid, std::string name, std::string status)
{
	friends->set_friendid (friendid);
	friends->set_name (name);
	friends->set_status (status);
}

//目录问题
void MakePath4FileOrDir (qiuwanli::Path4FilesOrDir* filepath, std::string pathname, 
							std::string pathdeep, unsigned long fileid)
{
	filepath->set_pathorname (pathname);
	filepath->set_pathtypes (pathdeep);
	filepath->set_fileid (fileid);
}

void MakeFileInfo (qiuwanli::FileInfo* Info, std::string filename, unsigned long size, std::string md51,
							std::string md52, unsigned long long  creatime, unsigned long filepathid)
{
	Info->set_fileid (filename);
	Info->set_filesize (size);
	Info->set_filemd5_1 (md51); 
	Info->set_filemd5_2 (md52);
	Info->set_filecreatedate (creatime);
	Info->set_filepathid (filepathid);
}

//一开始先保存在内存，定时（或文件下载完成时）将其写入到磁盘
//若客户端结束时，在析构是将其写入磁盘，便于下次使用
//断点续传，文件下载记录
void MakeFileTemp (qiuwanli::filetemp* tmpfile, std::string filename, std::string crc, 
						std::string BitMap, std::string Status, unsigned long blocknum)
{
	tmpfile->set_bitmap (BitMap);
	tmpfile->set_nowstatus (Status);
	tmpfile->fileinfo.set_file_id (filename);
	tmpfile->fileinfo.set_fileblock_num (blocknum);
	tmpfile->fileinfo.set_file_CRC (crc);
}

//初始化配置文件//
int main ()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	makesetfiles ();
	FileDownLogFile ();
	ServerUserFiles ();

	google::protobuf::ShutdownProtobufLibrary ();
	return 0;
}