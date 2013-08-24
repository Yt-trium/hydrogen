#include "console.h"

console::console()
{

}

console::~console()
{

}

char console::askKey()
{
    char  key;
    DWORD  mode;
    DWORD  counte;
    HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );

    GetConsoleMode( hstdin, &mode );
    SetConsoleMode( hstdin, 0 );
    WaitForSingleObject( hstdin, INFINITE );
    ReadConsole( hstdin, &key, 1, &counte, NULL );
    SetConsoleMode( hstdin, mode );
    return key;
}
