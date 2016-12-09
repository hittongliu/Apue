//生成可执行文件 程序15-15.c会用到。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char c;
    c = getchar();
    // 大写转换为小写。
    if (isupper(c)) {
        c = tolower(c);
    }
    putchar(c);
    exit(0);
}