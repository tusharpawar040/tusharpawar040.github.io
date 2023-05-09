#include<iomanip>
#include<iostream>
using namespace std;

int main()
{
 string movieName;
 float adultPrice,childPrice;
 int adultTicket,childTicket;
 float totalPrice,gross,amountD,netSale,perDonate;
 int totalTicket;

 cout<<"\n Enter Movie Name:";
 getline(cin,movieName);

 cout<<"\n Number of Adult Ticket's are:";
 cin>>adultTicket;
 cout<<"\n Number of Child Ticket's are:";
 cin>>childTicket;

 cout<<"\n Ticket Price for Adult is:";
 cin>>adultPrice;
 cout<<"\n Ticket Price for Child is:";
 cin>>childPrice;

 totalTicket=adultTicket+childTicket;
 totalPrice=adultPrice+childPrice;

 gross=adultTicket*adultPrice+childTicket*childPrice;

 cout<<"Percentage of GrossAmount Donated:";
 cin>>perDonate;

 amountD=gross*(perDonate/100);
 netSale=gross-amountD;

 cout<<setw(35)<<left<<setfill('.')<<"Movie Name:"<<setw(16)<<right<<setfill(' ')<<movieName<<endl;

 cout<<setw(35)<<left<<setfill('.')<<"Number of Ticket's Sold:"<<setw(10)<<right<<setfill(' ')<<totalTicket<<endl;

 cout<<setw(35)<<left<<setfill('.')<<"Gross Amount:"<<" $ "<<gross<<endl;

 cout<<"Percentage of Gross Amount Donated:"<<setw(7)<<left<<setfill(' ')<<right<<perDonate<<("%")<<endl;

 cout<<setw(35)<<left<<setfill('.')<<"Amount Donated:"<<" $ "<<amountD<<endl;

 cout<<setw(35)<<left<<setfill('.')<<"Net Sale:"<<" $ "<<netSale<<endl;

 return 0;

}
