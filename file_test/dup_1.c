#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd1, fd2;
	int ret;
	char buf[100];

	fd1 = open("aaa", O_RDONLY);
	fd2 = dup(fd1);

	ret = read(fd1, buf, 2);
	write(1, buf, ret);
	ret = read(fd2, buf, 2);
	write(1, buf, ret);

	close(fd1);
	close(fd2);
	return 0;
}
