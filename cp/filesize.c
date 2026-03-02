#include <stdio.h>
#include <unistd.h>

int get_fsize(FILE *fp);
int main(int argc, char **argv)
{
	char buf[1024];
	int fsize;
	FILE *fp;

	fp = fopen(argv[1], "r");
	fsize = get_fsize(fp);

	fgets(buf, sizeof buf, fp);
	fputs(buf, stdout); 
	
	fclose(fp);
	printf("%s size=%d\n", argv[1], fsize);

	return 0;
}

int get_fsize(FILE *fp)
{
	int fsize;
	int fpos;

	fops = ftell(fp);
	fseek(fp, 0, SEEK_END);
	fsize = ftell(fp);
	fseek(fp, fops, SEEK_SET);

	return fsize;
}
