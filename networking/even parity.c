#include<stdio.h>
void main()
{
	int ones=0,i;
	char bit[8];
	printf("\n Entere the 7 bit of data:=");
	scanf("%s",bit);
	for(i=0;i<7;i++)
	{
		if(bit[i]=='1')
		{
			ones++;
		}
	}
	if(ones%2==0)
	{
		bit[7]='0';
	}
	else
	{
		bit[7]='1';
	}
	printf("\n Even parity=");
	for(i=0;i<8;i++)
	{
		printf("%c",bit[i]);
	}
}

/*#include<stdio.h>
void main()
{
	int ones=0, i;
	char bit[8];
	printf("\n enter the received 7 bit data=");
	scanf("%s",bit);
	for(i=0;i<7;i++)
	{
		if(bit[i]=='1')
		{
			ones++;
		}
	}
	if(ones%2==0)
	{
		printf("ACCEPTED");
	}
	else
	{
		printf("REJECTED");
	}
}*/
