#ifndef HYDROGEN_H_INCLUDED
#define HYDROGEN_H_INCLUDED

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

class DLL_EXPORT hydrogen
{
    public:
        hydrogen();
        ~hydrogen();
        int testFunc();
        void about();
    private:
        const char* creator = "Yttrium";
};

#ifdef __cplusplus
}
#endif

#endif // HYDROGEN_H_INCLUDED
