#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct file_info
{
	char fname[20];
	int fsize;
} INFO;

int get_fsize(FILE *fp);

int main(int argc, char **argv)
{
	if (argc < 4)
	{
		printf("Argument Error!\n");
		return -1;
	}

	char buf[1024];
	FILE *dst_fp;
	FILE *src_fp;
	INFO info;
	int ret;
	int i;

	dst_fp = fopen(argv[argc - 1], "w");

	for (i = 0; i < argc - 2; i++)
	{
		info.fsize = 6; 
		strcpy(info.fname, argv[i + 1]);
		fwrite(&info, sizeof(INFO), 1, dst_fp); //header

		src_fp = fopen(argv[i + 1], "r");
		while (ret = fread(buf, 1, sizeof buf, src_fp))
			fwrite(buf, 1, ret, dst_fp); //data
		fclose(src_fp);
	}

	fclose(dst_fp);
	return 0;
}
