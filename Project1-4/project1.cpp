/*-----------programing 1--------------*/
#include<stdio.h>

int fib(int n) {
	if (n <= 1)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}

int main() {

	int input, result;

	printf("원하는 수를 입력하시오 : ");
	scanf_s("%d", &input);
	result = fib(input);
	printf(result);

	return 0;

}

/*-----------programing 2--------------*/
#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;

	printf("입력 : ");
	scanf("%d", &n);

	int* f = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		f[i] = i;
	}

	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
		}
	}


	free(f);


	return 0;

}

/*-----------programing 3--------------*/
#include <stdio.h>
#define n 3
void matrixmult() {

	int A[n][n] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	int B[n][n] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
	int C[n][n];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			C[i][j] = 0;

			for (int k = 1; k <= n; k++) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
			}
		}
	}
	print("결과 : %d", C[n][n]);
}

void main() {

	matrixmult();

}

/*-----------programing 4--------------*/
#include <stdio.h>
#define n 3

void exchangesort() {
	int i, j;
	int S[n];

	for (i = 1; i <= n - 1; i++) {
		for (j = i + 1; j <= n; j++) {
			if (S[j] < S[i]) {
				int temp;
				temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
	printf("결과 : %d", S[n]);
}

void main() {

	exchangesort();
}