#ifndef PROTOBUF_INTERFACE_HPP
#define PROTOBUF_INTERFACE_HPP

#include "MyDataStruct.pb.h"
#include "config.pb.h"

namespace qiuwanli{

class BufInterface
{
public:
	BufInterface ();
	~BufInterface ();

	/**
	* �����ļ���¼
	* @param conf  �����ļ�����
	* @param type  ��������
	* @param value ��Ӧ��ֵ
	*/
	void MakeConfigFile (qiuwanli::Config* conf, qiuwanli::Type type, std::string value);

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
		std::string filesize, std::string downtime, std::string downingStatus, std::string fileSha512);
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
		std::string size, std::string downtime, std::string status);

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
	void MakeUser (qiuwanli::Users* user, std::string id, std::string name, std::string ps,
		std::string uuid, std::string code, std::string type);

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
		, std::string mirchat, std::string email, std::string bri, std::string adress);

	/**
	* �û�ע����Ϣ
	* @param reg   [description]
	* @param name  �û���
	* @param ps    ����MD5
	* @param phone �ֻ�����
	* @param code  �ֻ���֤��
	*/
	void MakeUserLogin (qiuwanli::userreg* reg, std::string name, std::string ps, std::string phone, std::string code);

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
		unsigned long long time, unsigned long timelength, std::string type);

	/**
	* �����б�
	* @param friends  ���Ѷ���
	* @param friendid ����ID
	* @param name     ���ѱ�ע
	* @param status   ��������״̬
	*/
	void MakeFriendList (qiuwanli::MyFriend* friends, std::string friendid, std::string name, std::string status);

	/**
	* �ļ�Ŀ¼�����ڴ����ļ�Ŀ¼�������ļ�����ӦPath
	* @param filepath
	* @param pathname ·�����ļ�����
	* @param pathdeep ·���������
	* @param fileid   ·�����ļ���Ӧ��ID
	*/
	void BufInterface::MakePath4FileOrDir (qiuwanli::Path4FilesOrDir* filepath, std::string pathname,
		std::string pathdeep, unsigned long fileid);

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
		std::string md52, unsigned long long  creatime, unsigned long filepathid);

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
		std::string BitMap, std::string Status, unsigned long blocknum);

};

}
#endif // !PROTOBUF_INTERFACE_HPP
