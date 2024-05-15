#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc ,char*argv[])
{
  int ret1 = 0,ret2 = 0,ret3 = 0,err = 0,s =0;
   int ret = 0;
   /* ret1 = fork();
    if(ret1 == 0)
    {
      err = execl("/usr/bin/gcc", "gcc", "-c","circle.c", NULL);
      if(err < 0)
      { 
        	perror("exec() failed");
			_exit(1);
      }
    }
    else
    {
      	wait(&s);
		printf("child exit status: %d\n", WEXITSTATUS(s));
    }
    printf("parent completed!\n");*/
    
    for(int i = 1;i<=4;i++)
    {
      ret = fork();
      if(ret == 0)
      {
        err = execl("/usr/bin/gcc", "gcc", "-c",argv[i], NULL);
        if(err < 0)
        {
              perror("exec() failed");
              _exit(1);
        }
      }
      else
      {
        wait(&s);
        printf("child exit status: %d\n",WEXITSTATUS(s));
      }
    }

    ret = fork();
    if(ret == 0)
    {
      err = execl("/usr/bin/gcc","gcc","-o","project.out","circle.o","square.o","rectangle.o","main.o",NULL);
      if(err < 0)
      {
         perror("exec() failed");
         _exit(1);
      }
    }
    else
    {
      wait(&s);
      printf("child exit status: %d\n",WEXITSTATUS(s));
    }
   // /home/shrikrishna/Desktop/assignment  OS/assignment_7/QUESTION 3 and 4

    ret = fork();
    if(ret == 0)
    {
      err = execl("/home/sunbeam/Desktop/EmbeddedOS/Assign_day09/day9_q4/project.out","project.out",NULL);
      if(err < 0)
      {
         perror("exec() failed");
         _exit(1);
      }
    }
    else
    {
      wait(&s);
      printf("child exit status: %d\n",WEXITSTATUS(s));
    }
  return 0;
}
