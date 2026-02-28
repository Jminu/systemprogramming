#include <stdio.h>
#include <unistd.h>

int get_width(int);

int main(int argc, char **argv)
{
	FILE *fp = fopen(argv[1], "r");
	int ch;
	int flag = 0;
	int cnt[3] = {0, };
	int width = 0;
	int w;

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
	for (int i = 0; i < 3; i++)
	{
		w = get_width(cnt[i]);
		if (width < w)
			width = w;
	}

	printf("line_cnt=%*d char_cnt=%*d word_cnt=%*d\n",
			width, cnt[0], width, cnt[1], width, cnt[2]);
	fclose(fp);
	return 0;
}

int get_width(int num)
{
	int i;
	for (i = 0; num != 0; i++)
		num /= 10;

	return i;
}
