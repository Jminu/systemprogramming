#include <stdio.h>
#include <unistd.h>

typedef struct
{
	char fname[20];
	int fsize;
} INFO;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Argument Error!\n");
		return -1;
	}

	FILE *src;
	FILE *dst;
	char buf[1024];
	INFO info;
	int ret, len;
	
	src = fopen(argv[1], "r");
	
	while (fread(&info, sizeof(INFO), 1, src))
	{
		dst = fopen(info.fname, "w");
		while (info.fsize > 0)
		{
			len = sizeof(buf) < info.fsize ? sizeof(buf) : info.fsize;
			ret = fread(buf, 1, len, src);
			fwrite(buf, 1, ret, dst);
			info.fsize -= ret;
		}
		fclose(dst);
	}

	fclose(src);
	printf("suc\n");
	return 0;
}
