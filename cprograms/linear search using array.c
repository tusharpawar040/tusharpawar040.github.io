#include<stdio.h>
int main()
{
	int arr[10],n,i,item;
	printf("how many element you want to enter in the array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element %d",i+1);
		scanf("%d",&arr[i]);
	}
	printf("enter the element to be searched\n");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(item==arr[i])
		{
			printf("%d found at position %d\n",item,i+1);
			break;
		}
	}
	if(i==n)
	printf("item %d not found in array\n",item);
}
