#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_sig(int signo)
{
	int status;
	printf("my_sig signal handler\n");

	while (waitpid(-1, &status, WNOHANG) > 0)
	{
		status = WEXITSTATUS(status);
		printf("Parent: status=%d\n", status);
	}
}

int main(void)
{
	pid_t pid;
	int i, j;
	
	signal(SIGCHLD, my_sig);

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			for (j = 0; j < i + 1; j++)
			{
				printf("\t\t\tchild\n");
				sleep(1);
			}
			exit(7);
		}
	}

	while (1)
	{
		printf("parent\n");
		sleep(1);
	}

	return 0;
}
