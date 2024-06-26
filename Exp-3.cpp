#include<stdio.h>
int main()
{
	int n1,n2,gcd;
	printf("Enter the number1:");
	scanf("%d",&n1);
	printf("Enter the number2:");
	scanf("%d",&n2);
	do
	{
		if(n1>n2)
		{
			n1=n1-n2;
		}
		else
		{
			n2=n2-n1;
		}
	}
	while(n1!=n2);
	{
		gcd=n1;
	}
	printf("Gcd of two number: %d",gcd);
}
