#include<iostream>
using namespace std;

#define n 20

class queue
{
 int*array;
 int front;
 int rear;

 public:
     queue()
     {
      array=new int[n];
      front=-1;
      rear=-1;
     }


 void enqueue(int x)
 {
  if(rear==n-1)
  {
   cout<<"\n Queue overflow"<<endl;
   return;
  }
  else
  {
   rear++;
   array[rear]=x;
  }

  if(front==-1)
  {
    front++;
  }
 }

 void dequeue()
 {
  if(front==-1)
  {
   cout<<"\n No data in queue"<<endl;
  }
    else
  {
      front++;
  }
 }

 int display()
 {
  if(front==-1)
  {
   cout<<"No data in queue"<<endl;
   return -1;
  }
  else
  {
   return array[front];
  }
 }

};

int main()
{
 int choice=0;
 int x;
 queue d;

 while(choice<2)
 {
  cout<<"\n Queue Operation"<<endl;
  cout<<"\n 1]enqueue"<<endl;
  cout<<"\n 2]Dequeue"<<endl;
  cout<<"\n Enter Choice:=";
  cin>>choice;

  switch(choice)
  {
   case 1:cout<<"\n Enter the data:=";
          cin>>x;
          d.enqueue(x);
          break;

   case 2:cout<<"\n Dequeued data is:="<<d.display()<<endl;
          d.dequeue();
          break;
  }
 }
 return 0;
}
