#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node * next;

};


struct node *head=NULL;
void InsertAtBegin(int data);
void InsertAtMiddle(int data , int position);
void InsertAtEnd(int data);

void nodecount();
void nodetraversal();

void DelAtBeg();
void DelAtMid(int position);
void DelAtEnd();


void InsertAtBegin(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    if(temp==NULL)
    {
        printf("\n no node created");
    }
    else
    {
        temp->num =data;
        temp->next =NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }

}
void InsertAtEnd(int data)
{
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));
    current=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n no node created");
    }
    else
    {
        temp->num =data;
        temp->next =NULL;
    }
        if(head==NULL)
        {
            head=temp;
        }
        else{
            current=head;
            while(current !=NULL)
            {
                current=current->next;
            }

        current->next=temp;


    }
}
void InsertAtMiddle(int data , int position )
{
    struct node *temp,*current;
    int count;
    temp=(struct node *)malloc(sizeof(struct node));
    current=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\n no node created");
    }
    else
    {
        temp->num=data;
        temp->next=NULL;
        if(head==NULL)
            head=temp;
        else{
            current=head;
            for(count=0;count<position-1;count++)
            {
                if(current->next==NULL)
                {
                    printf("\n insufficient nodes");
                }
                else
                {
                    current=current->next;
                }
            }
            temp->next=current->next;
            current->next=temp;
        }
    }
}
void nodecount()
{
    struct node *current;
    int cnt=0;
    if(head==NULL)
    {
        printf("\n list is empty");
        return;
    }
    else{
        current=head;
        while(current!=NULL)
        {
            cnt++;
            current=current->next;
        }
        printf("\n size of linked list=%d",cnt);
    }
}

void nodetraversal()
{
    struct node *current;
    if(head==NULL)
    {

        printf("\n list is empty");
    }
    else
    {
        current=head;
        while(current!=NULL)
        {

            printf("\n node element=%d",current->num);
            current=current->next;
        }
    }
}

void DelAtBeg()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\n list is empty");
        return;
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }

}

void DelAtEnd()
{
    struct node *current, *previous;
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    else{
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;

        }
        previous->next=NULL;
        free(current);
    }

}

void DelAtMid(int position)
{

    struct node *current, *previous;
    int cnt;
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    else{
        current=head;
        for(cnt=0;cnt<position-1;++cnt)
        {
            if(current->next==NULL)
            {
                printf("\n Insufficient nodes");
                return;

            }
            else{
                previous=current;
                current=current->next;
            }

        }
        previous->next=current->next;
        free(current);
    }

}

int main()
{

    int choice,num,position;
    while(1)
    {

        printf("\n list operation");
        printf("\n 1) InsertAtBegin");
        printf("\n 2) InsertAtMiddle");
        printf("\n 3) InsertAtEnd");
        printf("\n 4) node count");
        printf("\n 5) node traversal");
        printf("\n 6) DelAtBeg");
        printf("\n 7) DelAtMid");
        printf("\n 8) DelAtEnd");
        printf("\n 9) exit(0)");

        printf("\n enter the choice");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1: printf("\n enter the node elements");
                    scanf("%d",&num);
                    InsertAtBegin(num);
                    break;
            case 2: printf("\n enter the node value");
                    scanf("%d",&num);
                    printf("enter the position=");
                    scanf("%d",&position);
                    InsertAtMiddle(num, position);
                    break;
            case 3: printf("\n enter the node value");
                    scanf("%d",&num);
                    void InsertAtEnd(data);
                    break;
            case 4: nodecount();
                    break;
            case 5: nodetraversal();
                    break;
            case 6: DelAtBeg();
                    break;
            case 7: printf("enter the position to remove=");
                    scanf("%d",&position);
                    DelAtMid(position);
                    break;
            case 8: DelAtEnd();
                    break;
            case 9: exit(0);
            default: printf("\n make proper choice");

        }
    }
}
