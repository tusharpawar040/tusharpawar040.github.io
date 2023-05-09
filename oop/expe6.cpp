#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.142
class line
{
	int x1;
	int x2;
	int y1;
	int y2;
	float slope;
	float intercept;
public:
	line()
	{
		x1=0; x2=0; y1=0; y2=0;
		slope=0;
		intercept=0;
	}
	line(int a,int b,int c,int d)
	{
		x1=a; x2=b; y1=c; y2=d;
		slope=0;
		intercept=0;
	}
	void setp1(int x1,int y1);
	void setp2(int x2,int y2);
	int getp1x();
	int getp1y();
	int getp2x();
	int getp2y();
	float getSlope();
	float getIntercept();
	void calcSlope();
	void calcIntercept();
};
class circle
{
	int cx;
	int cy;
	int radius;
	float circumference;
	float area;
public:
	circle()
	{
		cx=0; cy=0;
		radius=0;
	}
	circle(int a,int b)
	{
		cx=a; cy=b;
		radius=0;
	}
	circle(int a,int b,int r)
	{
		cx=a; cy=b;
		radius=r;
	}
	void setradius(int r);
	int getcenterx();
	int getcentery();
	int getradius();
	void calcArea();
	void calcCircumference();
	float getArea();
	float getCircumference();
	int isTangent(int x1,int x2,int y1,int y2);
	int isTangent(int slope,int intercept);
	int isTangent(line l);
};

void circle::setradius(int a)
{
	radius=a;
}
int circle::getcenterx()
{
	return cx;
}
int circle::getcentery()
{
	return cy;
}
int circle::getradius()
{
	return radius;
}
void circle::calcArea()
{
	area=PI*radius*radius;
}
void circle::calcCircumference()
{
	circumference=2*PI*radius;
}
float circle::getArea()
{
	return area;
}
float circle::getCircumference()
{
	return circumference;
}
int circle::isTangent(int x1,int x2,int y1,int y2)
{
	int d;
	float slope,intercept;
	slope=(y2-y1)/(x2-x1);
	intercept=y1-(x1*slope);
	d=(-1*slope*x1+y1-intercept)/sqrt(slope*slope+1*1);
	if(d<0)
		d=-d;
	if(d==radius)
		return 1;
	else
		return 0;
}
int circle::isTangent(int slope,int intercept)
{
	int d,c;
	c=cy-slope*cx;
	d=(c-intercept)/sqrt(slope*slope+1*1);
	if(d<0)
		d=-d;
	if(d==radius)
		return 1;
	else
		return 0;
}
int circle::isTangent(line l)
{
	int d;
	l.calcSlope();
	l.calcIntercept();
	d=(-1*l.getSlope()*l.getp1x()+l.getp1y()-l.getIntercept())/sqrt(l.getSlope()*l.getSlope()+1*1);
	if(d<0)
		d=-d;
	if(d==radius)
		return 1;
	else
		return 0;
}
void line::setp1(int a,int b)
{
	x1=a; 
	y1=b;
}
void line::setp2(int a,int b)
{
	x2=a; 
	y2=b;
}
int line::getp1x()
{
	return x1;
}
int line::getp1y()
{
	return y1;
}
int line::getp2x()
{
	return x2;
}
int line::getp2y()
{
	return y2;
}
float line::getSlope()
{
	return slope;
}
float line::getIntercept()
{
	return intercept;
}
void line::calcSlope()
{
	slope=(y2-y1)/(x2-x1);
}
void line::calcIntercept()
{
	intercept=y1-(x1*slope);
}

int main()
{
	circle c(0,0,5);
	line l(1,5,-1,5);
	cout<<"center of a circle is: ("<<c.getcenterx()<<","<<c.getcentery()<<")"<<endl;
	cout<<"center of a circle is: "<<c.getradius();
	c.calcArea();
	cout<<"area of the circle is: "<<c.getArea()<<endl;
	c.calcCircumference();
	cout<<"Circumference of the circle is: "<<c.getCircumference()<<endl;
	
}

