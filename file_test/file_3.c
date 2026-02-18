#include <stdio.h>

int main(void)
{
	FILE *fp;
	char ch;
	int i;

	fp = fopen("aaa", "r");

	while ((ch = fgetc(fp)) != EOF) {
		fputc(ch, stdout);
	}

	fclose(fp);

	return 0;
}
