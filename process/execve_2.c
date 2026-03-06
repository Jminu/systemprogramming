#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"ls", (char*)0};
	
	printf("prompt> ls\n");
	execve("/bin/ls", argv, 0);
	printf("prompt> ls\n");

	return 0;
}
