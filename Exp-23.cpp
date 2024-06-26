#include<stdio.h>
int main()
{
	int d,rev,num;
	printf("Enter the number:");
	scanf("%d",&num);
	while(num!=0)
	{
		d=num%10;
		rev=rev*10+d;
		num=num/10;
	}
	printf("Reversed number:%d",rev);
}
