#include <stdio.h>
#include <limits.h>
#define N 4  
#define INF INT_MAX
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{

    int dist[N][N] =
	{
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int memo[1 << N][N];
    for (int i = 0; i < (1 << N); i++)
	{
        for (int j = 0; j < N; j++)
		{
            memo[i][j] = INF;
        }
    }
    memo[1][0] = 0;
    for (int mask = 1; mask < (1 << N); mask++)
	{
        for (int u = 0; u < N; u++)
		{
            if (mask & (1 << u))
			{
                for (int v = 0; v < N; v++)
				{
                    if (!(mask & (1 << v)) && dist[u][v] != INF)
					{
                        memo[mask | (1 << v)][v] = min(memo[mask | (1 << v)][v], memo[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }
    int result = INF;
    for (int i = 1; i < N; i++)
	{
        if (dist[i][0] != INF)
		{
            result = min(result, memo[(1 << N) - 1][i] + dist[i][0]);
        }
    }
    printf("The minimum cost to visit all cities is: %d\n", result);
}
