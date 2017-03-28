#include <iostream>
#include <fstream>
#include "MyDataStruct.pb.h"
#include "config.pb.h"

/**
 * 配置文件记录
 * @param conf  配置文件对象
 * @param type  配置类型
 * @param value 对应的值
 */
void MakeConfigFile (qiuwanli::Config* conf, qiuwanli::Type type, std::string value)
{
	conf->set_type (type);
	conf->set_valuestring (value);
}

/**
 * 文件正在下载的记录
 * @param downingLog    文件下载记录对象
 * @param filename      文件名
 * @param filesize      文件大小
 * @param downtime      下载时间
 * @param downingStatus 下载状态
 * @param fileSha512    文件对应的SHA512
 */
void MakeFileDowingLog (qiuwanli::FileDowningLog* downingLog, std::string filename, 
	std::string filesize, std::string downtime, std::string downingStatus, std::string fileSha512)
{
	downingLog->set_filename (filename);
	downingLog->set_filesize (filesize);
	downingLog->set_downtime (downtime);
	downingLog->set_downingstatus (downingStatus);
	downingLog->set_filesha512 (fileSha512);
}

/**
 * 文件下载记录的封装
 * @param log      下载记录对像
 * @param filename 文件名称
 * @param path     下载路径
 * @param size     文件大小
 * @param downtime 完成下载的时间
 * @param status   现在是否存在
 */
void MakeDownlog (qiuwanli::FileDownLog *log, std::string filename, std::string path, 
						std::string size, std::string downtime, std::string status)
{
	log->set_filename (filename);
	log->set_filepath (path);
	log->set_filesize (size);
	log->set_downtime (downtime);
	log->set_status (status);
}

/**
 * 用户对象的封装
 * @param user 用户对象
 * @param id   用户ID
 * @param name 用户昵称
 * @param ps   密码对应的MD5
 * @param uuid PC端UUID
 * @param code 登陆验证码
 * @param type 登陆类型
 */
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

/**
 * 用于实名认证
 * @param realuser   
 * @param id         用户ID
 * @param realname   真实姓名
 * @param idcard     身份证号码
 * @param liveadress 现居住地址
 * @param phone      手机号码
 * @param qq         QQ号码
 * @param mirchat    微信账号
 * @param email      邮箱
 * @param bri        生日
 * @param adress     籍贯
 */
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

/**
 * 用户注册信息
 * @param reg   [description]
 * @param name  用户名
 * @param ps    密码MD5
 * @param phone 手机号码
 * @param code  手机验证码
 */
void MakeUserLogin (qiuwanli::userreg* reg, std::string name, std::string ps, std::string phone, std::string code)
{
	reg->set_user_name (name);
	reg->set_user_password_md5 (ps);
	reg->set_user_phone (phone);
	reg->set_reg_code (code);
}

/**
 * 文件分享记录
 * @param Shared     分享记录对象
 * @param url        分享链接的URL
 * @param ps         分享密码，默认为空
 * @param time       创建分享的时间
 * @param timelength 分享时间长度
 * @param type       分享类型
 */
void MakeFileSharedLog (qiuwanli::FilesSharedLog*  Shared, std::string url, std::string ps/*=""*/, 
								 unsigned long long time, unsigned long timelength, std::string type)
{
	Shared->set_shared_url (url);
	Shared->set_shared_ps (ps);
	Shared->set_shared_time (time);
	Shared->set_shared_timelenth (timelength);
	Shared->set_shared_types (type);
}

/**
 * 好友列表
 * @param friends  好友对象
 * @param friendid 好友ID
 * @param name     好友备注
 * @param status   好友现在状态
 */
void MakeFriendList (qiuwanli::MyFriend* friends, std::string friendid, std::string name, std::string status)
{
	friends->set_friendid (friendid);
	friends->set_name (name);
	friends->set_status (status);
}

/**
 * 文件目录，用于创建文件目录和下载文件到对应Path
 * @param filepath 
 * @param pathname 路径或文件名称
 * @param pathdeep 路径所属深度
 * @param fileid   路径或文件对应的ID
 */
void MakePath4FileOrDir (qiuwanli::Path4FilesOrDir* filepath, std::string pathname, 
							std::string pathdeep, unsigned long fileid)
{
	filepath->set_pathorname (pathname);
	filepath->set_pathtypes (pathdeep);
	filepath->set_fileid (fileid);
}

/**
 * 文件详细信息+验证
 * @param Info        
 * @param filename   文件名
 * @param size       大小
 * @param md51       md5_1
 * @param md52       MD5_2
 * @param creatime   文件创建时间
 * @param filepathid 路径对应的ID
 */
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
/**
 * 文件下载状态，BitMap存储
 * @param tmpfile   
 * @param filename 临时文件名称
 * @param crc      对应文件CRC验证序列
 * @param BitMap   文件块对应的位图信息
 * @param Status   文件下载状态，0000 0000 0000 0000 前四位代表下载状态信息，剩余12位用作下载文件的百分比
 * @param blocknum 文件总块数
 */
