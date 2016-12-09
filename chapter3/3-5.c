#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFERSIZE 4096
int main(int argc, char *argv[])
{
    int n;
    char buf[BUFFERSIZE];
    while ((n = read(0, buf, BUFFERSIZE)) > 0) {
        printf("%s\n", buf);
        if (write(1, buf, n) != n) {
            printf("wrong!\n");
        }
    }
    exit(0);
}