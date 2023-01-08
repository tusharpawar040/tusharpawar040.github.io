/*#include<stdio.h>
#include<string.h>
int main()
{
	int j=0,i;
	char byte[50],stuffed[50];
	printf("\n Enter character:");
	scanf("%s",byte);
	int l=strlen(byte);
	stuffed[j]='@';
	j++;
	for(i=0;i<l;i++)
	{
		if(byte[i]=='@' || byte[i]=='#')
		{
			stuffed[j]='#';
			j++;
			stuffed[j]=byte[i];
		}
		else
		{
			stuffed[j]=byte[i];
			j++;
		}
	}
	stuffed[j]='@';
	printf("BYTE STUFFING:");
	for(i=0;i<=j;i++)
	{
		printf("%c",stuffed[i]);
	}
	return 0;
}*/

#include<stdio.h>
#include<string.h>
int main()
{
	int j=0,i;
	char received[50],code[50];
	printf("\nEnter received Data:");
	scanf("%s",received);
	for(i=1;i<strlen(received)-1;i++)
	{
		if(received[i]=='#')
		{
			i++;
		}
		code[j]=received[i];
		j++;
    }
    printf("CODE:");
	for(i=0;i<j;i++)
	{
		printf("%c",code[i]);
	}
	return 0;
}
