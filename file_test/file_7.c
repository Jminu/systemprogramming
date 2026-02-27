#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fp;
	char buf[100];
	
	fp = fopen(argv[1], "r");
	
	while(fgets(buf, sizeof buf, fp))
	{
		usleep(100000);
		fputs(buf, stdout);
		fflush(stdout);
	}

	fclose(fp);
	return 0;
}
