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

void kruskal() {

	int min, i, j, n, a, b, tmp, tmp2, cycle, sum;
	int v[MAX];

	n = MAX;
	sum = 0;

	printf("result of kruskal algorism : ");

	for (i = 0; i < n; i++)
		v[i] = 1;

	for (tmp = 0; tmp < n - 1;)
	{
		min = 999999;
		cycle = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (w[i][j] != 0 && w[i][j] != -1 && w[i][j] != 100)
				{
					if (min > w[i][j])
					{
						min = w[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			if (w[a][i] == -1 && w[i][b] == -1)
			{
				w[a][b] = -1;
				w[b][a] = -1;
			}
		}

		if (v[a] == -1 && v[b] == -1)
			for (i = 0; i < n; i++)
			{
				if (w[a][i] == -1 && w[i][b] == -1)
				{
					cycle = 1;
					break;
				}
			}

		if (cycle == 0)
		{
			printf("(%c, %c) ", alph[a], alph[b]);
			v[a] = -1;
			v[b] = -1;
			w[a][b] = -1;
			w[b][a] = -1;
			sum = sum + min;
			tmp++;
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (tmp2 = 0; tmp2 < n; tmp2++)
				{
					if (w[i][tmp2] == -1 && w[tmp2][j] == -1)
					{
						w[i][j] = -1;
						w[j][i] = -1;
					}
				}
			}
		}
	}

	printf(", Sum = %d \n", sum);
}