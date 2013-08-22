#include "memoryEditing.h"

memoryEditing::memoryEditing()
{

}

memoryEditing::~memoryEditing()
{

}

void    memoryEditing::setProcessName(string name)
{
    processName = name;
}

void    memoryEditing::setValueAddress(int address)
{
    valueAddress = address;
}

string  memoryEditing::getProcessName()
{
    return processName;
}

int     memoryEditing::getValueAddress()
{
    return valueAddress;
}

int     memoryEditing::write(int value)
{
    entry.dwSize = sizeof(PROCESSENTRY32);
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    hProcess = NULL;

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp(entry.szExeFile, processName.c_str()) == 0)
            {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                if(WriteProcessMemory (hProcess, (LPVOID)valueAddress, (LPVOID)&value, sizeof(&value), NULL) == 0)
                {
                    cout << "GetLastError : " << GetLastError() << endl;
                }
                CloseHandle(hProcess);
            }
        }
    }
    CloseHandle(snapshot);

    return 0;
}
int     memoryEditing::read()
{
    int buf;
    entry.dwSize = sizeof(PROCESSENTRY32);
    snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    hProcess = NULL;

    if (Process32First(snapshot, &entry) == TRUE)
    {
        while (Process32Next(snapshot, &entry) == TRUE)
        {
            if (stricmp(entry.szExeFile, processName.c_str()) == 0)
            {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entry.th32ProcessID);
                if(ReadProcessMemory (hProcess, (LPVOID)valueAddress, &buf,4,NULL) == 0)
                {
                    cout << "GetLastError : " << GetLastError() << endl;
                }
                CloseHandle(hProcess);
            }
        }
    }
    CloseHandle(snapshot);
    return buf;
}
