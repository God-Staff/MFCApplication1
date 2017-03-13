#include <iostream>
#include <windows.h>
#include<ShlObj.h>
#include <string>
int main()
{
	PROCESS_INFORMATION ProcessInfo;
	STARTUPINFO StartupInfo; //This is an [in] parameter 
	ZeroMemory (&StartupInfo, sizeof (StartupInfo));
	StartupInfo.cb = sizeof (StartupInfo); //Only compulsory field 
	if (CreateProcess (NULL , "sendfile.exe 127.0.0.1 9999 fdf.txt", NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo))
	{
		WaitForSingleObject (ProcessInfo.hProcess, INFINITE);
		CloseHandle (ProcessInfo.hThread);
		CloseHandle (ProcessInfo.hProcess);
	}
	else
	{
		std::cout << "ERROE"<<std::endl;
	}
}
