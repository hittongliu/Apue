//test the function popen()
//ls ./ |wc -l shell 命令会输出当前文件夹的文件数目

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    FILE *p;
    char tmp[1024];
    char *cmdString = "ls |wc -l";
    p = popen(cmdString, "r");
    fgets(tmp, sizeof(tmp), p);
    printf("当前文件夹数目%s\n", tmp);
}