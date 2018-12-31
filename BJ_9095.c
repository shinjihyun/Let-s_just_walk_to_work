//BACKJOON #9095
//gitub username: shinjihyun

#include <stdio.h>

int PLUS(int n);
int main() {
	int test_case;		// test_case: test case count
	int num[12];		// array num: input the value
	int result[12];		// array result : ouput the value

	scanf("%d", &test_case);	// input the test case count value

	for (int i = 0; i < test_case; i++) {
		scanf("%d", &num[i]);	// input the int number value
	}

	for (int i = 0; i < test_case; i++) {
		result[i] = PLUS(num[i]);		// call the funtion PLUS
		printf("%d\n", result[i]);		// ouput the result
	}

	return 0;
}

int PLUS(int num) {
	if (num == 1) { return 1; }
	if (num == 2) { return 2; }
	if (num == 3) { return 4; }

	return PLUS(num - 1) + PLUS(num - 2) + PLUS(num - 3);
}