void MakeFileTemp (qiuwanli::filetemp* tmpfile, std::string filename, std::string crc, 
						std::string BitMap, std::string Status, unsigned long blocknum)
{
	qiuwanli::FileBlockInfo ttt;
	ttt.set_file_id (filename);
	ttt.set_fileblock_num (blocknum);
	ttt.set_file_crc (crc);
	tmpfile->set_bitmap (BitMap);
	tmpfile->set_nowstatus (Status);
	tmpfile->set_allocated_fileinfo (&ttt);

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
//服务端保存用户信息
void ServerUserFiles ()
{
	std::fstream output ("ServerUser", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output)
		return;

	qiuwanli::ServerUser user;
	MakeUser (user.add_user(), "12345", "卦卦", "1234", "1234", "1234", "geren");
	MakeUser (user.add_user(), "qwer", "qwer", "qwer", "qwer", "qrwe", "");
	MakeUser (user.add_user(), "asdf", "asdf", "asdf", "asdf", "asdf", "");
	MakeUser (user.add_user(), "zxcv", "zxcv", "zxcv", "zxcv", "zxcv", "");

	if (!user.SerializeToOstream (&output))
		std::cerr << "Failed to write ServerUser:" << std::endl;
	output.close ();
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
//
void MakeFileDowingLog ()
{
	std::fstream output1 ("downinglog", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::FileDownLogFiles downing;
	MakeFileDowingLog (downing.add_filedownlog (), "filename1", "1234", "20170203", "wateing", "sha512");
	MakeFileDowingLog (downing.add_filedownlog (), "filename12", "1234", "20170203", "wite", "sha512");
	MakeFileDowingLog (downing.add_filedownlog (), "filename13", "1234", "20170203", "downing", "sha512");
	MakeFileDowingLog (downing.add_filedownlog (), "filename14", "1234", "20170203", "wating", "sha512");
	MakeFileDowingLog (downing.add_filedownlog (), "filename15", "1234", "20170203", "wating", "sha512");

	if (!downing.SerializeToOstream (&output1))
		std::cerr << "Failed to write FileDownLogFile:" << std::endl;
	output1.close ();
}

void MakePath4FileOrDir ()
{
	std::fstream output1 ("MakePath4FileOrDir", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::AllFiles allfile;
	allfile.set_pathlist ("default");
	MakePath4FileOrDir (allfile.add_filespath (), "123a", "1234a", 1234lu);
	MakePath4FileOrDir (allfile.add_filespath (), "123b", "1234b", 1234lu);
	MakePath4FileOrDir (allfile.add_filespath (), "123c", "1234c", 1234lu);
	MakePath4FileOrDir (allfile.add_filespath (), "123d", "1234d", 1234lu);

	if (!allfile.SerializeToOstream (&output1))
		std::cerr << "Failed to write FileDownLogFile:" << std::endl;
	output1.close ();
}

void MakeFriendList ()
{
	std::fstream output1 ("FriendList", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::FriednList friends;
	MakeFriendList (friends.add_friend_ (), "123a", "1234z", "1234");
	MakeFriendList (friends.add_friend_ (), "123s", "1234x", "1234");
	MakeFriendList (friends.add_friend_ (), "123d", "1234c", "1234");
	MakeFriendList (friends.add_friend_ (), "123f", "1234v", "1234");

	if (!friends.SerializeToOstream (&output1))
		std::cerr << "Failed to write FileDownLogFile:" << std::endl;
	output1.close ();
}

void MakeFileSharedLog ()
{
	std::fstream output1 ("FileSharedLog", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output1)
		return;

	qiuwanli::FileShared fileshared;
	MakeFileSharedLog (fileshared.add_sharedlog (), "qwer", "1234", 1234, 1234, "1234");
	MakeFileSharedLog (fileshared.add_sharedlog (), "qwerasdf", "1234", 1234, 1234, "1234");
	MakeFileSharedLog (fileshared.add_sharedlog (), "qwetqweqwe", "1234", 1234, 1234, "1234");
	MakeFileSharedLog (fileshared.add_sharedlog (), "http://www.baidu.com", "1234", 1234, 1234, "1234");
	MakeFileSharedLog (fileshared.add_sharedlog (), "123", "1234", 1234, 1234, "1234");

	if (!fileshared.SerializeToOstream (&output1))
		std::cerr << "Failed to write FileDownLogFile:" << std::endl;
	output1.close ();
}
//初始化配置文件//
int main ()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	makesetfiles ();
	FileDownLogFile ();
	ServerUserFiles ();
	MakeFileDowingLog ();
	MakePath4FileOrDir ();
	MakeFriendList ();
	MakeFileSharedLog ();

	google::protobuf::ShutdownProtobufLibrary ();
	return 0;
}