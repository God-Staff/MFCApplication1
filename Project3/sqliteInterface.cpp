#include "sqliteInterface.hpp"

bool sqliteInterface::createTable (const char* creatTableSql)
{
	//插入一个表，返回值为SQLITE_OK为成功，否则输出出错信息
	//函数参数：第一个为操作数据库的指针，第二句为SQL命令字符串
	//第三个参数为callback函数，这里没有用，第四个参数为callback函数
	//中的第一个参数，第五个为出错信息
	int rc = sqlite3_exec (pDB, creatTableSql, 0, 0, &errMsg);

	if (rc == SQLITE_OK)
		std::cout << "创建表 tblTest 成功!" << std::endl;
	else
		std::cout << "建表失败：" << errMsg << std::endl;
	return true;
}

//往表中添加数据
bool sqliteInterface::insert (const char* insertTableSql)
{
	int id = 1;
	char name[] = "大气象";
	char value[500];
	//定义一条参数SQL命令，其中chn,eng为需要插入的数据    
	//sprintf (value, "insert into tblTest(id, name)values(%d, '%s')", id, name);

	rc = sqlite3_exec (pDB, value, 0, 0, &errMsg);
	return 1;
}

bool sqliteInterface::Delete (const char* deleteTableSql)
{
	sqlite3_exec (pDB, "delete from tblTest where id = 100", 0, 0, &errMsg);
	return 1;
}

bool sqliteInterface::update (const char* updatasql)
{
	char *pSql = "update tblTest set name = ? where id = ?";
	sqlite3_stmt *ppStmt;
	if (SQLITE_OK != sqlite3_prepare_v2 (pDB, pSql, strlen (pSql), &ppStmt, 0))
	{
		std::cout << "update tblTest : prepare sql error !!!" << std::endl;
		sqlite3_finalize (ppStmt);
		return 0;
	}
	sqlite3_bind_text (ppStmt, 1, "ok", -1, SQLITE_TRANSIENT);    //绑定值到第一个？
	sqlite3_bind_int (ppStmt, 2, 100);                            //绑定值到第二个？
	int ret = -1;
	while (ret != SQLITE_DONE)
	{
		ret = sqlite3_step (ppStmt);
	}
	sqlite3_reset (ppStmt);
	sqlite3_finalize (ppStmt);

	return 1;
}

bool sqliteInterface::select (const char* selectSql)
{
	//查询一条记录
	char value[500];
	//定义一条查询语句，其中条件为当english为target时的中文记录
	//print_result_cb为callback函数，在其中可以得到查询的结果，具体见下文
	//sprintf(value,"select * from tblTest where name='%s'", "大气象");
	//sprintf (value, "select * from tblTest", "hello");
	//rc = sqlite3_exec (pDB, value, print_result_cb, 0, &errMsg);

	if (rc == SQLITE_OK)
	{
		std::cout << "select the record successful!" << std::endl;
	}
	else
	{
		std::cout << errMsg << std::endl;
	}
	return 1;
}

//callback回调函数print_result_cb的编写，其中data为sqlite3_exec中的第四个参数
//第二个参数是栏的数目，第三个是栏的名字，第四个为查询得到的值得。
//这两个函数输出所有查询到的结果
//有多少列回调函数就会执行多少次。
int sqliteInterface::print_result_cb (void* data, int n_columns, char** column_values, char** column_names)
{
	static int column_names_printed = 0;
	int i;
	if (!column_names_printed) //首次执行结果是列名
	{
		print_row (n_columns, column_names);
		column_names_printed = 1;
	}

	print_row (n_columns, column_values);
	return 0;
}

void sqliteInterface::print_row (int n_values, char** values)
{
	int i;
	for (i = 0; i < n_values; ++i)
	{
		if (i > 0)
		{
			printf ("\t");
		}
		printf ("%s", values[i]);
	}
	printf ("\n");
}



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
