#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fork();
	printf("after\n");
	return 0;
}
