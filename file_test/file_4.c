#include <stdio.h>

int main(void)
{
	char buff[100];

	while(fgets(buff, sizeof buff, stdin))
		fputs(buff, stdout);

	return 0;
}
