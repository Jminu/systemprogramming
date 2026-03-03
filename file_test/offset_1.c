#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[100];

	fd = open("aaa", O_RDONLY);
	ret = read(fd, buf, 2);
	write(1, buf, ret);
	ret = read(fd, buf, 2);
	write(1, buf, ret);

	close(fd);
	return 0;
}
