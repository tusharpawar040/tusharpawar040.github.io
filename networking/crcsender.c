#include<stdio.h>
 int main(){

int divisor[50], dataword [50], codeword[50]; int div,data,code;
int i,j,k;
//INPUT

printf("ENTER no. of digits of DIVISER : ");

scanf("%d", &div);

printf("ENTER %d digits of DIVISER :",div);

for( i=0; i<div; i++)

scanf("%d",&divisor[i]);

printf("\nENTER no. of digits of DATAWORD :");

scanf("%d",&data);

printf("ENTER %d digits of DATAWORD :",data);

for( i=0; i<data; i++) scanf("%d",&dataword[i]);

// DATA PLUS EXTRA ZERO

for( i=data; i<data+div-1; i++)

dataword[i]=0;

for( i=0; i<data; i++) codeword[i]=dataword[i];

data=data+div-1;


for( i=0; i<-data-div;i++){
 if(dataword[i]!=1)
continue;

else{

 k=0;

for(j=i;j<i+div;j++)
{

dataword[j]=divisor [k]^dataword[j]; k++;
}}}//OUTPUT

for ( i=data-div+1; i<data; i++){
  codeword[i]=dataword[i];

printf("%d",codeword[i]);}

printf("\nCODEWORD : "); for( i=0; i<data; i++) printf("%d",codeword[i]);
}