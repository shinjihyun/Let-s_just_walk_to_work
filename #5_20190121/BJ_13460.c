#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define min(x,y) ((x > y) ? y : x)

int N, M;

int ans = INT_MAX;

int red[2];
int blue[2];
int blank[2];

int move[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

//char **map;
char map[5][5] = {
{"#####"},
{"#..B#"},
{"#.#.#"},
{"#RO.#"},
{"#####"}
};

void calc(int r[], int b[], int cnt, int prev);

int main()
{
	int i, j;
	
	scanf("%d", &M);
	scanf("%d", &N);
	
	/*	동적할당 
	map = (char**)malloc(sizeof(char*) * M);
	for(i = 0; i < M; i++)
		map[i] = (char*)malloc(sizeof(char) * N);
	*/
	
	for(i = 1; i < M - 1; i++)
	{
		for(j = 1; i < N - 1; i++)
		{
			if(map[i][j] == 'R')
			{
				red[0] = i;
				red[1] = j;
			}
			else if(map[i][j] == 'B')
			{
				blue[0] = i;
				blue[1] = j;
			}
			else if(map[i][j] == 'O')
			{
				blank[0] = i;
				blank[1] = j;
			}
		}
	}
	
	calc(red, blue, 0, 0);
	
	printf("%d", ans);
	
	return 0;
}

void calc(int r[2], int b[2], int cnt, int prev)
{
	int i;
	
	if(cnt == 10)
	{
		ans = -1;
		return;
	}
	
	for(i = 0; i < 4; i++)
	{
		int prio = 0;	// 0 빨간공 1 파란공 
		// 0 상 1 하 2 좌 3 우
		if(prev == 0 && i == 1) continue;
		else if(prev == 1 && i == 0) continue;
		else if(prev == 2 && i == 3) continue;
		else if(prev == 3 && i == 2) continue;
		
		if(i == 0)
		{
			if(r[0] > b[0]) prio = 1;
		}
		else if(i == 1)
		{
			if(r[0] < b[0]) prio = 1;
		}
		else if(i == 2)
		{
			if(r[1] > b[1]) prio = 1;
		}
		else if(i == 3)
		{
			if(r[1] < b[1]) prio = 1;
		}
		
		if(prio)	// 파란공 먼저
		{
			while(map[ b[0] + move[i][0] ][ b[1] + move[i][1] ] == '.')
			{
				if(map[ b[0] + move[i][0] ][ b[1] + move[i][1] ] != 'O')
				{
					ans = -1;
					return;
				}
				b[0] += move[i][0];
				b[1] += move[i][1];
			}
			while(map[ r[0] + move[i][0] ][ r[1] + move[i][1] ] == '.')
			{
				if(map[ r[0] + move[i][0] ][ r[1] + move[i][1] ] != 'O')
				{
					ans = min(ans, ++cnt);
					return;
				}
				r[0] += move[i][0];
				r[1] += move[i][1];
			}
		}
		else		// 빨간공 먼저
		{
			while(map[ r[0] + move[i][0] ][ r[1] + move[i][1] ] == '.')
			{
				r[0] += move[i][0];
				r[1] += move[i][1];
			}
			while(map[ b[0] + move[i][0] ][ b[1] + move[i][1] ] == '.')
			{
				if(map[ b[0] + move[i][0] ][ b[1] + move[i][1] ] != 'O')
				{
					ans = -1;
					return;
				}
				b[0] += move[i][0];
				b[1] += move[i][1];
			}
			if(map[ r[0] + move[i][0] ][ r[1] + move[i][1] ] != 'O')
			{
				ans = min(ans, ++cnt);
				return; 
			}
		}
		calc(r, b, ++cnt, i);
	}
}
