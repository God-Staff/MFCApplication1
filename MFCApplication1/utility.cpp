#include "stdafx.h"
#include "utility.hpp"

namespace qiuwanli{

	//获取主板序列号
	std::string utilty::getBios ()
	{
		char *lpszBaseBoard;
		const long MAX_COMMAND_SIZE = 10000; // 命令行输出缓冲大小     
		WCHAR szFetCmd[] = L"wmic BaseBoard get SerialNumber"; // 获取主板序列号命令行   
		const std::string strEnSearch = "SerialNumber"; // 主板序列号的前导信息  

		BOOL   bret = FALSE;
		HANDLE hReadPipe = NULL; //读取管道  
		HANDLE hWritePipe = NULL; //写入管道      
		PROCESS_INFORMATION pi;   //进程信息      
		STARTUPINFO         si;   //控制命令行窗口信息  
		SECURITY_ATTRIBUTES sa;   //安全属性  

		char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // 放置命令行结果的输出缓冲区  
		std::string          strBuffer;
		unsigned long   count = 0;
		long            ipos = 0;

		memset (&pi, 0, sizeof (pi));
		memset (&si, 0, sizeof (si));
		memset (&sa, 0, sizeof (sa));

		pi.hProcess = NULL;
		pi.hThread = NULL;
		si.cb = sizeof (STARTUPINFO);
		sa.nLength = sizeof (SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = TRUE;

		//1.0 创建管道  
		bret = CreatePipe (&hReadPipe, &hWritePipe, &sa, 0);
		if (!bret)
			goto END;

		//2.0 设置命令行窗口的信息为指定的读写管道  
		GetStartupInfo (&si);
		si.hStdError = hWritePipe;
		si.hStdOutput = hWritePipe;
		si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
		si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

		//3.0 创建获取命令行的进程  
		bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
		if (!bret)
			goto END;

		//4.0 读取返回的数据  
		WaitForSingleObject (pi.hProcess, 500/*INFINITE*/);
		bret = ReadFile (hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
		if (!bret)
			goto END;

		//5.0 查找主板序列号  
		bret = FALSE;
		strBuffer = szBuffer;
		ipos = strBuffer.find (strEnSearch);

		if (ipos < 0) // 没有找到  
			goto END;
		else
			strBuffer = strBuffer.substr (ipos + strEnSearch.length ());

		memset (szBuffer, 0x00, sizeof (szBuffer));
		strcpy_s (szBuffer, strBuffer.c_str ());

		//去掉中间的空格 \r \n  
		int j = 0;
		for (int i = 0; i < strlen(szBuffer); i++)
		{
			if (szBuffer[i] != ' ' && szBuffer[i] != '\n' && szBuffer[i] != '\r')
			{
				lpszBaseBoard[j] = szBuffer[i];
				j++;
			}
		}

		bret = TRUE;

	END:
		//关闭所有的句柄  
		CloseHandle (hWritePipe);
		CloseHandle (hReadPipe);
		CloseHandle (pi.hProcess);
		CloseHandle (pi.hThread);

		return std::move (lpszBaseBoard);
	}

	//获取CPU序列号
	std::string utilty :: getCPU ()
	{
		char *lpszCpu;
		const long MAX_COMMAND_SIZE = 10000; // 命令行输出缓冲大小     
		WCHAR szFetCmd[] = L"wmic cpu get processorid"; // 获取CPU序列号命令行    
		const std::string strEnSearch = "ProcessorId"; // CPU序列号的前导信息  

		BOOL   bret = FALSE;
		HANDLE hReadPipe = NULL; //读取管道  
		HANDLE hWritePipe = NULL; //写入管道      
		PROCESS_INFORMATION pi;   //进程信息      
		STARTUPINFO         si;   //控制命令行窗口信息  
		SECURITY_ATTRIBUTES sa;   //安全属性  

		char            szBuffer[MAX_COMMAND_SIZE + 1] = { 0 }; // 放置命令行结果的输出缓冲区  
		std::string          strBuffer;
		unsigned long   count = 0;
		long            ipos = 0;

		memset (&pi, 0, sizeof (pi));
		memset (&si, 0, sizeof (si));
		memset (&sa, 0, sizeof (sa));

		pi.hProcess = NULL;
		pi.hThread = NULL;
		si.cb = sizeof (STARTUPINFO);
		sa.nLength = sizeof (SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = TRUE;

		//1.0 创建管道  
		bret = CreatePipe (&hReadPipe, &hWritePipe, &sa, 0);
		if (!bret)
			goto END;

		//2.0 设置命令行窗口的信息为指定的读写管道  
		GetStartupInfo (&si);
		si.hStdError = hWritePipe;
		si.hStdOutput = hWritePipe;
		si.wShowWindow = SW_HIDE; //隐藏命令行窗口  
		si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;

		//3.0 创建获取命令行的进程  
		bret = CreateProcess (NULL, szFetCmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
		if (!bret)
			goto END;

		//4.0 读取返回的数据  
		WaitForSingleObject (pi.hProcess, 500/*INFINITE*/);
		bret = ReadFile (hReadPipe, szBuffer, MAX_COMMAND_SIZE, &count, 0);
		if (!bret)
			goto END;

		//5.0 查找CPU序列号  
		bret = FALSE;
		strBuffer = szBuffer;
		ipos = strBuffer.find (strEnSearch);

		if (ipos < 0) // 没有找到  
			goto END;
		 else
			strBuffer = strBuffer.substr (ipos + strEnSearch.length ());
		

		memset (szBuffer, 0x00, sizeof (szBuffer));
		strcpy_s (szBuffer, strBuffer.c_str ());

		//去掉中间的空格 \r \n  
		int j = 0;
		for (int i = 0; i < strlen(szBuffer); i++)
		{
			if (szBuffer[i] != ' ' && szBuffer[i] != '\n' && szBuffer[i] != '\r')
			{
				lpszCpu[j] = szBuffer[i];
				j++;
			}
		}

		bret = TRUE;

	END:
		//关闭所有的句柄  
		CloseHandle (hWritePipe);
		CloseHandle (hReadPipe);
		CloseHandle (pi.hProcess);
		CloseHandle (pi.hThread);

		return std::move (lpszCpu);
	}

	//生成UUID
	std::string utilty :: getUuid (std::string ip_cpu)
	{
		boost::uuids::uuid dns_namespace_uuid;

		boost::uuids::name_generator gen (dns_namespace_uuid);
		boost::uuids::uuid u = gen (getCPU()+getBios());
		std::string uuid=boost::lexical_cast<std::string>(u);

		return std::move (uuid);
	}

	//发送文件
	void utilty :: sendFile (){}
	//发送文件列表
	void utilty :: sendFiles (){}
	//发送消息
	void utilty :: sendMsg (){}
	//发送心跳连接
	void utilty::sendHeart (){}

	void utilty::sender (boost::asio::io_service &io, const char*	ip_address, unsigned	port, const char* filename, const char* msg_type)
	{
		FILE *fp;
		fopen_s (&fp, filename, "rb");
		if (fp == NULL) {
			std::cerr << "cannot open file\n";
			return;
		}

		//使用智能指针，防止程序出现异常时，fclose未被调用。
		boost::shared_ptr<FILE> file_ptr (fp, fclose);

		clock_t cost_time = clock ();

		const size_t k_buffer_size = 32 * 1024;
		char buffer[k_buffer_size];
		File_info file_info;

		char buf[32 * 1024];
		/*strcpy (buf, filename);
		strcpy (buf, "+");
		strcpy (buf, msg_type);*/
		strcat_s (buf, filename);
		strcat_s (buf, "+");
		strcat_s (buf, msg_type);
		filename = (const char*)buf;

		//MessageBox ();
		//const char* filename_msg = filename + msg_type;

		int filename_size = strlen (filename) + 1;
		size_t file_info_size = sizeof (file_info);
		size_t total_size = file_info_size + filename_size;
		if (total_size > k_buffer_size) {
			std::cerr << "File name is too long";
			return;
		}
		file_info.filename_size = filename_size;
		fseek (fp, 0, SEEK_END);
		file_info.filesize = ftell (fp);
		rewind (fp);

		memcpy (buffer, &file_info, file_info_size);								//文件信息
		memcpy (buffer + file_info_size, filename, filename_size);					//文件名/消息类型

		TCP::socket socket (io);
		socket.connect (TCP::endpoint (boost::asio::ip::address_v4::from_string (ip_address), port));

		std::cout << "Sending file : " << filename << " MsgType:" << msg_type << std::endl;
		size_t len = total_size;
		unsigned long long total_bytes_read = 0;
		while (true) {
			//先发送文件头，之后发送data
			socket.send (boost::asio::buffer (buffer, len), 0);
			if (feof (fp)) break;
			len = fread (buffer, 1, k_buffer_size, fp);
			total_bytes_read += len;
		}

		//计算时间、大小和速度//
		cost_time = clock () - cost_time;
		if (cost_time == 0) cost_time = 1;
		double speed = total_bytes_read * (CLOCKS_PER_SEC / 1024.0 / 1024.0) / cost_time;
		std::cout << "cost time: " << cost_time / (double)CLOCKS_PER_SEC << " s "
			<< "  transferred_bytes: " << total_bytes_read << " bytes\n"
			<< "speed: " << speed << " MB/s\n\n";
	}


	std::wstring utilty::StringToWstring (const std::string& str)
	{
		int size_needed = MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), NULL, 0);
		std::wstring wstrTo (size_needed, 0);
		MultiByteToWideChar (CP_UTF8, 0, &str[0], (int)str.size (), &wstrTo[0], size_needed);
		return wstrTo;
	}

	bool utilty::WCharStringToUTF8String (const std::wstring &wstr, std::string &u8str)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		u8str = conv.to_bytes (wstr);
		return true;
	}

	bool utilty::UTF8StringToWCharString (const std::string &u8str, std::wstring &wstr)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t> > conv;
		wstr = conv.from_bytes (u8str);
		return true;
	}
	std::wstring utilty::s2ws (const std::string& s)
	{
		int len;
		int slength = (int)s.length () + 1;
		len = MultiByteToWideChar (CP_ACP, 0, s.c_str (), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar (CP_ACP, 0, s.c_str (), slength, buf, len);
		std::wstring r (buf);
		delete[] buf;
		return r;
	}

	void utilty::pathAll (boost::filesystem::path p, boost::filesystem::ofstream & file)
	{
		//try 当访问到无法访问的目录时，跳过//
		try{
			if (exists (p))
			{
				if (is_regular_file (p))
					std::cout << p << " size is " << boost::filesystem::file_size (p) << '\n';
				else if (is_directory (p)){
					std::cout << p << " is a directory containing:\n";
					for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator (p)){
						if (!is_regular_file (x)){
							file << std::endl << "DIR:" << x.path ().generic() << std::endl;
							pathAll (x, file);
						} else {
							std::cout << "    " << x.path () << '\n';
							//获取文件路径，将文件的Size和MD5值计算出来并保存下来
							getFileMD5 (x.path ().string ().c_str (), buffer);
							file << "name:" << x.path ().filename () << std::endl << "Size:" << file_size (x) << "		MD5:" << buffer << std::endl;
						}
					}
				}else
					std::cout << p << " exists, but is not a regular file or directory\n";
			}else
				std::cout << p << " does not exist\n";
		}catch (const boost::filesystem::filesystem_error& ex){
			std::cout << ex.what () << '\n';
		}
	}

