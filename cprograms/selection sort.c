#include<stdio.h>
#define MAX 100
void selectionsort(int [],int size);
int main()
{
	int datalist[MAX],size, index;
	printf("\nEnter the size of an array:=");
	scanf("%d",&size);
	printf("Enter %d number of elements:=", size);
	for(index=0;index<size;index++)
	{
		scanf("%d",&datalist[index]);
	}
	selectionsort(datalist, size);
	return 0;
}

void selectionsort(int datalist[],int size)
{
	int fixed, change, temp;
	for(fixed=0;fixed<size-1;fixed++)
	{
		for(change=fixed+1;change<size;change++)
		{
			if(datalist[fixed]>datalist[change])
			{
				temp=datalist[fixed];
				datalist[fixed]=datalist[change];
				datalist[change]=temp;
			}
		}
	}
	printf("\n Ascending order \n");
	for(fixed=0;fixed<size;fixed++)
	{
		printf("%d\t",datalist[fixed]);
	}
}
