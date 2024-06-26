#include <stdio.h>
#include <limits.h>
void optimalBST(int keys[], int freq[], int n)
{
    int cost[n][n];
    int sum[n][n];
    for (int i = 0; i < n; i++)
	{
        cost[i][i] = freq[i];
        sum[i][i] = freq[i];
    }
    for (int L = 2; L <= n; L++)
	{
        for (int i = 0; i <= n - L; i++)
		{
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            sum[i][j] = sum[i][j - 1] + freq[j];
            for (int r = i; r <= j; r++)
			{
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) + 
                        sum[i][j];
                if (c < cost[i][j])
				{
                    cost[i][j] = c;
                }
            }
        }
    }
    printf("The optimal cost of the binary search tree is %d\n", cost[0][n - 1]);
}
int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    optimalBST(keys, freq, n);
}
