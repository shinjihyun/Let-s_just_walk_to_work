// 미완성

//SW Expert Academy #1260 
//gitub username: shinjihyun

#include <stdio.h>
#include <string.h>


int mul_cnt = 0;	// 곱셈횟수

int main(void) {
	int **arr;
	int SubMatrix_Cnt = 0;
	int TestCase_Cnt = 0;
	//int mul_cnt = 0;	// 곱셈횟수
	int Cnt = 101;

	scanf("%d", &SubMatrix_Cnt);

	while (Cnt == 0) {

		scanf("%d", &TestCase_Cnt);
		Cnt = TestCase_Cnt;
		arr = (int**)malloc(sizeof(int*) * TestCase_Cnt);		// 2차원 배열 n을 동적할당
		for (int i = 0; i < TestCase_Cnt; i++) {
			arr[i] = (int*)malloc(sizeof(int) * TestCase_Cnt);
		}

		for (int i = 0; i < TestCase_Cnt; i++) {		// 2차원 배열 n값 입력
			for (int j = 0; j < TestCase_Cnt; j++) {
				scanf("%d", *(arr+i));
			}
		}



		Cnt--;
	}


	for (int i = 1; i < SubMatrix_Cnt; i++) {	// 곱셈횟수 출력
		printf("#%d %d\n", i, mul_cnt);
	}
	
	for (int i = 0; i < SubMatrix_Cnt; i++) {	// 동적할당 해제
		free(arr[i]);
	}
	free(arr);
}

int	sub_matrix_size(int **arr, int TestCase_Cnt) {		// 각각의 sub matrix 크기 구하기
	int **mat_size;	// 행렬의 최대 높이와 넓이
	int flag = 0;

	for (int i = 0; i < TestCase_Cnt; i++) {
		for (int j = 0; j < TestCase_Cnt; j++) {
			
			while (flag==1) {
				if (((*arr)[i] != 0) && ((*arr)[j] != 0)) {
					flag = 1;
				}
				if (((*arr)[i] != 0) || ((*arr)[j] != 0)) {
					flag = 1;
				}
				}
			}

		}
	}





}

int mul_cnt() {	// 계산횟수 구하는 함수
	//int mul_cnt;


	return mul_cnt;
}
