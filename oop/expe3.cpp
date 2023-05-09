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
	date(int x)
	{
		dd=0;
		mm=0;
		yy=0;
	}
	date(int x,int y,int z)
	{
		dd=x;
		mm=y;
		yy=z;
	}
	void setDay(int n);
	void setMonth(int n);
	void setYear(int n);
	int getDay();
	int getMonth();
	int getYear();
	int isLeapYear(int y);
	int setDate(int d,int m,int y);
	void increamentDate();
	void display(int n);
	date dateDiff(date d);
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
		return 0;
	if(m<1||m>12)
		return 0;
	if(m==2)
	{	
		if(isLeapYear(y))
			mdays[1]=29;
	}
	if(d<1||d>mdays[m-1])
		return 0;
	setDay(d);
	setMonth(m);
	setYear(y);
	return 1;
}
void date::increamentDate()
{
	int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int n;
	if(isLeapYear(yy))
		mdays[1]=29;
	n=dd;
	n++;
	if(n>mdays[mm-1])
	{
		n-=mdays[mm-1];
		mm++;
		if(mm>12)
		{
			mm=1;
			yy++;
		}	
	}
	dd=n;
	mdays[1]=28;
}
date date::dateDiff(date d)
{
	date ans;
	int mdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	ans.yy=yy-d.yy;
	if(mm<d.mm)
	{
		ans.yy--;
		ans.mm=(12-d.mm)+mm;
		if(dd<d.dd)
		{
			ans.mm--;
			ans.dd=(mdays[d.mm-1]-d.dd)+dd;
		}
		else		
		{
			ans.dd=dd-d.dd;
		}
	}
	else
	{
		ans.mm=mm-d.mm;
		if(dd<d.dd)
		{
			ans.mm--;
			ans.dd=(mdays[d.mm-1]-d.dd)+dd;
		}
		else		
		{
			ans.dd=dd-d.dd;
		}
	}
	return ans;
}
void date::display(int n)
{
	string months[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
	string mmm=months[mm];
	switch(n)
	{
		case 1: cout<<dd<<"-"<<mm<<"-"<<yy<<endl;
			break;
		case 2: cout<<dd<<"-"<<mmm<<"-"<<yy<<endl;
			break;
		case 3: cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
			break;
	}
}

int main()
{
	date d1,d2(5),d3(12,4,2023),d4;
	int d,m,y,status,option,choice;
	do
	{	cout<<"\n1.store the date 2.increament date 3.difference between two days 4.display the date 5.exit\nenter your option:";
		cin>>option;
		switch(option)
		{
			case 1: cout<<"enter date in the form dd mm yy:";
				cin>>d>>m>>y;
				status=d1.setDate(d,m,y);
				if(status==0)
					cout<<"date is invalid\n";
				else
					cout<<"date stored successfully\n";
				break;
			case 2: d1.increamentDate();
				cout<<"increamented date is: ";
				d1.display(3);
				break;
			case 3: cout<<"enter 1st date in the form dd mm yy:";
				cin>>d>>m>>y;
				status=d1.setDate(d,m,y);
				if(status==0)
				{	cout<<"date is invalid\n";
					break;
				}		
				cout<<"enter 2nd date in the form dd mm yy:";
				cin>>d>>m>>y;
				status=d2.setDate(d,m,y);
				if(status==0)
				{	cout<<"date is invalid\n";
					break;
				}
				d4=d1.dateDiff(d2);
				cout<<d4.getYear()<<" years "<<d4.getMonth()<<" months "<<d4.getDay()<<" days\n";
				break;
			case 4: cout<<"1.'dd-mm-yyyy' 2.'dd-mmm-yyyy' 3.'dd/mm/yy'\nenter your option in which you want to display the date:";
				cin>>choice;
				d1.display(choice);
				break;
		}
	}while(option<5);
}
