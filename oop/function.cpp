#include<iostream>
#include<string>
using namespace std;

struct person
{
 int id;
 string name;
 string address;
 int age;
};


int setId(int x,struct person*p)
{
 p->id=x;
}

int getId(struct person p)
{
 return(p.id);
}

int setName(string x,struct person*p)
{
 p->name=x;
}

string getName(struct person p)
{
 return(p.name);
}

int setAddress(string x,struct person*p)
{
 p->address=x;
}

string getAddress(struct person p)
{
 return(p.address);
}

int setAge(int x,struct person*p)
{
 p->age=x;
}

int getAge(struct person p)
{
 return(p.age);
}

int main()
{
 int id;
 struct person p;
 string name,address;
 int age;
 int x;
 int result;



 cout<<"\n Enter the name of person:="<<endl;
 getline(cin,name);
 setName(name,&p);
 cout<<"\n Name of person is:="<<getName(p);


 cout<<"\n Enter the Address of person:="<<endl;
 getline(cin,address);
 setAddress(address,&p);
 cout<<"\n Address of person is:="<<getAddress(p);

 cout<<"\n Enter the id of person:="<<endl;
 cin>>x;
 setId(x,&p);
 result=getId(p);
 cout<<"\n Id of person is:="<<result;


 int r;
 cout<<"\n Enter the Age of person:="<<endl;
 cin>>x;
 setAge(x,&p);
 r=getAge(p);
 cout<<"\n Age of person is:="<<r;


  return 0;
}
