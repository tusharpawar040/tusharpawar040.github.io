#include<iostream>
using namespace std;
class node
{public:
	int data;
	node* next;
	node()
	{
		data=0;
		next=NULL;
	}
};
class linkedList
{
	node* head;
	node* createNode();
	void initNode(node* nnode,int data);
public:
	linkedList()
	{
		head=NULL;
	}
	int attachBegin(int data);
	void traverse();
	void attachEnd(int data);
	node* detachBegin();
	node* detachEnd();
	int attachMiddle(int data,int dataCheck);
	node* detachMiddle(int dataSearch);
	node* desiredNode(int data);
};


node* linkedList::createNode()
{
	node* temp;
	temp=new node();
	return temp;
}
void linkedList::initNode(node* nnode,int data)
{
	nnode->data=data;
}
int linkedList::attachBegin(int data)
{
	node *tNode=NULL;
	tNode=createNode();
	initNode(tNode,data);
	if(head==NULL)
	{
		head=tNode;
		return 1;
	}
	else
	{
		tNode->next=head;
		head=tNode;
		return 1;
	}
}
void linkedList::traverse()
{
	node* currentNode;
	if (head!=NULL)
	{
		currentNode=head;		
		while(currentNode!=NULL)
		{
			cout<<currentNode->data<<"\t";
			currentNode=currentNode->next;
		}
	}
	else
	{
		cout<<"currently list is empty\n";
	}
}
void linkedList::attachEnd(int data)
{
	node *firstNode=NULL;
	node *lastNode=NULL;
	node *currentNode=NULL;
	node *tNode=NULL;
	tNode=createNode();
	initNode(tNode,data);
	if (head==NULL)
		head=tNode;
	else
	{
		firstNode=head;
		currentNode=firstNode;
		while(currentNode->next!=NULL)
		{
			currentNode=currentNode->next;
		}
		lastNode=currentNode;
		lastNode->next=tNode;
	}
}
node* linkedList::detachBegin()
{
	node *firstNode=NULL;
	if (head==NULL)
		return NULL;
	else
	{
		firstNode=head;
		head=firstNode->next;
		return firstNode;
	}
}
node* linkedList::detachEnd()
{
	node *firstNode;	
	node *lastNode;
	node *previousLastNode;
	node *currentNode=NULL;	
	if (head==NULL)
		return NULL;
	firstNode=head;
	if (firstNode->next==NULL)
	{
		head=NULL;
		return (firstNode);	
	}
	else
	{
		currentNode=firstNode;
		while(currentNode->next!=NULL)
			currentNode=currentNode->next;
		lastNode=currentNode;
		currentNode=firstNode;
		while(currentNode->next!=lastNode)
			currentNode=currentNode->next;
		previousLastNode=currentNode;
		previousLastNode->next=NULL;
		return lastNode;
	}
}
int linkedList::attachMiddle(int data,int dataCheck)
{
	node*nextNode;
	node*requiredNode;
	node* tNode=NULL;	
	tNode=createNode();
	initNode(tNode,data);
	if (head==NULL)
		return 0;
	else
	{
		requiredNode=desiredNode(dataCheck);
		if(requiredNode==NULL)
			return -1;
		else
		{
			nextNode=requiredNode->next;
			tNode->next=nextNode;
			requiredNode->next=tNode;
			return 1;			
		}
	}
}
node* linkedList::desiredNode(int data)
{
	node*firstNode;
	node*currentNode;
	firstNode=head;
	currentNode=firstNode;
	while(currentNode!=NULL)
	{
		if (currentNode->data==data)
			return currentNode;
		currentNode=currentNode->next;
	}
	return NULL;
}
node* linkedList::detachMiddle(int dataSearch)
{
	node*nextNode;
	node*requiredNode;	
	if (head==NULL)
		return NULL;
	else
	{
		requiredNode=desiredNode(dataSearch);
		if(requiredNode==NULL)
			return NULL;
		else
		{
			nextNode=requiredNode->next;
			requiredNode->next=nextNode->next;
			return nextNode;		
		}
	}
}
int main()
{
	linkedList l;
	node* tmp=NULL;
	int choice,data,dataToSearch;
	do
	{
		cout<<"\n1.travese 2.attach at beginning 3.attach at middle 4.attach at end"; 
		cout<<"\n5.detach from beginning 6.detach from middle 7.detach from end 8.stop\n";
		cout<<"enter your choice";
		cin>>choice;
		switch(choice)
		{
			case 1:
				l.traverse();
				break;
			case 2:	
		    		cout<<"enter data to store:";	
				cin>>data;
				l.attachBegin(data);
				l.traverse();
				break;
			case 3:	
		    		cout<<"enter data to store:";
				cin>>data;	
				cout<<"enter data to search:";
				cin>>dataToSearch;	
				l.attachMiddle(data,dataToSearch);
				l.traverse();
				break;
			case 4:
				cout<<"enter data to store:";
				cin>>data;
				l.attachEnd(data);
				l.traverse();	
				break;
			case 5:
				tmp=l.detachBegin();
				cout<<"detached data is: "<<tmp->data<<endl;
				cout<<"after detaching data from begining\n";
				l.traverse();
				break;
			case 6:	
				cout<<"enter data to search:";
				cin>>dataToSearch;	
				tmp=l.detachMiddle(dataToSearch);
				cout<<"detached data is: "<<tmp->data<<endl;
				cout<<"after detaching data \n";
				l.traverse();
				break;
			case 7:
				tmp=l.detachEnd();
				cout<<"after detaching data at end\n";
				l.traverse();
				break;
		}
	}while(choice<8);		
	return 0;
}
