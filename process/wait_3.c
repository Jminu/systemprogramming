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

	if ((status & 0x7f) == 0)
		printf("sucess exit : %d\n", (status>>8) & 0xff);
	else
	{
		if (status & 0x80)
			printf("no success exit : %d CORE DUMPED\n", status & 0xff);
		else
			printf("no sucess exit : %d\n", status & 0xff);
	}
	return 0;
}
