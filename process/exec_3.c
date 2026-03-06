#include <unistd.h>

int main()
{
	char *argv[] = {"newpgm_1", "one", "two", (char*)0};
	char *env[] = {"name=LG", "addr=seoul", (char*)0};

	execve("./newpgm_1", argv, env);
	return 0;
}
