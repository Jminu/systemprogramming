#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		printf("child\n");
	else if( pid > 0 )
		printf("parent\n");
	else
		printf("error\n");

	return 0;
}
