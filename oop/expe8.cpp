#include<iostream>
using namespace std;
#define con 5
class matrix
{
	int *q;
	int rows;
	int cols;
public:
	matrix()
	{	q=new int[con*con];
		rows=con;
		cols=con;
	}
	matrix(int r,int c)
	{
		q=new int[r*c];
		rows=r;
		cols=c;	
	}
	friend void operator <<(ostream& cout, matrix& km);
	friend void operator >>(istream& cin, matrix& km);
	matrix operator +(matrix& km);
	matrix operator -(matrix& km);
	matrix operator *(matrix& km);
};
void operator <<(ostream& cout, matrix& km)
{
	for(int i=0;i<km.rows;i++)
	{
		for(int j=0;j<km.cols;j++)
			cout<<*(km.q+i*km.cols+j)<<"\t";
		cout<<endl;
	}
}
void operator >>(istream& cin, matrix& km)
{
	for(int i=0;i<km.rows;i++)
		for(int j=0;j<km.cols;j++)
			cin>>*(km.q+i*km.cols+j);
			
}
matrix matrix::operator +(matrix& km)
{	matrix m(km.rows,km.cols);
	for(int i=0;i<km.rows;i++)
	{
		for(int j=0;j<km.cols;j++)
		{
			*(m.q+i*m.cols+j)=*(q+i*cols+j)+*(km.q+i*km.cols+j);
		}
	}
	return m;
}
matrix matrix::operator -(matrix& km)
{
	matrix m(km.rows,km.cols);
	for(int i=0;i<km.rows;i++)
	{
		for(int j=0;j<km.cols;j++)
		{
			*(m.q+i*m.cols+j)=*(q+i*cols+j)-*(km.q+i*km.cols+j);
		}
	}
	return m;
}
matrix matrix::operator *(matrix& km)
{	matrix m(rows,km.cols);
	int ans=0;
	for(int i=0;i<m.rows;i++)
	{
		for(int j=0;j<m.cols;j++)
		{
			for(int p=0;p<cols;p++)
			{
				for(int t=0;t<km.rows;t++)
				{
					ans+=(*(q+i*m.cols+p))*(*(km.q+t*km.cols+j));
				}
				
			}
			*(m.q+i*m.cols+j)=ans;
			ans=0;
		}	
	}
	return m;
}
int main()
{
	int rows,cols;
	cout<<"enter rows and cols of matrix:";
	cin>>rows>>cols;
	matrix m1(rows,cols),m2(rows,cols),m3(rows,cols);
	cin>>m1;
	cout<<"enter m2:";
	cin>>m2;
	m3=m1+m2;
	cout<<"addition is:"<<endl;
	cout<<m3;
	m3=m1-m2;
	cout<<"subtraction is:"<<endl;	
	cout<<m3;
	m3=m1*m2;
	cout<<"multiplication is:"<<endl;
	cout<<m3;	
	return 0;
}
