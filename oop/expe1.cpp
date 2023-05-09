#include<iostream>
#include<string>
using namespace std;
struct student
{
	int PRN;
	string name;
	string address;
	int marks[5];
	string grade;
};
struct person
{
	int ID;
	string name;
	string address;
	int age;
};
struct employee
{
	int ID;
	string name;
	string address;
	float grossPay;
	float HRA;
	float TA;
	float netSalary;
};
//student data
void setPRN(int a,struct student*p)
{
	p->PRN=a;
}
int getPRN(struct student p)
{
	return p.PRN;
}
void setName(string a,struct student*p)
{
	p->name=a;
}
string getName(struct student p)
{
	return p.name;
}
void setAddress(string a,struct student*p)
{
	p->address=a;
}
string getAddress(struct student p)
{
	return p.address;
}
void setMarks(int a[],struct student*p)
{
	int i;
	for(i=0;i<5;i++)
		p->marks[i]=a[i];
}
int getMarks(int i,struct student p)
{
	return p.marks[i];
}
string calcGrade(struct student* p)
{
	int sum=0,i;
	float ave;
	for(i=0;i<5;i++)
	{
		sum+=p->marks[i];	
	}
	ave=sum/5;
	if(ave>90)
		p->grade="O";
	if(ave>80)
		p->grade="A";
	else if(ave>70)
		p->grade="B";
	else if(ave>60)
		p->grade="C";
	else if(ave>50)
		p->grade="D";
	else if(ave>40)
		p->grade="E";
	else
		p->grade="f";
	return p->grade;
}
//person's data
void setID(int a,struct person*p)
{
	p->ID=a;
}
int getID(struct person p)
{
	return p.ID;
}
void setName(string a,struct person*p)
{
	p->name=a;
}
string getName(struct person p)
{
	return p.name;
}
void setAddress(string a,struct person*p)
{
	p->address=a;
}
string getAddress(struct person p)
{
	return p.address;
}
void setAge(int a,struct person*p)
{
	p->age=a;
}
int getAge(struct person p)
{
	return p.age;
}
//employee data
void setID(int a,struct employee*p)
{
	p->ID=a;
}
int getID(struct employee p)
{
	return p.ID;
}
void setName(string a,struct employee*p)
{
	p->name=a;
}
string getName(struct employee p)
{
	return p.name;
}
void setAddress(string a,struct employee*p)
{
	p->address=a;
}
string getAddress(struct employee p)
{
	return p.address;
}
void setGrosspay(float a,struct employee*p)
{
	p->grossPay=a;
}
float getGrosspay(struct employee p)
{
	return p.grossPay;
}
void setHRA(float a,struct employee*p)
{
	p->HRA=a;
}
float getHRA(struct employee p)
{
	return p.HRA;
}
void setTA(float a,struct employee*p)
{
	p->TA=a;
}
float getTA(struct employee p)
{
	return p.TA;
}
float calcNetsalary(struct employee* p)
{
	float HRA,TA;
	HRA=(p->grossPay*p->HRA)/100;
	TA=(p->grossPay*p->TA)/100;
	p->netSalary=p->grossPay-(HRA+TA);
	return p->netSalary;
}
int main()
{
	struct student s;
	struct person p;
	struct employee e;
	int x,v,i,b[5];
	float l,m,n;
	string y,z;
	cout<<"enter following information of student:\n";    //taking student info
	cout<<"PRN:";
	cin>>x;
	setPRN(x,&s);
	cout<<"name:";
	cin>>y;
	setName(y,&s);	
	cout<<"address:";
	cin>>z;
	setAddress(z,&s);	
	cout<<"marks of 5 subjects:";
	for(i=0;i<5;i++)
		cin>>b[i];
	setMarks(b,&s);
	cout<<"enter following information of the person:\n";   //taking person info
	cout<<"ID:";
	cin>>x;
	setID(x,&p);
	cout<<"name:";
	cin>>y;
	setName(y,&p);	
	cout<<"address:";
	cin>>z;
	setAddress(z,&p);	
	cout<<"Age:";
	cin>>v;
	setAge(v,&p);
	cout<<"enter following information of the employee:\n";   //taking employee info
	cout<<"ID:";
	cin>>x;
	setID(x,&e);
	cout<<"name:";
	cin>>y;
	setName(y,&e);	
	cout<<"address:";
	cin>>z;
	setAddress(z,&e);	
	cout<<"grosspay:";
	cin>>l;
	setGrosspay(l,&e);
	cout<<"HRA(%):";
	cin>>m;
	setHRA(m,&e);
	cout<<"TA(%):";
	cin>>n;
	setTA(n,&e);		
	cout<<"\nstudent information:"<<"\n\tPRN\t\t"<<getPRN(s)<<endl;	//print student info
	cout<<"\tname\t\t"<<getName(s)<<endl;	
	cout<<"\taddress\t\t"<<getAddress(s)<<endl;
	cout<<"\tmarks\t\t";	
	for(i=0;i<5;i++)
		cout<<getMarks(i,s)<<"\t";
	cout<<endl;
	cout<<"\tgrade\t\t"<<calcGrade(&s)<<endl;
	cout<<"\nperson's information:"<<"\n\tID\t\t"<<getID(p)<<endl;	//print person info
	cout<<"\tname\t\t"<<getName(p)<<endl;	
	cout<<"\taddress\t\t"<<getAddress(p)<<endl;
	cout<<"\tage\t\t"<<getAge(p)<<endl;
	cout<<"\nemployee's information:"<<"\n\tID\t\t"<<getID(e)<<endl;  //print employee info	
	cout<<"\tname\t\t"<<getName(e)<<endl;	
	cout<<"\taddress\t\t"<<getAddress(e)<<endl;
	cout<<"\tgrosspay\t"<<getGrosspay(e)<<endl;
	cout<<"\tHRA\t\t"<<getHRA(e)<<"%"<<endl;
	cout<<"\tTA\t\t"<<getTA(e)<<"%"<<endl;
	cout<<"\tnet salary\t"<<calcNetsalary(&e)<<endl;

}
