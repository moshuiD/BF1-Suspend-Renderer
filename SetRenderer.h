#pragma once
#include <Windows.h>
class SetRenderer
{
public:
	enum State
	{
		Suspend, Unsuspend
	};
	void SetState(State state);
private:
	HANDLE gameH = (HANDLE)-1;
	template<class T>
	size_t Write(long long addr, T buffer)
	{
		if (gameH == (HANDLE)-1)
		{
			HWND windowsH = FindWindowW(nullptr, L"Battlefield™ 1");
			DWORD pid = 0;
			GetWindowThreadProcessId(windowsH, &pid);
			gameH = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
			int error = GetLastError();
			char*  errorMsg= new char[30];
			sprintf_s(errorMsg,30,"发生错误\r\n%d", error);
			if (error)
			{
				MessageBoxA(nullptr, errorMsg, "error",MB_OK);
				gameH = (HANDLE)-1;
				delete[] errorMsg;
			}
		}
		size_t returnV = 0;
		WriteProcessMemory(gameH, (void*)addr, &buffer, sizeof(T), &returnV);
		return returnV;
	}
};