	//dir
	int main1 (int argc, char* argv[])
	{
		if (argc < 1){
			std::cout << "Usage: tut3 path\n";
			return 1;
		}
		qiuwanli::utilty uuu;
		boost::filesystem::path p (argv[1]);
		try	{
			if (exists (p)){
				if (is_regular_file (p))
					std::cout << p << " size is " << boost::filesystem::file_size (p) << '\n';
				else if (is_directory (p))	{
					std::cout << p << " is a directory containing:\n";
					boost::filesystem::path p (R"(d:\)");
					boost::filesystem::ofstream f ("www1.txt");
					uuu.pathAll (p, f);
				}	else
					std::cout << p << " exists, but is not a regular file or directory\n";
			}	else
				std::cout << p << " does not exist\n";
		} catch (const boost::filesystem::filesystem_error& ex) {
			std::cout << ex.what () << '\n';
		}

		return 0;
	}

	void MonitorDir (std::string files)
	{
		//char* file=&file;
		bool bIncludeSubdirectories = true;
		int		nBufferSize = 1024;
		char*	buffer = new char[nBufferSize];
		HANDLE  hDirectoryHandle = NULL;
		SYSTEMTIME st = { 0 };

		hDirectoryHandle = ::CreateFileA (
			files.c_str (),
			FILE_LIST_DIRECTORY,
			FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
			NULL,
			OPEN_EXISTING,
			FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED,
			NULL);

		if (hDirectoryHandle == INVALID_HANDLE_VALUE)
			return;

		while (1)
		{
			DWORD dwBytes = 0;

			memset (buffer, 0, nBufferSize);

			if (!::ReadDirectoryChangesW (
				hDirectoryHandle,
				buffer,
				nBufferSize,
				bIncludeSubdirectories,
				FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_ATTRIBUTES |
				FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_FILE_NAME |
				FILE_NOTIFY_CHANGE_CREATION | FILE_NOTIFY_CHANGE_SECURITY |
				FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_LAST_ACCESS,
				&dwBytes,
				NULL,
				NULL) || GetLastError () == ERROR_INVALID_HANDLE)
			{
				break;
			}

			if (!dwBytes)
			{
				printf ("Buffer overflow~~\r\n");
			}

			PFILE_NOTIFY_INFORMATION record = (PFILE_NOTIFY_INFORMATION)buffer;
			DWORD cbOffset = 0;

			do
			{
				switch (record->Action)
				{
				case FILE_ACTION_ADDED:
					printf ("FILE_ACTION_ADDED:");
					break;
				case FILE_ACTION_REMOVED:
					printf ("FILE_ACTION_REMOVED:");
					break;
				case FILE_ACTION_MODIFIED:
					printf ("FILE_ACTION_MODIFIED:");
					break;
				case FILE_ACTION_RENAMED_OLD_NAME:
					printf ("FILE_ACTION_RENAMED_OLD_NAME:");
					break;
				case FILE_ACTION_RENAMED_NEW_NAME:
					printf ("FILE_ACTION_RENAMED_NEW_NAME:");
					break;

				default:
					break;
				}

				char fileBuffer[1024]{};
				WideCharToMultiByte (CP_ACP, 0, record->FileName, record->FileNameLength, fileBuffer, record->FileNameLength, NULL, NULL);
				::GetLocalTime (&st);
				std::wcout << st.wHour << ":" << st.wMinute << ":" << st.wSecond << " 更改" << fileBuffer << std::endl;
				printf (fileBuffer);
				printf ("\r\n");

				cbOffset = record->NextEntryOffset;
				record = (PFILE_NOTIFY_INFORMATION)((LPBYTE)record + cbOffset);
			} while (cbOffset);
		}

		delete buffer;

		if (hDirectoryHandle)
			CloseHandle (hDirectoryHandle);
	}

	bool watchDirs (std::string &dirs, int  nums)
	{
		//启用不同的线程监听不同的文件夹
		for (int i = 0; i < nums; ++i)
		{
			std::thread thr (MonitorDir, &dirs[i]);
			thr.join ();
		}
		return true;
	}


}