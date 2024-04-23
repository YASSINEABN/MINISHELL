#include <unistd.h>
#include <stdlib.h>
typedef struct command{
  char *str;
  char **commands;
  int infile;
  int outfile;
}t_command;

int main()
{
  int fds[2];
   char *args[] = {"ls",NULL,NULL};
    char *argss[] = {"rev",NULL,NULL};
      char *argsss[] = {"wc",NULL,NULL};
      t_command cmdd[] = {{"/bin/ls",args,1,0},{"/bin/rev",argss,0,1 },{"/bin/wc",argss,1 , 0}};
      int pid = 0 ;
      int i = 0;
      int fd = 0;
      while(i < 3)
	{
	  pipe(fds);
	  pid = fork();
	  if(pid == 0)
	    {
	     close(fds[0]);
	      dup2(fd,0);
	      if(i == 0 || i == 1)
		{
	     
		  dup2(fds[1],1);
		}
	      
	       execve(cmdd[i].str, cmdd[i].commands, NULL);
	       exit(1);
	    }
       
	  fd = fds[0];
	  
	  close(fds[1]);
	  i++;
	  
	}
      waitpid();
      waitpid();
      waitpid();
  

}
