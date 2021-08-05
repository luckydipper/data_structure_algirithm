#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <ctime>


int _tmain(int argc, TCHAR* argv[])
{
    STARTUPINFO startup_info = { 0, };
    PROCESS_INFORMATION process_info;
    HANDLE windows_exe_handler = GetCurrentProcess();
    startup_info.cb = sizeof(startup_info);
    TCHAR command[] = _T("Operation2.exe");
    bool file_is_open = CreateProcess(
        NULL, command, NULL, NULL,
        TRUE, 0, NULL, NULL,
        &startup_info, &process_info
    );
    if (!file_is_open)
    {
        printf("exe not open.");
        return 0;
    }

    DWORD timing{ 0 };
    while (true)
    {
        //waiting, sleep -> block 상태로 감.
        time_t start_time = time(NULL);

        for (int i = 0; i < 100000; i++)
            for (int k = 0; k < 10000; k++);
        _fputts(_T("Operation1.exe \n"), stdout);
        
        time_t end_time = time(NULL);
        printf("%u is interval time\n", end_time - start_time);

        printf("%d \n", GetCurrentProcessId());
        timing++;
        if (timing == 5)
        {
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
        }
        printf("----------------\n");
    }

    // handle table에서 자식 process와 연결을 끊어.
    // 완전히 다른 process가 됨.
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);

    return 0;
};