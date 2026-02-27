#include <stdio.h>
#include <unistd.h>

int main(void) {
	fprintf(stdout, "hello");
	sleep(3);

	return 0;
}
