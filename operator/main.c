// 运算符是一种告诉编译器执行特定的数学或逻辑操作的符号。C 语言内置了丰富的运算符，并提供了以下类型的运算符：
// 算术运算符
// 关系运算符
// 逻辑运算符

// 位运算符
// 赋值运算符
// 杂项运算符
#include <stdio.h>
 
main()
{
   int a = 21;
   int c ;
 
   c =  a;
   printf("Line 1 - =  运算符实例，c 的值 = %d\n", c );
 
   c +=  a;
   printf("Line 2 - += 运算符实例，c 的值 = %d\n", c );
 
   c -=  a;
   printf("Line 3 - -= 运算符实例，c 的值 = %d\n", c );
 
   c *=  a;
   printf("Line 4 - *= 运算符实例，c 的值 = %d\n", c );
 
   c /=  a;
   printf("Line 5 - /= 运算符实例，c 的值 = %d\n", c );
 
   c  = 200;
   c %=  a;
   printf("Line 6 - %= 运算符实例，c 的值 = %d\n", c );
 
   c <<=  2;
   printf("Line 7 - <<= 运算符实例，c 的值 = %d\n", c );
 
   c >>=  2;
   printf("Line 8 - >>= 运算符实例，c 的值 = %d\n", c );
 
   c &=  2;
   printf("Line 9 - &= 运算符实例，c 的值 = %d\n", c );
 
   c ^=  2;
   printf("Line 10 - ^= 运算符实例，c 的值 = %d\n", c );
 
   c |=  2;
   printf("Line 11 - |= 运算符实例，c 的值 = %d\n", c );
 
}
