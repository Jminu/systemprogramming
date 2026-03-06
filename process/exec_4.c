#include <unistd.h>

int main()
{
	execlp("ls", "ls", "-l", (char*)0);
	return 0;
}
