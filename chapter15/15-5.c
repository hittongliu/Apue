#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int fd[2];
    pid_t pid;
    char line[1024];
    int n = 0;
    if (pipe(fd) < 0) {
        printf("pipe wrong!\n");
        exit(0);
    }
    if ((pid = fork()) < 0) {
        printf("pid fork() wrong!\n");
    }
    if (pid > 0) {
        close(fd[1]);
        printf("parent, before read\n");
        n = read(fd[0], line, 1024);
        if (n <= 0) {
            printf("read wrong!\n");
        }
        write(STDOUT_FILENO, line, n);
    } else {
        close(fd[0]);
        char *buf = "hello\n";
        sleep(2);
        write(fd[1], buf, 5);
        // write(fd[1], pid, 2);
    }
    exit(0);
}