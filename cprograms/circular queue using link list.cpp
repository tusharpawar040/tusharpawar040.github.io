/* circular queue using linked list */

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	
};
struct node *f=NULL;
struct node *r=NULL;

void enqueue (int d) //insret element in queuq
{
	struct node* n;
	n=(struct node*)malloc(sizeof(struct node));
	n->data=d;
	n->next=NULL;
	if((r==NULL)&&(f==NULL))
	{
		f=r=n;
		r->next=f;
	}
	else
	{
		r->next=n;
		r=n;
		n->next=f;
	}
}

void dequeue()  //Delate an element from queue
{
	struct node* t;
	t=f;
	if((f==NULL)&&(r==NULL))
	  printf("\nQueue is empty");
	else if(f==r)
	{
		f=r=NULL;
		free(t);
	}
	else
	{
		f=f->next;
		r->next=f;
		free(t);
		
	}
}

void print() //print the elements of queue
{
	struct node* t;
	t=f;
	if((f==NULL)&&(r==NULL))
	  printf("\nQueue is empty");
	else
	{
		do
		{
			printf("\n%d",t->data);
			t=t->next;
		}while(t!=f);
	}
}

int main()
{
	int opt,n,i,data;
	printf("enter your choice:");
	do{
		printf("\n\n1 for insert the Data in Queue \n2for show the data in queue \n3 for Delete the data from the queue \n4Exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\n Enter the Number of data");
				scanf("%d",&n);
				printf("\nEnter your data");
				i=0;
				while(i<n)
				{
					scanf("%d",&data);
					enqueue(data);
					i++;
					
				}
				break;
			case 2:
				print();
				break;
			case 3:
				dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncoorect choice");
	
		}
}while(opt!=0);


return 0;		
	
 } 




