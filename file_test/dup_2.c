#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[1024];
	
	fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 066);
	
	close(1);
	dup(fd);

	printf("hello world!\n");

	return 0;
}
