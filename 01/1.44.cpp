#include <iostream>

int main()
{
    // curVal 是我们正在统计的数；我们将读入的新值存入val
    int curVal = 0, val = 0;
    // 读取第一个数，并确保确实有数据可以处理
    if (std::cin >> curVal) {
        int cnt = 1;
        while(std::cin >> val) {
            if(val == curVal) {
                ++cnt;
            } else {
                std::cout << curVal << " occurs "
                << cnt << " times" << std::endl;
                curVal = val;
                cnt = 1;
            }
        };
        std::cout << curVal << " occurs " << cnt
        << " times" << std::endl;
    };
    return 0;
}