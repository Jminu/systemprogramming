#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void term_stat(int status)
{
	if (WIFEXITED(status) == 0)
                printf("sucess exit : %d\n", WEXITSTATUS(status));
        else
        {
                if (WIFSIGNALED(status))
                        printf("no success exit : %d CORE DUMPED\n", WTERMSIG(status));
                else
                        printf("no sucess exit : %d\n", WTERMSIG(status));
        }
}

int main()
{
	int status;

	if (fork() == 0)
		while (1);

	wait(&status);
	term_stat(status);
	
	return 0;
}
