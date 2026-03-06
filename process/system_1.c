#include <stdlib.h>
#include <stdio.h>

int my_system(char *cmd);

int main(void)
{
	my_system("/bin/ls");
	return 0;
}

int my_system(char *cmd)
{
	char *argv[] = {cmd, (char*)0};
	int status;
	pid_t pid;

	pid = fork();
	
	if (pid == 0)
	{
		execve(argv[0], argv, 0);
		_exit(7);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		printf("child process exit code: %d\n", WEXITSTATUS(status));
	}
	else
		status = -1;

	return 0;
}
