#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"ls", (char*)0};
	pid_t pid;

	printf("prompt> ls\n");

	if ((pid = fork()) == 0) // child
		execve("/bin/ls", argv, 0);

	waitpid(pid, NULL, WCONTINUED);
	printf("prompt> \n");
	
	return 0;
}
