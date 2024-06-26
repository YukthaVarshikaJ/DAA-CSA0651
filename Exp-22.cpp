#include <stdio.h>
#define MAX 100
int main()
{
    int n = 5; 
    int k = 2;
    int C[MAX][MAX]; 
    for (int i = 0; i <= n; i++)
	{
        for (int j = 0; j <= i && j <= k; j++)
		{
            if (j == 0 || j == i)
			{
                C[i][j] = 1; 
            }
			else
			{
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
            }
        }
    }
    printf("C(%d, %d) = %d\n", n, k, C[n][k]);
}
