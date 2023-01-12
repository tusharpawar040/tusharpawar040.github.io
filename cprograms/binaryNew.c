#include<stdio.h>
int binarysearch(int array[],int low, int high, int datasearch)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(array[mid]==datasearch)
		{
			return (mid);
		}
			
		if(array[mid]<datasearch)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
			
	}
		printf("element found at index %d",datasearch);
	
	return (datasearch);
}
int main()
{
	int data;
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	printf("\nEnter data");
	scanf("%d",&data);
	int x=binarysearch(array,0,9, data);
	printf("%d",x);
}

/*#include<stdio.h>
int binarysearch(int array[],int low, int high, int datasearch)
{
	int mid;
	
	
		mid=(low+high)/2;
		if(array[mid]==datasearch)
		{
			printf("element found at index %d",mid);
		}
		
		if(array[mid]<datasearch)
		{
			low=mid+1;
			binarysearch(array,low, high, datasearch);
			
			
		}
		else
		{
			high=mid-1;
			binarysearch(array,low, high, datasearch);
			
		}
			
	

	return 0;
}
int main()
{
	int data;
	int array[10]={1,2,3,4,5,6,7,8,9,10};
	printf("\nEnter data");
	scanf("%d",&data);
	binarysearch(array,0,9, data);
	
}
*/