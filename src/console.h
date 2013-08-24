#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED

#include <iostream>
#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

class DLL_EXPORT console
{
    public:
        console();
        ~console();
        char askKey();
    private:
};

#ifdef __cplusplus
}
#endif

#endif // CONSOLE_H_INCLUDED
