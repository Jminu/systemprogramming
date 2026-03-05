#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void my_sig(int signo)
{
	int status;

	while (waitpid(-1, &status, WNOHANG) > 0) 
	{
		printf("exit code = %d\n", WEXITSTATUS(status));
	}
}



int main(void)
{
	int i;
	pid_t pid;
	
	signal(SIGCHLD, my_sig);
	
	pid = fork();
	if (pid == 0)
	{
		for (i = 0; i < 3; i++)
		{
			printf("\t\t\tchild\n");
			sleep(1);
		}
		exit(7);
	}

	while (1)
	{
		printf("parent\n");
		sleep(1);
	}

	return 0;
}
