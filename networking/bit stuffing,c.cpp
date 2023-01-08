#include<stdio.h>
#include<string.h>
int main()
{
	int count=0,j=0,i;
	char bit[50],stuffed[50];
	printf("\n Enter the bit for stuffing:");
	scanf("%s",bit);
	for(i=0;i<strlen(bit);i++)
	{
		stuffed[j]=bit[i];
		j++;
		if(bit[i]=='1')
		{
			count++;
		}
		if(count==5)
		{
			stuffed[j]='0';
			j++;
		}
		if(count==0 || bit[i]=='0')
		{
			count=0;
		}
	}
	printf("\n STUFFED:");
	for(i=0;i<j;i++)
	{
		printf("%c",stuffed[j]);
	}
	return 0;
}
