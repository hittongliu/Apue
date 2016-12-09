#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
    FILE *file;
    char line[1024];
    // 将15-14.c编译成可执行文件15-14，popen执行，并将其标准输出定向为文件file。
    file = popen("./15-14","r");
    if (file == NULL) {
        return 0;
    }
    // 文件file保存了15-14的标准输出内容。
    fputs("prompt>", stdout);
    fgets(line, sizeof(line), file);
    fputs(line, stdout);
    exit(0);
}