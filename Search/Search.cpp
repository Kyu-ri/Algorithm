#include<stdio.h>
#include <stdlib.h>

int bin(int n, int k) {
	if (k == 0 || n == k) return 1;
	else
		return(bin(n - 1, k - 1) + bin(n - 1, k));
}

int bin2(int** B, int n, int k) {

	int i, j;
	B = (int**)malloc(sizeof(int*) * (n + 1));
	for (i = 0; i < n + 1; i++)
		B[i] = (int*)malloc(sizeof(int*) * (k + 1));

	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < i + 1; j++) {
			if (j == 0 || j == i) B[i][j] = 1;
			else if (i > j&& j > 0)
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
		}
	}
	return B[n][k];
}

int bin3(int n, int k) {

	int i, j;
	int staticSize = k + 1;
	int* C = (int*)malloc(sizeof(int) * staticSize);
	C[0] = 1;

	for (i = 1; i <= n; i++)
	{
		for (j = min(i, k); j > 0; j--)
			C[j] = C[j] + C[j - 1];
	}
	return C[k];
}
int main() {

	int** map = 0;
	int n, k;
	printf("입력하시오 : ");
	scanf_s("%d %d", &n, &k);

	printf("%d\n", bin(n, k));
	printf("%d\n", bin2(map, n, k));
	printf("%d\n", bin3(n, k));
	return 0;
}


