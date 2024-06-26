#include<stdio.h>
#include<string.h>
int main()
{
	int length;
	char str[100];
	printf("Enter the string:");
	scanf("%s",&str);
	length=strlen(str);
	printf("Length of the string:%d",length);
}
