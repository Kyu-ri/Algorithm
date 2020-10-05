#include <stdio.h>

#define MAX 7
#define INF 1000

void prim();
void kruskal();

int w[MAX][MAX] = { { 0, 10, 15, 8, INF, INF, 27 },

{ 10, 0, INF, 25, INF, INF, 4 },
{ 15, INF, 0, 13, 32, 8, INF },
{ 8, 25, 13, 0, 19, 22, 10 },
{ INF, INF, 32, 19, 0, 15, INF },
{ INF, INF, 8, 22, 15, 0, 25 },
{ 27, 4, INF, 10, INF, 25, 0 } };

char alph[MAX] = { 'A', 'B', 'C', 'D', 'F', 'G', 'H' };

void main()
{

	prim();
	printf("\n");
	kruskal();

}

void prim() {

	int n, lnum;
	int d[MAX];
	int v[MAX];
	int start[MAX];
	int finish[MAX - 1];

	int i, j, min, idx, tmp, sum;
	n = MAX;
	lnum = n - 1;
	sum = 0;

	for (i = 0; i < n; i++) {
		d[i] = w[1][i];
		v[i] = -1;
	}
	d[1] = -1;
	idx = 1;
	start[0] = 1;

	for (i = 0; i < n - 1; i++) {
		min = INF;
		for (tmp = 0; tmp < n; tmp++) {
			if (d[tmp] != 0 && d[tmp] != -1 && d[tmp] != 100) {
				if (tmp == 0) min = d[tmp];
				else
					if (min > d[tmp]) {
						min = d[tmp];
					}
			}
		}

		for (j = 0; j < n; j++)
			for (tmp = 0; tmp < n; tmp++)
				if (d[j] == -1 && w[j][tmp] == min)

					start[i + 1] = j;

		for (j = 0; j < n; j++) {
			if (d[j] != -1 && min >= d[j]) {
				min = d[j];
				finish[i] = j;
				v[idx] = j;
				idx = j;
			}
		}
		sum = sum + min;
		d[idx] = -1;
		v[i] = idx;

		if (i == n - 2) break;
		for (j = 0; j < n; j++) {
			if (d[j] > w[idx][j]) {
				d[j] = w[idx][j];
				if (i + 1 != n - 1)	start[i + 1] = idx;
			}
		}

	}

	printf("result of prim algorism : ");

	for (i = 0; i < n - 1; i++) {
		printf("(%c, %c) ", alph[start[i]], alph[finish[i]]);
	} printf(" ");
	printf("Sum = %d \n", sum);
}