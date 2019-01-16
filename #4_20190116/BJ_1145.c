#include <stdio.h>

int ans = 0;
int nNums[5];

void calc();

int main()
{
	int i;
	
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &nNums[i]);
	}
	calc();
	printf("%d\n", ans);
	
	return 0;
}

void calc()
{
	int i, j;
	int cnt = 0;
	
	for(i = 1; cnt < 3; i++)
	{
		cnt = 0;
		for(j = 0; j < 5; j++)
		{
			if(i % nNums[j] == 0) cnt++;
		}
	}
	ans = --i;
}
