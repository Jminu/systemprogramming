#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[1024];

	fd = open(argv[1], O_RDONLY);
	printf("fd=%d\n", fd);

	while (ret = read(fd, buf, sizeof buf))
		write(1, buf, ret);
	close(fd);

	return 0;
}
