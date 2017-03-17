#include "sqliteInterface.hpp"

bool sqliteInterface::createTable (const char* creatTableSql)
{
	//����һ��������ֵΪSQLITE_OKΪ�ɹ����������������Ϣ
	//������������һ��Ϊ�������ݿ��ָ�룬�ڶ���ΪSQL�����ַ���
	//����������Ϊcallback����������û���ã����ĸ�����Ϊcallback����
	//�еĵ�һ�������������Ϊ������Ϣ
	int rc = sqlite3_exec (pDB, creatTableSql, 0, 0, &errMsg);

	if (rc == SQLITE_OK)
		std::cout << "������ tblTest �ɹ�!" << std::endl;
	else
		std::cout << "����ʧ�ܣ�" << errMsg << std::endl;
	return true;
}

//�������������
bool sqliteInterface::insert (const char* insertTableSql)
{
	int id = 1;
	char name[] = "������";
	char value[500];
	//����һ������SQL�������chn,engΪ��Ҫ���������    
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
	sqlite3_bind_text (ppStmt, 1, "ok", -1, SQLITE_TRANSIENT);    //��ֵ����һ����
	sqlite3_bind_int (ppStmt, 2, 100);                            //��ֵ���ڶ�����
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
	//��ѯһ����¼
	char value[500];
	//����һ����ѯ��䣬��������Ϊ��englishΪtargetʱ�����ļ�¼
	//print_result_cbΪcallback�����������п��Եõ���ѯ�Ľ�������������
	//sprintf(value,"select * from tblTest where name='%s'", "������");
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

//callback�ص�����print_result_cb�ı�д������dataΪsqlite3_exec�еĵ��ĸ�����
//�ڶ���������������Ŀ�����������������֣����ĸ�Ϊ��ѯ�õ���ֵ�á�
//����������������в�ѯ���Ľ��
//�ж����лص������ͻ�ִ�ж��ٴΡ�
int sqliteInterface::print_result_cb (void* data, int n_columns, char** column_values, char** column_names)
{
	static int column_names_printed = 0;
	int i;
	if (!column_names_printed) //�״�ִ�н��������
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
