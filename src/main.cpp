#include "../lib/calculate/lib.h"
#include "../lib/version/version.h"

#include <iostream>

int main()
{
    int ver = version();
    std::cout << "Calculate version №" << ver << std::endl;
    std::cout << ver << "+" << ver << "=" << Lib::Sum(ver, ver) << std::endl;
    std::cout << ver << "*" << ver << "=" << Lib::Mul(ver, ver) << std::endl;
    std::cout << ver << "/" << ver << "=" << Lib::Div(ver, ver) << std::endl;
    return 0;
}


