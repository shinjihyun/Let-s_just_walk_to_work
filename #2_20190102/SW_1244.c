#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(x,y) ((x) > (y) ? (x) : (y))

int opp, ans;
char num[100];
char str[100];

void swap(char* a, char* b);
void cal(int cnt, int n);

int main()
{
	int T, i;
	
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		ans = 0;
		scanf("%s", num);
		scanf("%d", &opp);
		strcpy(str, num);
		cal(0, 0);
		printf("#%d %d\n", i, ans);
	}

	return 0;
}

void swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void cal(int cnt, int n)
{
	int i, j;
	
	if (cnt == opp)
	{
		ans = max(ans, atoi(str));
		return;
	}

	for (i = n; i < strlen(str); i++)
	{
		for (j = i + 1; j < strlen(str); j++)
		{
			if (str[i] <= str[j]) {
				swap(&str[i], &str[j]);
				cal(cnt + 1, i);
				swap(&str[i], &str[j]);
			}
		}
	}
}
