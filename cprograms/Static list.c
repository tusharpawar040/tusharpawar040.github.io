#include<stdio.h>
void insert(int*  ,int ,int);
int insert_at_begin(int * ,int ,int ,int );
int insert_at_end(int * ,int ,int ,int );
int insert_after_(int * ,int ,int ,int ,int );
int insert_before(int *,int ,int ,int ,int );
int insert_specific(int *,int ,int ,int ,int );
void delet(int* ,int e);
int delet_begin(int* ,int  );
int delet_end(int* ,int );
int delet_after(int* ,int ,int);
int delet_before(int* ,int ,int );
int delet_specific(int* ,int ,int );
int search(int* ,int  );
void traverse(int* ,int );
void main()
{
  int a[100],i,x,p,c;
  printf("elements of arry are:  ");
  for(i=0;i<10;i++)
  {
  	a[i]=i+1;
  	printf("%d  ",a[i]);
  }
  printf("\nEnter your choise :\n");
  printf("1-Insertion\n");
  printf("2-Deletation\n");
  printf("3-Search\n");
  printf("4-Traverse");
  scanf("%d",&x);
  switch(x)
  {
  	case 1:
  	insert(&a[0],100,9);
  	break;
  	case 2:
  	delet(&a[0],9);
  	break;
  	case 3:{
	c=search(&a[0],9);
  	if (c==-1){
	  
  	printf("\nelement not found");}
  	else
  	printf("\nElement has found at %d",c);
  }
  case 4:
  	traverse(&a[0],9);
  }
}
void insert(int* a ,int max,int e)
{
	int x,result,d,i,p;
    printf("enter a data wich you have to enter");
    scanf("%d",&d);
	printf("Enter a choise :");
	printf("1-begin\n");
  printf("2-end\n");
  printf("3-After specific\n");
  printf("4-Before Specific\n");
	printf("5-at_specific\n");
	scanf("%d",&x);

	switch(x)
	{
		case 1:
			{
		  result=insert_at_begin(a,max,d,e);
		  if(result=1)
		 {
		 printf("\nsucsses \n");
		 for(i=0;i<=e+1;i++)
		 {
		 	printf("%d  ",*(a+i));
		 }
		 }
		  
		  else{
		  printf("fail");
		  
			} break;}
		case 2:
			{
			 result=insert_at_end(a,max,d,e);
			 if(result=1)
			 {
			 	printf("\n sucsses \n");
			 for(i=0;i<=e+1;i++)
		 {
		 	printf("%d  ",*(a+i));
		 }
			 }
			 else{
			 
			 printf("fail");}
			 break;
			}
			case 3:
			{ printf("\nenter a position\n");
				scanf("%d",&p);
				result=insert_after(a,max,d,e,p);
				
			if(result==0)
			 {
			 	printf("\nFail");
			 }
			 else
			{
			  printf("\n sucsses \n");
			 for(i=0;i<=e+1;i++)
		 
		 	printf("%d  ",*(a+i));
		 }	break;
			}
			case 4:
				{
					printf("\n Enter a position:  ");
					scanf("%d",&p);
					result=insert_before(a,max,d,e,p);
						if(result==0)
			 {
			 	printf("\nFail");
			 }
			 else
			{
			  printf("\n sucsses \n");
			 for(i=0;i<=e+1;i++)
		 
		 	printf("%d  ",*(a+i));
		 }	break;
				}
			case 5:
				{
					printf("\n Enter a position:  ");
					scanf("%d",&p);
					result=insert_specific(a,max,d,e,p);
						if(result==0)
			 {
			 	printf("\nFail");
			 }
			 else
			{
			  printf("\n sucsses \n");
			 for(i=0;i<=e+1;i++)
		 
		 	printf("%d  ",*(a+i));
				} break;
	}
	
}}
int insert_at_begin(int *a,int max,int d,int e)
{
int i;
 if(e<max){
  for(i=e+1;i>0;i--)
  {
  *(a+i)=*(a+i-1);};
  *a=d;
  return 1;}
  else
  return 0;
  
  
}
int insert_at_end(int *a,int max,int d,int e)
{
	if(e<max)
	{
	
	*(a+e+1)=d;
	return 1;
}
else
return 0;
}
int insert_after(int* a,int max,int d,int e,int p)
{
	printf("%d",e);
	int i,result;
	if(p<e)
	{
		for(i=e+1;i>p;i--)
  {
  *(a+i)=*(a+i-1);};
  *(a+p)=d;
  return 1;
	}
	else if(p>e)
	{
	
    return 0;
	}
else
   {
       result=insert_at_end(a,max,d,e);
		if (result=0)
		return 0;
		else
		return 1;
   }
}
int insert_before(int* a,int max,int d,int e,int p)
{
 int	result;
	if(p==0)
	{
		result=insert_at_begin(a,max,d,e);
		if(result==1)
		return 1;
		else
		return 0;
	}
    else
    {
    	int c=p-1;
    	result=insert_after(a,max,d,e,c);
    	if(result==1)
    	return 1;
    	else
    	return 0;
	}
}

