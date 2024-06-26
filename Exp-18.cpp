#include <stdio.h>
int main()
{
    int num, prime[100], count, primeCount = 0;
    printf("Enter the number: ");
    scanf("%d", &num);
    for (int i = 2; i <= num; i++)
	{
        count = 0;
        for (int j = 1; j <= i; j++)
		{
            if (i % j == 0)
			{
                count++;
            }
        }
        if (count == 2)
		{
            prime[primeCount++] = i;
        }
    }
    printf("Prime numbers up to %d are: ", num);
    for (int i = 0; i < primeCount; i++)
	{
        printf("%d ", prime[i]);
    }
    printf("\n");
}
