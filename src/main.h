#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <iostream>
#include "hydrogen.h"
#include "memoryEditing.h"
#include "console.h"

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#endif // __MAIN_H__
