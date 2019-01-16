#include <stdio.h>
#include <limits.h>

int ans;
int pay[4];
int uDay[12] = {0};

void calc(int mon, int sum);

int main()
{
	int T;
	int i, j;
	
	scanf("%d", &T);
	
	for(i = 0; i < T; i++)
	{
		ans = INT_MAX;
		for(j = 0; j < 4; j++)
		{
			scanf("%d", &pay[j]);
		}
		for(j = 0; j < 12; j++)
		{
			scanf("%d", &uDay[j]);
		}
		
		calc(0, 0);
		
		printf("#%d %d\n", i + 1, ans);
	}
	
	return 0;
}

void calc(int mon, int sum)
{
	if(mon >= 12)
	{
		if(ans > sum)
		{
			ans = sum;
		}
		return;
	}
	
	if(uDay[mon] == 0)
	{
		calc(++mon, sum);
	}
	else
	{
		calc(++mon, sum + pay[0] * uDay[mon]);
		calc(++mon, sum + pay[1]);
		calc(mon + 3, sum + pay[2]);
		calc(mon + 12, sum + pay[3]);
	}
}
