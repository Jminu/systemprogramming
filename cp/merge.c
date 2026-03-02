#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		printf("argument error!\n");
		return -1;
	}
	printf("open success!\n");

	char buf[1024];
	FILE *src_fp;
	FILE *dst_fp;
	int cnt = 0; 
	int ret;
	int i;

	dst_fp = fopen(argv[argc - 1], "w");

	for (i = 0; i < argc - 2; i++)
	{
		src_fp = fopen(argv[i + 1], "r");
		while (ret = fread(buf, 1, sizeof buf, src_fp))
		{
			fwrite(buf, 1, ret, dst_fp);
			cnt++;
			printf("cnt=%d\n", cnt);
		}
		fclose(src_fp);
	}
	printf("copy success!\n");

	fclose(dst_fp);
	return 0;
}
