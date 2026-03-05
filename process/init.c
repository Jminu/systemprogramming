#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/socket.h>
#include <string.h>

int sig_fd;
int sig_recv_fd;

void my_sig(int signo)
{
	char s = 'W';
	write(sig_fd, &s, 1);
}

int main(void)
{
	int i;
	pid_t pid;
	int fd[2];
	char ch;
	struct sigaction act;
	
	memset(&act, 0, sizeof(act));
	act.sa_handler = my_sig;
	act.sa_flags = SA_NOCLDSTOP;
	sigaction(SIGCHLD, &act, 0);
	socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
	sig_fd = fd[0];
	sig_recv_fd = fd[1];
	
	pid = fork();
	if (pid == 0)
	{
		for (i = 0; i < 3; i++)
		{
			printf("\t\t\tchild\n");
			sleep(1);
		}
		exit(7);
	}

	while (1)
	{
		read(sig_recv_fd, &ch, 1);
		
		while (waitpid(-1, 0, WNOHANG) > 0) {}
		printf("parent\n");
		sleep(1);
	}

	return 0;
}
