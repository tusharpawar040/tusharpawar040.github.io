#include<stdio.h>

int main(){


int divisor[50], codeword[50], dataword[50]; int div,data,code,i;

//INPUT

printf("ENTER no. of digits of DIVISER : "); scanf("%d", &div); printf("ENTER %d digits of DIVISER :",div);

for(i=0; i<div; i++) scanf("%d",&divisor[i]);

printf("\nENTER no. of digits of CODEWORD :");

scanf("%d", &code); printf("ENTER %d digits of CODEWORD",code);

for(i=0; i<code; i++) scanf("%d", &codeword[i]);
for (i=0; i<-code-div; i++) dataword[i]=codeword[i];

for(i=0; i<=code-div; i++) {

if(codeword[i]-1) continue;

else{

int k=0;

for(int j=i; j<i+div; j++){ codeword[j]-divisor[k]^codeword[j];

k++;
}}}
for (i=0; i<code; i++) { 
if (codeword[i]==1)
{ printf("\nDATAWORD DISCARDED");
 break;
} }
if(i==code) {

printf("DATAWORD ACCEPTED\nDATAWORD: "); 
for(int j=0; j<=code-div; j++)
 printf("%d ", dataword[j]);
}}