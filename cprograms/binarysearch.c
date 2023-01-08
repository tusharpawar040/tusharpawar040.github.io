#include<stdio.h>
#define MAX100
void binarysearch(int [],int ,int ,int);

int main()
{
	int datalist[]={10,20,30,40,50,60};
	int search;
	printf("Enter value to search:=");
	scanf("%d",&search);
	binarysearch(datalist,0,5,search);
}

void binarysearch(int datalist[],int low, int high, int search)
{
	int mid; char flag='n';
	while(low<=high)
	{
		mid=(low+high)/2;
		if(datalist[mid]==search)
		{
			flag='y';
			break;
		}
		else
		{
			if(datalist[mid]>search)
			{
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		if(flag=='y')
		{
			printf("\n value found");
		}
		else{
			printf("\n Value not found");
		}
	}
}

