#include<stdio.h>
int stack[5];
int top=-1;

void push(int data);
int pop();
int peek();
void display();



void push(int data)
{
    if(top==4)
    {
        printf("\n stack overflow");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}
int pop()
{
    int val;
    if(top==-1)
    {
        printf("\n stack is empty");

    }
    else
    {
        val=stack[top];
        top--;

    }
    return val;
}
int peek()
{
    int val;
    if(top==-1)
    {
        printf("stack is empty");

    }
    else{
        val=stack[top];

    }
    return val;
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n stack is empty");

    }
    else{
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }

    }
}

int main()
{
    int num,choice;
    choice=0;
    while(choice<5)
    {
        printf("\n stack operation:");
        printf("\n 1) push");
        printf("\n 2) pop");
        printf("\n 3) peek");
        printf("\n 4) display");
        printf("\n 5) exit");


        printf("\n enter your choice=");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n Enter the push element= ");
                    scanf("%d",&num);
                    push(num);
                    break;

            case 2: num=pop();
                    printf("\n poped element=%d",num);
                    break;

            case 3: num=peek();
                    printf("\n peeked element =%d", num);
                    break;

            case 4:display();
                    printf("\n");
        }
    }
    return 0;
}
