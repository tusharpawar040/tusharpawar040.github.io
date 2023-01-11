#include<stdio.h>
int power(int,int);
int bin_to_dec(int);
int dec_to_bin(int);
void main()
{
    int ip[4],prefix,n,first[4],last[4],i;
    printf("Enter addres and prefix length(in slash notation):\n");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3],&prefix);
    if(prefix>=8)
    {
        first[0]=last[0]=ip[0];
        first[2]=first[3]=0;
        last[2]=last[3]=255;
        i=1;
        n=16-prefix;
    }
    if(prefix>=16)
    {
        first[1]=last[1]=ip[1];
        first[3]=0;
        last[3]=0;
        i=2;
        n=24-prefix;
    }
    if(prefix>=24)
    {
        first[2]=last[2]=ip[2];
        i=3;
        n=32-prefix;
    }
    first[i]=dec_to_bin(ip[i]);
    first[i]=first[i]/power(10,n);
    first[i]=first[i]*power(10,n);
    first[i]=bin_to_dec(first[i]);
    last[i]=dec_to_bin(ip[i]);
    last[i]=last[i]/power(10,n);
    for(int j=1;j<=n;j++)
    last[i]=last[i]*10+1;
    last[i]=bin_to_dec(last[i]);
    printf("First address....last address");
    printf("\n%d.%d.%d.%d.......",first[0],first[1],first[2],first[3]);
    printf("%d,%d.%d.%d",last[0],last[1],last[2],last[3]);
   
}
int power(int x,int y)
{
    int power=1,i;
    for(i=1;i<=y;++i)
    power=power*x;
    return power;
}
int bin_to_dec(int n)
{
    int dec=0,i=0,rem;
    while(n!=0)
    {
        rem=n%10;
        n/=10;
        dec+=rem*power(2,i);
        ++i;

    }
    return dec;
}
int dec_to_bin(int n)
{
    int rem,bin=0,i=1;
    while(n!=0)
    {
        rem=n%2;
        n/=2;
        bin+=rem*1;
        i*=10;
    }
    return bin;
}