#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	int ch;
	int flag = 0;
	int cnt[3] = {0, };

	while((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
			cnt[0]++;

		if (ch != '\n' && ch != ' ' && ch != '\t')
		{
			if (flag == 0)
			{
				cnt[2]++;
				flag = 1;
			}
		}
		else
			flag = 0;

		cnt[1]++;
	}

	printf("line_cnt=%d char_cnt=%d word_cnt=%d\n", cnt[0], cnt[1], cnt[2]);
	return 0;
}
