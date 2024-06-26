#include <stdio.h>
int main()
{
    int n = 5; 
    int pascal[n][n];
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j <= i; j++)
		{
            if (j == 0 || j == i)
			{
                pascal[i][j] = 1;
            }
			else
			{
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
	{
        for (int k = 0; k < n - i - 1; k++)
		{
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
		{
            printf("%d ", pascal[i][j]);
        }
        printf("\n");
    }
}
