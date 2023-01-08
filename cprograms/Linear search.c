#include<stdio.h>
int linear_search(int* ,int ,int );
void main()
{  
	int n,i;
	int a[10],r,d;
	printf("\nEnter a elements of array:");
	for(i=0;i<10;i++)
	{   
		scanf("\n %d",&a[i]);
	}
	printf("\n Enter a data to search");
	scanf("%d",&d);
	r=linear_search(&a[0],10,d);
	if(r== -1)
	printf("\n element not found");
	else
  	printf("Element fount at index %d",n);
}
int linear_search(int* a,int n,int d)
{
	int i=0;
	while(i<n && *(a+i)!=d)
	{
		i++;
	}
	if(i==n)
	return -1;
	else
	return i;
}
