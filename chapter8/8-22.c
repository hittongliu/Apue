#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int system(const char *cmdstring)
{
	pid_t pid;
	int status = -1;
	if (cmdstring == NULL) {
		printf("cmdstring wrong!\n");
		status = -1;
	}
	if ((pid = fork()) < 0) {
		printf("fork() wrong!\n");
		status = -1;
	} else if (pid == 0) {
		printf("child process\n");
		if((execl("/bin/sh", "sh", "-c", cmdstring, (char *)0)) < 0) {
			printf("execl wrong!\n");
			status = -1;
		}
		_exit(127);
	}
	printf("parent process\n");
	if (waitpid(pid, &status, 0) < 0) {
		status = -1;
	}
	return status;
}
int main(int argc, char *argv[])
{
	int status;
	if ((status = system("date")) < 0)
		printf("error\n");
	if ((status = system("nosuchcommend")) < 0)
		printf("error\n");
	if ((status = system("ls")) < 0)
		printf("error\n");
	exit(0);
}