int insert_specific(int *a,int max,int d,int e,int p)
{ 
    int result;
    if (p==0)
    {
    	result=insert_at_begin(a,max,d,e);
    	if(result==1)
    	return 1;
    	else
    	return 0;
	}
	else if(p<=e)
	{
	  int c=p-1;
		result=insert_after(a,max,d,e,c);
		if(result==1)
		return 1;
		else
		return 0;
	}
	else
	return 0;

}
void delet(int* a,int e)
{
		int x,result,i,p;
	printf("Enter a choise :");
	printf("1-begin\n");
  printf("2-end\n");
  printf("3-After specific\n");
  printf("4-Before Specific\n");
	printf("5-at_specific\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			{
			 result=delet_begin(a,e);
			 printf("%d is deleted\n",result);
			 printf("\nArry after deleting begining element");
			 for(i=0;i<e;i++)
			 {
			 	printf("%d ",*(a+i));
			 }
				
		}
		case 2:
			{
				result=delet_end(a,e);
				printf("\n deleted element is %d",result);
				printf("\n Arry after deleting element: ");
				for(i=0;i<e;i++)
				{
					printf("%d  ",*(a+i));
				}
			}
		case 3:
			{   printf("\n Enter a position \n");
			    scanf("%d",&p);
			    if(p<e && p>=0){
				
				result=delet_after(a,e,p);
				printf("\n Deleted element id %d",result);
				printf("\n Arry after deleting element: ");
				for(i=0;i<e;i++)
				{
					printf("%d  ",*(a+i));
				}
			}
			else
			printf("\nEnter a valid position");
			}
		case 4:
			{
				printf("\n Enter a position \n");
				scanf("%d",&p);
				 if(p<e+1 && p>=1){
				
				result=delet_before(a,e,p);
				printf("\n Deleted element id %d",result);
				printf("\n Arry after deleting element: ");
				for(i=0;i<e;i++)
				{
					printf("%d  ",*(a+i));
				}
			}
			else
			printf("\nEnter a valid position");
				
			}
	
		case 5:
			{
				printf("\n Enter a position \n");
				scanf("%d",&p);
				 if(p<e+1 && p>=0){
				
				result=delet_specific(a,e,p);
				printf("\n Deleted element id %d",result);
				printf("\n Arry after deleting element: ");
				for(i=0;i<e;i++)
				{
					printf("%d  ",*(a+i));
				}
			}
			else
			printf("\nEnter a valid position");
				
			}
	}
}
int delet_begin(int* a,int e)
{
	int i;
	int *tmp;
	*tmp=*a;
	for(i=0;i<e+1;i++)
	{
		*(a+i)=*(a+i+1);
	}
	return *tmp;
}
int delet_end(int* a,int e)
{
	return *(a+e);
}
int delet_after(int* a,int e,int p)
{
	int i;
	int* temp;
	*temp=*(a+p+1);
	for(i=p+1;i<e;i++)
	{
		*(a+i)=*(a+i+1);
	}
	return *temp;
}
int delet_before(int* a,int e,int p)
{
int i;	int *temp;
	*temp=*(a+p-1);
	for(i=p-1;i<=e;i++)
	{
		*(a+i)=*(a+i+1);
	}
	return *temp;
}
int delet_specific(int*a,int e,int p)
{
	int i; int *temp;
	*temp=*(a+p);
	for(i=p;i<=e;i++)
	{
		*(a+i)=*(a+i+1);
	}
	return *temp;
}
int search(int *a,int e)
{ int p; 
 int i=0;
printf("\n enter element to the search");
  	scanf("\n%d",&p);
	
	while(i<=e)
	{
		if(*(a+i)==p)
		{
		return i;}
		else
		continue;
	}
	return -1;
}
void traverse(int *a, int e)
{int i;
	printf("elements of arry are:  ");
  for(i=0;i<=e;i++)
  {
  	printf("%d  ",*(a+i));
  }
}
