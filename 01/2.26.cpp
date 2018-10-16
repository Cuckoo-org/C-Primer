#include <iostream>

int main()
{
// const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; 
// ++sz;        // 不合法, const 对象不能被改变    
std::cout << cnt << '\n' << sz << std::endl;
return 0;
}
