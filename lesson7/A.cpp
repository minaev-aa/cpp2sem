#include <iostream>

int main() {
    int a,b,c,d,x;
    std::cin >> a >> b >> c >> d >> x;
    if (a + x == b && c*x == d)
    {
        std::cout << "5";
    }
    else if (a + x == b )
    {
        std::cout << "4";
    }
    else if (c*x == d)
    {
        std::cout << "4";
    }
    
    else if (x == 1024)
    {
        std::cout << "3";
    }
    else
    {
        std::cout << "2";
    }
    return 0;
}