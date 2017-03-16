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
	//往表中添加数据
	bool insert (const char* insertTableSql);
	bool Delete (const char* deleteTableSql);
	bool update (const char* updatasql);
	bool select (const char* selectSql);

	//callback回调函数print_result_cb的编写，其中data为sqlite3_exec中的第四个参数
	//第二个参数是栏的数目，第三个是栏的名字，第四个为查询得到的值得。
	//这两个函数输出所有查询到的结果
	//有多少列回调函数就会执行多少次。
	int print_result_cb (void* data, int n_columns, char** column_values, char** column_names);

	void print_row (int n_values, char** values);
};

#endif // !SQLITEINTERFACE_HPP



//int main ()
//{
//	string strConn = "C:/local/Sqlite3/data/mytest.db";
//	//打开一个数据库，如果改数据库不存在，则创建一个名字为databaseName的数据库文件
//	rc = sqlite3_open (strConn.c_str (), &pDB);
//
//	if (rc)
//	{
//		cout << "打开数据库 " << strConn << " 失败" << endl;
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
