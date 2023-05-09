#include<iostream>
using namespace std;
class complex
{
	float real;
	float img;
public:
	complex()
	{
		real=0;
		img=0;
	}
	complex(float a,float b)
	{
		real=a;
		img=b;
	}
	void setReal(float a);
	void setImg(float a);
	float getReal();
	float getImg();
	complex operator +(complex kc);
	complex operator -(complex kc);
	void operator ++();
};

void complex::setReal(float a)
{
	real=a;
}
void complex::setImg(float a)
{
	img=a;
}
float complex::getReal()
{
	return real;
}
float complex::getImg()
{
	return img;
}
complex complex::operator +(complex kc)
{
	complex c;
	c.real=real+kc.real;
	c.img=img+kc.img;
	return c;
}
complex complex::operator -(complex kc)
{
	complex c;
	c.real=real-kc.real;
	c.img=img-kc.img;
	return c;
}

int main()
{
	complex c1,c2(5,6),c3,c4;
	c1.setReal(3);
	c1.setImg(5);
	c3=c1+c2;
	c4=c1-c2;
	cout<<"addition is: "<<c3.getReal()<<"+"<<c3.getImg()<<"i"<<endl;
	cout<<"subtraction is: "<<c4.getReal()<<"+"<<c4.getImg()<<"i"<<endl;
}

