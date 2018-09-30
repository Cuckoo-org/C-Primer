#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[12] = "hello";
    char str2[12] = "world";
    char str3[12];
    int len;

    // 复制str1 到 str3
    strcpy(str3, str1);
    printf("strcpy(str3, str1) : %s\n", str3);

    // 连接 str1 和 str2
    strcat(str1, str2);
    printf("strcat(str1, str2) : %s\n",str1);

    // 连接后， str1 的总长度
    len = strlen(str1);
    printf("strlen(str1) : %d\n",len);
    len = strcmp(str1, str2);
    printf("strlen(str1) : %d\n",len); // 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
    len = strchr(str1, "l");
    printf("strlen(str1) : %d\n",len); // 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
    len = strstr(str1, str3);
    printf("strlen(str1) : %d\n",len); // 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。

    return 0;
}