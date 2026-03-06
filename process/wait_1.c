#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	int status;

	if (fork() == 0)
		exit(7);

	wait(&status);

	if ((status & 0xff) == 0)
		printf("status=%d\n", (status>>8) & 0xff);

	return 0;
}
