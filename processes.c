#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>

int main(void)  {
  pid_t pid;

  /* fork a child process */
  pid = fork();

  if(0 > pid)  {
    /* error occured */
    printf("Error Occured: Fork Failed\n");
    return 1;
  }
  else if(pid == 0)  {
    /* this is a child process */
    execlp("bin/ls", "ls", NULL);
    printf("I, the child, am done\n");
  }
  else  {
    /* this is the parent process, gotta wait for child to be done */
    wait(NULL);
    printf("Child has completed\n");
  }

  return 0;
}
