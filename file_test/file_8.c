#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char buf[100];
	int ret;

	fp = fopen(argv[1], "r");
	while(ret = fread(buf, 1, sizeof buf, fp))
	{
		usleep(100000);
		fwrite(buf, 1, ret, stdout);
		fflush(stdout);
	}

	fclose(fp);
	return 0;
}
