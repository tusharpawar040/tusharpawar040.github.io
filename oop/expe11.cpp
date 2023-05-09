#include<iostream>
#include<string.h>
using namespace std;
class date
{
	int dd;
	int mm;
	int yy;
 public:
	date()
	{
		dd=0;
		mm=0;
		yy=0;
	}
	void setDay(int n);
	void setMonth(int n);
	void setYear(int n);
	int getDay();
	int getMonth();
	int getYear();
	int isLeapYear(int y);
	int setDate(int d,int m,int y);
};
class person
{
	int ID;
	string name;
public:
	person()
	{
		ID=0;
		name="null";
	}
	void setId(int a);
	void setName(string a);
	int getId();
	string getName();
};
void date::setDay(int n)
{
	dd=n;
}
void date::setMonth(int n)
{
	mm=n;
}
void date::setYear(int n)
{
	yy=n;
}
int date::getDay()
{
	return dd;
}
int date::getMonth()
{
	return mm;
}
int date::getYear()
{
	return yy;
}
int date::isLeapYear(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
		return 1;
	return 0;
}
int date::setDate(int d,int m,int y)
{
	int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(y<1800||y>2050)
		throw "invalid date as entered year is incorrect\n";
	if(m<1||m>12)
		throw "invalid date as entered month is incorrect\n";
	if(m==2)
	{	
		if(isLeapYear(y))
			mdays[1]=29;
	}
	if(d<1||d>mdays[m-1])
		throw "invalid date as entered day is incorrect\n";
	setDay(d);
	setMonth(m);
	setYear(y);
	return 1;
}
void person::setId(int a)
{
	ID=a;
}
void person::setName(string a)
{
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]==32)
			throw "enter something";
		if(a[i]<65||a[i]>122)
			throw "only letters are acceptable\n";
		if(a[i]>90&&a[i]<97)
			throw "only letters are acceptable\n";
	}
	name=a;
}
int person::getId()
{
	return ID;
}
string person::getName()
{
	return name;
}
int main()
{
	int option;
	do
	{
		cout<<"1.store date 2.store person name 3.exit\nenter your option: ";
		cin>>option;
		switch(option)
		{
			case 1:{	date dt;
					int d,m,y;
					cout<<"enter date in the form dd mm yy:";
					cin>>d>>m>>y;
					try
					{
						dt.setDate(d,m,y);
						cout<<"date stored successfully\n"<<endl;
					}
					catch(const char* msg)
					{
						cout<<msg<<endl;
					}
					break;
				}
			case 2:{	person p;
					string a;
					cout<<"enter name of person: ";
					cin>>a;
					try
					{
						p.setName(a);
						cout<<"person's name stored successfully\n"<<endl;
					}
					catch(const char* msg)
					{
						cout<<msg<<endl;
					}
					break;
				}
		}
	}while(option<3);
	return 0;
}
