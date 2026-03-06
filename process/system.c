#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int my_system(char *cmd)
{
	pid_t pid;
	int status;
	
	pid = fork();

	if (pid == 0)
	{
		execlp(cmd, cmd, (char*)0);
		_exit(127);
	}
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
		status = -1;

	return status;
}

int main(void)
{
	my_system("ls");
	printf("after\n");
	return 0;
}
