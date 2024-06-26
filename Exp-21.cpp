#include <stdio.h>
#include <limits.h>
#define MAX_KEYS 5
float sum(float freq[], int start, int end)
{
    float s = 0;
    for (int i = start; i <= end; i++)
	{
        s += freq[i];
    }
    return s;
}
int main()
{
    float keys[MAX_KEYS] = {10, 12, 16, 21, 25};
    float freq[MAX_KEYS] = {4, 2, 6, 3, 1};
    int n = MAX_KEYS;
    float cost[MAX_KEYS][MAX_KEYS];
    for (int i = 0; i < n; i++)
	{
        cost[i][i] = freq[i];
    }
    for (int len = 2; len <= n; len++)
	{  
        for (int i = 0; i <= n - len; i++)
		{
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++)
			{
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sum(freq, i, j);
                if (c < cost[i][j])
				{
                    cost[i][j] = c;
                }
            }
        }
    }
    printf("The minimum cost of optimal BST is %.2f\n", cost[0][n - 1]);
}
