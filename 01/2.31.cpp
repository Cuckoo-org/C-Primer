#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1*2;
    // int &r4 = r1 * 2; 错误： r4 是一个普通的非常量引用
    i= 52;
    std::cout << i << '\n' << r1 << r3 << std::endl;

    return 0;
}
