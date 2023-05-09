#include<iostream>
using namespace std;

#define n 100

class stack
{
 int*array;
 int top;

 public:
 stack()
 {
  array=new int[n];
  top=-1;
 }

 void push(int x)
 {
  if(top==n-1)
  {
   cout<<"\n Stack is Full"<<endl;
   return;
  }
  else
  {
   top++;
   array[top]=x;
  }
 }

 void pop()
 {
  if(top==-1)
  {
   cout<<"\n No element to pop"<<endl;
   return;
  }
  else
  {
   top--;
  }
 }

 int Top()
 {
  if(top==-1)
  {
   cout<<"\n No element in stack"<<endl;
   return -1;
  }
  return array[top];
 }
};



int main()
{
 int choice=0;
 int x;
 stack S;

 while(choice<2)
 {
  cout<<"\n Queue Operation"<<endl;
  cout<<"\n 1]push"<<endl;
  cout<<"\n 2]pop"<<endl;
  cout<<"\n Enter Choice:=";
  cin>>choice;

  switch(choice)
  {
   case 1:cout<<"\n Enter the data:=";
          cin>>x;
          S.push(x);
          break;

   case 2:cout<<"\n Popped data is:="<<S.Top()<<endl;
          S.pop();
          break;
  }
 }
}
