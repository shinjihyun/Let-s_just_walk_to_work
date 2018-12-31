//SW Expert Academy #1206
//gitub username: shinjihyun

#include <stdio.h>

int main(void) {
	int test_case = 10;

	for (int i = 1; i <= test_case; i++) {
		int test_len;					// testcase length
		scanf("%d", &test_len);			// Input the testcase length
		int hori[1001] = { 0, };		// horizontal length(Max : 1000)
		long long sum = 0;		// Instead of int(4 byte), long long(8 byte)

		for (int i = 0; i < test_len; i++) {
			scanf("%d", &hori[i]);		// Input the horizontal length
		}
		
		for (int j = 2; j < test_len - 2; j++) {
			int left1 = hori[j - 2];
			int left2 = hori[j - 1];
			int right1 = hori[j + 1];
			int right2 = hori[j + 2];
			int min = 2e9;
			if (hori[j] - left1 <= 0 || hori[j] - left2 <= 0 || hori[j] - right1 <= 0 || hori[j] - right2 <= 0) {
				continue;
			}
			if (hori[j] - left1 < min) { min = hori[j] - left1; }
			if (hori[j] - left2 < min) { min = hori[j] - left2; }
			if (hori[j] - right1 < min) { min = hori[j] - right1; }
			if (hori[j] - right2 < min) { min = hori[j] - right2; }
			sum += min;
		}

		printf("#%d %lld\n", i, sum);		// ouput value: #test case number+" "+apartment
	}
	return 0;
}

