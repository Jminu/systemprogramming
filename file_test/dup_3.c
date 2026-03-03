#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char buf[1024];
	int ret;
	int fd;

	fd = open(argv[1], O_RDONLY);

	close(0);
	dup(fd);

	ret = read(0, buf, sizeof buf);
	write(1, buf, ret);

	close(fd);

	return 0;
}
