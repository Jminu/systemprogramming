#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[1024];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		close(0);
		dup(fd);
	}

	while (ret = read(0, buf, sizeof buf))
		write(1, buf, ret);

	if (argc == 2)
	{
		close(fd);
		close(0);
	}

	return 0;
}
