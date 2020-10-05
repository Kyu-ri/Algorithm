#include<stdio.h>
#include <limits.h>

#define n 5
#define INF 10000

void path(int D[][n])
{

	printf("\tP[i][j] ");

	for (int i = 0; i < n; i++)
		printf("[%d]    ", i);

	printf("\n       \n");

	for (int i = 0; i < n; i++)
	{
		printf("\t[%d]", i);
		for (int j = 0; j < n; j++)
		{
			if (D[i][j] == INF)
				printf("%7s", "INF");
			else
				printf("%7d", D[i][j]);
		}
		printf("\n");
	}
}

void floyd(int W[][n])
{
	int D[n][n], i, j, k;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			D[i][j] = W[i][j];


	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
					D[i][j] = D[i][k] + D[k][j];
			}
		}
	}

	path(D);
}

int main() {

	int W[n][n] = {
	{ 0, 1, INF, 1, 5 },
	{ 9, 0, 3, 2, INF },
	{ INF, INF, 0, 4, INF },
	{ INF, INF, 2, 0, 3 },
	{ 3, INF, INF, INF, 0 },
	};

	floyd(W);

	return 0;

}