#include <iostream>
#include <fstream>
#include "MyDataStruct.pb.h"
#include "config.pb.h"

/**
 * �����ļ���¼
 * @param conf  �����ļ�����
 * @param type  ��������
 * @param value ��Ӧ��ֵ
 */
void MakeConfigFile (qiuwanli::Config* conf, qiuwanli::Type type, std::string value)
{
	conf->set_type (type);
	conf->set_valuestring (value);
}

/**
 * �ļ��������صļ�¼
 * @param downingLog    �ļ����ؼ�¼����
 * @param filename      �ļ���
 * @param filesize      �ļ���С
 * @param downtime      ����ʱ��
 * @param downingStatus ����״̬
 * @param fileSha512    �ļ���Ӧ��SHA512
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
 * �ļ����ؼ�¼�ķ�װ
 * @param log      ���ؼ�¼����
 * @param filename �ļ�����
 * @param path     ����·��
 * @param size     �ļ���С
 * @param downtime ������ص�ʱ��
 * @param status   �����Ƿ����
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
 * �û�����ķ�װ
 * @param user �û�����
 * @param id   �û�ID
 * @param name �û��ǳ�
 * @param ps   �����Ӧ��MD5
 * @param uuid PC��UUID
 * @param code ��½��֤��
 * @param type ��½����
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
 * ����ʵ����֤
 * @param realuser   
 * @param id         �û�ID
 * @param realname   ��ʵ����
 * @param idcard     ���֤����
 * @param liveadress �־�ס��ַ
 * @param phone      �ֻ�����
 * @param qq         QQ����
 * @param mirchat    ΢���˺�
 * @param email      ����
 * @param bri        ����
 * @param adress     ����
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
 * �û�ע����Ϣ
 * @param reg   [description]
 * @param name  �û���
 * @param ps    ����MD5
 * @param phone �ֻ�����
 * @param code  �ֻ���֤��
 */
void MakeUserLogin (qiuwanli::userreg* reg, std::string name, std::string ps, std::string phone, std::string code)
{
	reg->set_user_name (name);
	reg->set_user_password_md5 (ps);
	reg->set_user_phone (phone);
	reg->set_reg_code (code);
}

/**
 * �ļ������¼
 * @param Shared     �����¼����
 * @param url        �������ӵ�URL
 * @param ps         �������룬Ĭ��Ϊ��
 * @param time       ���������ʱ��
 * @param timelength ����ʱ�䳤��
 * @param type       ��������
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
 * �����б�
 * @param friends  ���Ѷ���
 * @param friendid ����ID
 * @param name     ���ѱ�ע
 * @param status   ��������״̬
 */
void MakeFriendList (qiuwanli::MyFriend* friends, std::string friendid, std::string name, std::string status)
{
	friends->set_friendid (friendid);
	friends->set_name (name);
	friends->set_status (status);
}

/**
 * �ļ�Ŀ¼�����ڴ����ļ�Ŀ¼�������ļ�����ӦPath
 * @param filepath 
 * @param pathname ·�����ļ�����
 * @param pathdeep ·���������
 * @param fileid   ·�����ļ���Ӧ��ID
 */
void MakePath4FileOrDir (qiuwanli::Path4FilesOrDir* filepath, std::string pathname, 
							std::string pathdeep, unsigned long fileid)
{
	filepath->set_pathorname (pathname);
	filepath->set_pathtypes (pathdeep);
	filepath->set_fileid (fileid);
}

/**
 * �ļ���ϸ��Ϣ+��֤
 * @param Info        
 * @param filename   �ļ���
 * @param size       ��С
 * @param md51       md5_1
 * @param md52       MD5_2
 * @param creatime   �ļ�����ʱ��
 * @param filepathid ·����Ӧ��ID
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

//һ��ʼ�ȱ������ڴ棬��ʱ�����ļ��������ʱ������д�뵽����
//���ͻ��˽���ʱ���������ǽ���д����̣������´�ʹ��
//�ϵ��������ļ����ؼ�¼
/**
 * �ļ�����״̬��BitMap�洢
 * @param tmpfile   
 * @param filename ��ʱ�ļ�����
 * @param crc      ��Ӧ�ļ�CRC��֤����
 * @param BitMap   �ļ����Ӧ��λͼ��Ϣ
 * @param Status   �ļ�����״̬��0000 0000 0000 0000 ǰ��λ��������״̬��Ϣ��ʣ��12λ���������ļ��İٷֱ�
 * @param blocknum �ļ��ܿ���
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


//����config�����ļ�
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
//����˱����û���Ϣ
void ServerUserFiles ()
{
	std::fstream output ("ServerUser", std::ios::out | std::ios::trunc | std::ios::binary);
	if (!output)
		return;

	qiuwanli::ServerUser user;
	MakeUser (user.add_user(), "12345", "����", "1234", "1234", "1234", "geren");
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
//��ʼ�������ļ�//
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