#ifndef MEMORYEDITING_H_INCLUDED
#define MEMORYEDITING_H_INCLUDED

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

class DLL_EXPORT memoryEditing
{
    public:
        memoryEditing();
        ~memoryEditing();

        void    setProcessName(string name);
        void    setValueAddress(int address);
        string  getProcessName();
        int     getValueAddress();

        int     write(int value);
        int     read();

    private:
        string processName;
        int valueAddress;

        HANDLE hProcess;
        PROCESSENTRY32 entry;
        HANDLE snapshot;
};

#ifdef __cplusplus
}
#endif

#endif // MEMORYEDITING_H_INCLUDED
