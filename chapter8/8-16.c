#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int args, char* argv[])
{
	printf("zhn loves lt forever\n");
	printf("摸摸哒😘\n");
    pid_t pid;
    if ((pid = fork() < 0)) {
        printf("wrong!\n");
    } else if (pid == 0) {
    	if (execl("/Users/liutong/Desktop/apue/8-16.sh", "param1", "param2", (char *)0) < 0) {
    		printf("execl wrong\n");
    	}
    	exit(0);
    }
    if (waitpid(pid, NULL, 0) < 0) {
    	printf("waitpid wrong\n");
    }
    exit(0);
}