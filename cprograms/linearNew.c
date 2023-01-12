#include<stdio.h>
linear_search(int array[],int data,int lastindex/int data,int *a,int l/)
{
	int currentpos=0;
	while(currentpos<lastindex && array[currentpos]!=data)
	{
		
  		currentpos++;
	}
	if(array[currentpos]==data)
	{
		printf("element found at index %d",currentpos);
			//return (currentpos);
	}
	else
  	{
  		printf("\n data not found");
  	}
	

	/*int i=0;
  while(i<l && *(a+i)!=data)
  {
  	i++;
  }
  if(*(a+i)==data)
  {
  	printf("element found at index %d",i);
  }
  else
  {
  	printf("\n data not found");
  }*/
	
}
int main()
{
	int data;
	int array[10]={20,32,40,22,85,88,99,77,64,2};
	printf("\nEnter data");
	scanf("%d",&data);
	linear_search(array,data,10/data,&array[0],10/);
}