# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
int main()
{
  int x, fd[2];
  char buf[30],s[30];
  pipe(fd);  /*创建管道*/
  while((x=fork()) == -1); /*创建子进程失败时，循环*/
  if(x == 0)
  {
    close(fd[0]);
     sprintf(buf, "This is an example\n");
     write(fd[1],buf,30); /*把buf中字符写入管道*/
     exit(0);
   }
   else {
        close(fd[1]);
      wait(0);
      printf("hello\n");
      read(fd[0],s,30);  /*父进程读管道中字符*/
      printf("%s",s);
    }
  }