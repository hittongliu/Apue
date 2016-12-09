#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void set_fl(int fd, int flags)
{
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        printf("wrong!\n");
    }
    printf("val = %d\n", val);
    val |= flags;
    if ((fcntl(fd, F_SETFL, val)) < 0) {
        printf("wrong!\n");
    }
}

int main()
{
    int fd = open("/Users/liutong/Desktop/apue/chapter3/3-5.c", O_RDWR);
    set_fl(fd, O_WRONLY);
    set_fl(fd, O_APPEND);
    int n = (write (fd, "hi", 10));
    printf("%d\n", n);
}