#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	execl("./newpgm", "newpgm", "one", "two", (char*)0);
	return 0;
}
