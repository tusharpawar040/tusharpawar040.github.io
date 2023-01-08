#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *leftchild;
	struct node *rightchild;
};
struct node *createnode(int);
struct node *buildtree(struct node **,int);
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

struct node *buildtree(struct node **rptr,int data)
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
		else
		{
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
	else
	{
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
		return;
	}
	else{
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
	while(1)
    {

        printf("\n list operation");
        printf("\n 1) buildtree");
        printf("\n 2) Inorder Traversal");
        printf("\n 3) height of tree");
        printf("\n 4) exit(0)");
        

        printf("\n enter the choice");
        scanf("%d",&choice);

        switch(choice)
        {

            case 1: printf("\n enter the node elements");
                    scanf("%d",&num);
                   	root=buildtree(&root,num);
                    break;
            case 2: printf("\nInorder Traversal");
                    Inorder(root);
                    break;
            case 3: printf("\nthe height of tree is");
                    break;
            case 9: exit(0);
            default: printf("\n make proper choice");
		}
    }
    return 0;
}
