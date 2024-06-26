#include<stdio.h>
int main()
{
	int n,a[]={10,12,17,11,16};
	n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Largest number: %d",a[n-1]);
}
