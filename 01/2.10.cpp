#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main() {
    int local_int;
    std::string local_str;
    std::cout << global_str <<'\n'<< global_int<<'\n'
     << local_int<<'\n' << local_str<<std::endl;
}
/*
`global_str` 和 `global_int` 是全局变量，所以初值分别为空字符串和 0 。
`local_int` 是局部变量并且没有初始化，它的初值是未定义的。
`local_str` 是 string 类的对象，它的值由类确定，为空字符串。 
*/