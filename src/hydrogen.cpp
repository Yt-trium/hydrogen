#include "hydrogen.h"

hydrogen::hydrogen()
{

}

hydrogen::~hydrogen()
{

}

void hydrogen::about()
{
    std::cout << " ---------------- " << std::endl;
    std::cout << " - Hydrogen Lib - " << std::endl;
    std::cout << " -    Yttrium   - " << std::endl;
    std::cout << " -    GPL V2    - " << std::endl;
    std::cout << " ---------------- " << std::endl;
}

int hydrogen::testFunc()
{
    return 12345;
}
