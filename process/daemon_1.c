#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>

int daemon_init(void)
{
	pid_t pid;
	int i;
	
	if (fork() > 0)
		exit(0);

	setsid();
	chdir("/");
	umask(0);

	for (i = 0; i < 64; i++)
		close(i);

	signal(SIGCLD, SIG_IGN);
	return (0);
}

int main(void)
{
	daemon_init();
	//printf("I'm daemon\n");
	
	syslog(1, "%s\n", "daemon");

	while (1) {}

	return 0;
}
