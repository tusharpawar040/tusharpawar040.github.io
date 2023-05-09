#include<iostream>
using namespace std;
class stack
{
	int *s;
	int size;
	int top;
public: 
	stack()
	{
		s=new int[10];
		top=-1;
		size=10;
	}
	stack(int n)
	{
		s=new int[n];
		top=-1;
		size=n;
	}
	int push(int data);
	int pop(int *popedData);
	int isEmpty();
};
class queue
{
	int *q;
	int size;
	int front;
	int rear;
	int spaceUsed;
public:
	queue()
	{
		q=new int[10];
		rear=0;
		front=0;
		size=10;
		int spaceUsed=0;
	}
	queue(int n)
	{
		q=new int[n];
		rear=0;
		front=0;
		size=n;
		int spaceUsed=0;
	}
	int enqueue(int data);
	int dequeue(int *returnedData);
};
//stack function
int stack::push(int data)
{
	if(top>=size)
		return 0;
	(top)++;
	s[top]=data;
	return 1;
}
int stack::isEmpty()
{
	if (top==-1)
		return 1;
	else
		return 0;
}
int stack::pop(int *popedData)
{
	if(isEmpty())
		return 0;
      *popedData=s[top];
	(top)--;
	return 1;
}
//queue function
int queue::enqueue(int data)
{
	if(spaceUsed==size)
		return 0;
	q[rear]=data;
	rear=(rear+1)%size;
	(spaceUsed)++;
	return 1;
}
int queue::dequeue(int *returnedData)
{
	if (spaceUsed==0)
		return 0;
	(spaceUsed)--;
	*returnedData=q[front];
	front=(front+1)%size;
	return 1;
}
int main()
{
    stack sc;
    queue qc;
	int data,status,option=0,queueData,returnedData,popedData;
	while(option<3)
	{
		cout<<"\nchoose a data structure to handle the data:\n";
		cout<<"1.queue 2.stack 3.exit\n";	
		cin>>option;
		switch(option)
		{
			case 1:
			    cout<<"\nwrite your choice:\n";
				cout<<"1.enqueue data 2.dequeue data 3.exit\n";	
				cin>>option;
	     		switch(option)
				{
					case 1: cout<<"enter data to enqueue:";
						cin>>queueData;
						status=qc.enqueue(queueData);
						if (status==0)
							cout<<"queue is full\n";	
						else
							cout<<"data is enqueued "<<endl;
						break;
					case 2:status=qc.dequeue(&returnedData);
						if (status==0)
							cout<<"queue is empty\n";	
						else					
							cout<<"dequeued data is "<<returnedData<<endl;
						break;
				}
				break;
			case 2:
			    cout<<"\nwrite your choice:\n";
				cout<<"1.push data 2.pop data 3.exit\n";	
				cin>>option;
	     			switch(option)
				{
					case 1:cout<<"enter data to store in stack:";
						cin>>data;
						status=sc.push(data);
						if (status==0)
							cout<<"stack is full\n";
						else
							cout<<"data is stored "<<endl;
						break;
					case 2:status=sc.pop(&popedData);
						if (status==0)
							cout<<"stack is empty\n";	
						else					
							cout<<"poped data is "<<popedData<<endl;
						break;
				}
				break;
		}
	}
	return 0;
}
