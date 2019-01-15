//BACKJOON #1145
//gitub username: shinjihyun

#include <stdio.h>
#define N 5

int multiple(int num[]);

int main(void) {
	int num[N];
	int i = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	printf("%d\n", multiple(num));
}

int multiple(int num[]) {
	int i = 1;

	while (1) {
	
		int cnt = 0;

		for (int j = 0; j < 5; ++j) {
			if (i % num[j] == 0)
				cnt++;
		}
		if (cnt >= 3)
			break;
		++i;
	}

	return i;
}

