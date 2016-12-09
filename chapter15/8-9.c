#include "15-7.h"

int main(int argc, char *argv[])
{
    pid_t pid;
    TELL_WAIT();
    if ((pid = fork()) < 0) {
        printf("fork wrong!\n");
    }
    if (pid > 0) {
        // parent wait child
        printf("before wait\n");
        WAIT_CHILD();
        printf("parent\n");
    } else {
        sleep(1);
        printf("child\n");
        TELL_PARENT();
    }
    exit(0);
}