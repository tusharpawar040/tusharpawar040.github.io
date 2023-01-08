#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *leftchild;
    struct node *rightchild;
};

struct node *createnode(int);
struct node *buildtree(struct node **, int );
void inorder(struct node *);
int height(struct node *);

struct node *createnode(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->num=data;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
};
struct node *buildtree(struct node **rptr, int data)
{
    struct node *newnode;
    int num;
    newnode=createnode(data);
    if((*rptr)==NULL)
    {
        (*rptr)=newnode;
    }
    else
    {
        if((*rptr)->num>data)
        {
            (*rptr)->leftchild=buildtree(&(*rptr)->leftchild,data);
        }
        else{
            (*rptr)->rightchild=buildtree(&(*rptr)->rightchild,data);
        }
    }
    return (*rptr);
};
void inorder(struct node *rptr)
{
    if(rptr==NULL)
    {
        return ;
    }
    else{
        inorder(rptr->leftchild);
        printf("%d\t",rptr->num);
        inorder(rptr->rightchild);
    }

}
int height(struct node *rptr)
{
    int leftheight=0,rightheight=0,maxheight;
    if(rptr==NULL)
    {
        return 0;
    }
    else
    {
        leftheight=height(rptr->leftchild);
        rightheight=height(rptr->rightchild);

        if(leftheight>=rightheight)
        {
            maxheight=leftheight+1;
        }
        else
        {
            maxheight=rightheight+1;
        }
    }
    return maxheight;
}
int main()
{
    int choice=0,num;
    struct node *root=NULL;
    while(choice<4)
    {
        printf("\n 1. build tree");
        printf("\n 2. inorder Traversal");
        printf("\n 3. height of tree ");
        printf("\n 4. exit");

        printf("\n Enter your choice=");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\n Enter a newnode element");
                    scanf("%d",&num);
                    root=buildtree(&root,num);
                    break;
            case 2: printf("inorder traversal:");
                    inorder(root);
                    break;
            case 3: printf("\n the height of the tree is:%d",height(root));
                    break;
            default:printf("\n make proper choice");
        }
    }
    return 0;
}
