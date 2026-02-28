#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *src_fp;
	FILE *dst_fp;
	int ret;
	char buf[100];

	if (argc != 3)
	{
		printf("usage : cp  source  dest\n");
		return -1;
	}

	src_fp = fopen(argv[1], "r");
	dst_fp = fopen(argv[2], "w");

	while (ret = fread(buf, 1, sizeof buf, src_fp))
		fwrite(buf, 1, ret, dst_fp);

	fclose(src_fp);
	fclose(dst_fp);

	return 0;
}
