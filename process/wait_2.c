#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	int status;

	if (fork() == 0)
		while (1);

	wait(&status);

	if ((status & 0xff) == 0)
		printf("sucess exit : %d\n", (status>>8) & 0xff);
	else
		printf("no sucess exit : %d\n", status & 0xff);

	return 0;
}
