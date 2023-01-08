#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *link;
};

struct node *createnode(int);
void push(struct node **);
void pop(struct node **);
void peek(struct node *);
void display(struct node*);

struct node *createnode(int data)
{
   struct node *temp;
   temp=(struct node *)malloc(sizeof(struct node));
   temp->num=data;
   temp->link=NULL;
   return temp;
}
void push(struct node **topptr)
{
    struct node *temp;
    int value;
    printf("\n Enter the stack value=");
    scanf("%d",&value);
    temp=createnode(value);
    if((*topptr)==NULL)
    {
        (*topptr)=temp;
    }
    else{
        temp->link=*topptr;
        (*topptr)=temp;
    }
}
void pop(struct node **topptr)
{
    struct node *temp;
    if((*topptr)==NULL)
    {
        printf("stack is empty");
    }
    else
    {
        temp=(*topptr);
        (*topptr)=temp->link;
        free(temp);
    }

}
void peek(struct node *current)
{
    if (current==NULL)
    {
        printf("\n stack is empty");
    }
    else
    {
        printf("\n node value=%d",current->num);

    }

}
void display(struct node *current)
{
    if((current)==NULL)
    {
        printf("\n stack is empty");
    }
    else
    {
        while(current!=NULL)
        {


            printf("\n node value=%d",current->num);
            current = current ->link;
        }
    }
}
int main()
{
    int choice,num;
    struct node *top=NULL;
    while(1)
    {
        printf("\n list operation:");
        printf("\n 1. push");
        printf("\n 2. pop ");
        printf("\n 3. peek ");
        printf("\n 4. display");
        printf("\n 5. exit");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :push(&top);
                    break;
            case 2 :pop(&top);
                    break;
            case 3 :peek(top);
                    break;
            case 4:display(top);
                    break;
            case 5:exit(0);
                    break;
            default:printf("Make Proper Choice!!");
        }
    }
}
