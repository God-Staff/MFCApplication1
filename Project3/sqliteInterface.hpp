#ifndef SQLITEINTERFACE_HPP
#define SQLITEINTERFACE_HPP

#include "sqlite3.h"
#include <iostream>
#include <string>

class sqliteInterface
{
private:
	sqlite3 *pDB;
	char * errMsg ;
	int rc;
public:
	sqliteInterface () :pDB (0), errMsg (0),rc(0) { }
	bool createTable (const char* creatTableSql);
	//�������������
	bool insert (const char* insertTableSql);
	bool Delete (const char* deleteTableSql);
	bool update (const char* updatasql);
	bool select (const char* selectSql);

	//callback�ص�����print_result_cb�ı�д������dataΪsqlite3_exec�еĵ��ĸ�����
	//�ڶ���������������Ŀ�����������������֣����ĸ�Ϊ��ѯ�õ���ֵ�á�
	//����������������в�ѯ���Ľ��
	//�ж����лص������ͻ�ִ�ж��ٴΡ�
	int print_result_cb (void* data, int n_columns, char** column_values, char** column_names);

	void print_row (int n_values, char** values);
};

#endif // !SQLITEINTERFACE_HPP



//int main ()
//{
//	string strConn = "C:/local/Sqlite3/data/mytest.db";
//	//��һ�����ݿ⣬��������ݿⲻ���ڣ��򴴽�һ������ΪdatabaseName�����ݿ��ļ�
//	rc = sqlite3_open (strConn.c_str (), &pDB);
//
//	if (rc)
//	{
//		cout << "�����ݿ� " << strConn << " ʧ��" << endl;
//		return 0;
//	}
//	try
//	{
//		//createTable();
//		//insert();
//		//Delete();
//		//update();
//		select ();
//
//		sqlite3_close (pDB);
//	}
//	catch (exception &ex)
//	{
//		cout << "error:" << ex.what () << endl;
//	}
//	catch (...)
//	{
//	}
//
//	return 1;
//}
