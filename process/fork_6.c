#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_sig(int signo)
{
	printf("my_sig occur!\n");
	wait(0);
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
		exit(0);
	}
	
	while (1)
	{
		printf("parent\n");
		sleep(1);
	}

	return 0;
}
