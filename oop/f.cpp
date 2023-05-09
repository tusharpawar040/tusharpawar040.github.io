#include<iostream>
#include<string>
using namespace std;

struct student
{
 int prn;
 string name;
 string address;
 int mark[5];
};


int setPrn(int x,struct student*s)
{
 s->prn=x;
}

int getPrn(struct student s)
{
 return(s.prn);
}

int setName(string x,struct student*s)
{
 s->name=x;
}

string getName(struct student s)
{
 return(s.name);
}

int setAddress(string x,struct student*s)
{
 s->address=x;
}

string getAddress(struct student s)
{
 return(s.address);
}

int setMark(int x,struct student*s,int i)
{
 s->mark[i]=x;
}

int getMark(struct student s,int i)
{
 return(s.mark[i]);
}

int main()
{
 int prn;
 struct student s;
 string name,address;
 int mark[5];
 int x,i;
 int result;


 cout<<"\n Enter the name of student:="<<endl;
 getline(cin,name);
 setName(name,&s);
 cout<<"\n Name of student is:="<<getName(s);


 cout<<"\n Enter the Address of student:="<<endl;
 getline(cin,address);
 setAddress(address,&s);
 cout<<"\n Address of student is:="<<getAddress(s);


 cout<<"\n Enter the prn of student:="<<endl;
 cin>>x;
 setPrn(x,&s);
 result=getPrn(s);
 cout<<"\n Id of student is:="<<result;



 cout<<"\n Enter the marks of student:="<<endl;
 for(i=0;i<5;i++)
 {
  cout<<"\n mark of student is:="<<getMark(s,i);
 }

 return 0;
}
