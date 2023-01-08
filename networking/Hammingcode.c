#include<stdio.h>
#include<math.h>
int main()
{
	int i=0,j=0,A[8],c[4],h[12],n=0;
	for(i=0;i<8;i++)
	{
		printf("Enter the %d bit of data",i);
		scanf("%d",&A[i]);
	}
	printf("Dataword is \n");
	for(i=0;i<8;i++)
	{
		printf("%d",A[i]);
	}
	c[0]=A[0]^A[2]^A[4]^A[6];
	c[1]=A[1]^A[2]^A[5]^A[6];
	c[2]=A[2]^A[3]^A[4];
	c[3]=A[3]^A[4]^A[5]^A[6];
	printf("redundant bits\n");
	for(i=0;i<4;i++)
	{
		printf("%d",c[i]);
	}
	
	for(j=0;j<12;j++)
	{
		if(pow(2,n)-1 == j)
		{
			h[j]=c[n];
			n++;
		}
		else
		{
			h[j]=A[i];
			i++;
		}
	}
	printf("\n data transmitted is \n");
	for(j=0;j<12;j++)
	{
		printf("%d",h[i]);
	}
	return 0;
}
int power(int X, int Y)
{
	int power=1,i;
	for(i=1;i<=Y;i++)
	{
		power=power*X;
	}
	return power;
}

