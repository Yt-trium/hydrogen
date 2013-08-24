#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <iostream>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

class DLL_EXPORT global
{
    public:
        global();
        ~global();
    private:
};

#ifdef __cplusplus
}
#endif

#endif // GLOBAL_H_INCLUDED
