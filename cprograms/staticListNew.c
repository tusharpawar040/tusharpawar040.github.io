#include<stdio.h>
#include<stdlib.h>
int traverse(int list[],int lastPos);
int shiftDown(int list[],int size,int startPos,int lastPos);
int insertEnd(int list[],int size,int *lastPos,int insertData);
int insertBegin(int list[],int size,int *lastPos,int startPos,int insertData);
int deleteEnd(int *lastPos);
int insertMiddle(int list[],int size,int *lastPos,int insertPos,int insertData);
int shiftUp(int list[],int deletePos,int lastPos);
int deleteMiddle(int list[],int deletePos,int *lastPos);
int deleteBegin(int list[],int *lastPos);
int main()
{
	int listArray[100];
	int sz,data,choice,status;
	int startPosition=0;
	int lastPosition=-1;
	int insertPosition;
	int deletePosition;
	printf("\nEnter the size of list that you want to create : ");
	scanf("%d",&sz);
	while(1)
	{
        printf("\nOperation that you want to perform");
        printf("\n1)insertBegin\n2)insertMiddle\n3)insertEnd\n4)deleteBegin\n5)deleteMiddle\n6)deleteEnd\n7)Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter data to insert:");
                    scanf("%d",&data);
                    insertBegin(listArray,sz,&lastPosition,startPosition,data);
                    traverse(listArray,lastPosition);
                    break;

            case 2:printf("Enter data to insert:");
                    scanf("%d",&data);
                    printf("Enter Position To Insert Data:");
                    scanf("%d",&insertPosition);
                    insertMiddle(listArray,sz,&lastPosition,insertPosition,data);
                    traverse(listArray,lastPosition);
                    break;

            case 3:printf("Enter data to insert:");
                    scanf("%d",&data);
                    insertEnd(listArray,sz,&lastPosition,data);
                    traverse(listArray,lastPosition);
                    break;

            case 4:deleteBegin(listArray,&lastPosition);
                    traverse(listArray,lastPosition);
                    break;

            case 5:
                    printf("Enter Position To Delete Data:");
                    scanf("%d",&deletePosition);
                    deleteMiddle(listArray,deletePosition,&lastPosition);
		    		traverse(listArray,lastPosition);
                    break;
            case 6:deleteEnd(&lastPosition);
                    traverse(listArray,lastPosition);
                    break;
            case 7:exit(0);
		   printf("Invalid choice");
            	   break;
        }
	}
	return 0;
}
int traverse(int list[],int lastPos)
{
	int currentPos=0;
	while(currentPos<=lastPos)
	{
		printf("\n%d",list[currentPos]);
		currentPos++;
	}
	return 0;
}
int insertEnd(int list[],int size,int *lastPos,int insertData)
{
	if(*lastPos<=(size-1))
	{
		list[*lastPos+1]=insertData;
		*lastPos=*lastPos+1;
		return 1;
	}
	else
	{
		return 0;
	}
}

int shiftDown(int list[],int size,int startPos,int lastPos)
{
	int currentPos;
	if(lastPos<=(size-1))
	{
		if(startPos<=lastPos) //shift position 
		{
			currentPos=lastPos;
			while(currentPos>=startPos)
			{
				list[currentPos+1]=list[currentPos];
				currentPos--;
			}
		}
		else
		{
			return 0;
		}
	}

}
int insertBegin(int list[],int size,int *lastPos,int startPos,int insertData)
{
	if(*lastPos==-1)
	{
		list[startPos]=insertData;
		*lastPos=*lastPos+1;
	}
	else
	{
		shiftDown(list,size,startPos,*lastPos);
		list[0]=insertData;
		*lastPos=*lastPos+1;
	}
	return 0;
}
int deleteEnd(int *lastPos)
{
	if(*lastPos!=-1)
	{
		*lastPos=*lastPos-1;
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int insertMiddle(int list[],int size,int *lastPos,int insertPos,int insertData)
{
	if(insertPos<=(*lastPos+1))
	{
		if (size>(*lastPos+1))
		{
			if(insertPos==(*lastPos+1))
			{
				list[insertPos]=insertData;
				*lastPos=*lastPos+1;
				return 1;
			}
			else
			{
				shiftDown(list,size,insertPos,*lastPos);
				list[insertPos]=insertData;
				*lastPos=*lastPos+1;
				return 0;
			}
		}
	}
}
int shiftUp(int list[],int deletePos,int lastPos)
{
	int currentPos;
	if(deletePos<lastPos)
	{
		currentPos=deletePos;
		while(currentPos<lastPos)
		{
			list[currentPos]=list[currentPos+1];
			currentPos=currentPos+1;
		}
	}
}
int deleteMiddle(int list[],int deletePos,int *lastPos)
{
	if(*lastPos>-1)
	{
		if(deletePos==*lastPos)
		{
			*lastPos=*lastPos-1;
			return 1;
		}
		else
		{
			shiftUp(list,deletePos,*lastPos);
			*lastPos=*lastPos-1;
			return 1;
		}
	}
	return 0;
}
int deleteBegin(int list[],int *lastPos)
{
	int deletePos=0;
	if(*lastPos==-1)
	{
		return 0;
	}
	else
	{
		if(*lastPos<1)
		{
			*lastPos=*lastPos-1;
			return 1;
		}
		else
		{
			shiftUp(list,deletePos,*lastPos);
			*lastPos=*lastPos-1;
			return (1);
		}
	}
}