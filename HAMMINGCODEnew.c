//hamming_code_receiver
#include<stdio.h>
int main()
{
     int h[12],p[4],n=0,i=0;
     printf("Enter the hamming code\n");
     for(i=0;i<12;i++)
     {
         scanf("%d",&h[i]);
     }
     p[0]=h[0]^h[2]^h[4]^h[6]^h[8]^h[10];
     p[1]=h[1]^h[2]^h[5]^h[6]^h[9]^h[10];
     p[2]=h[3]^h[4]^h[5]^h[6]^h[11];
     p[3]=h[7]^h[8]^h[9]^h[10]^h[11];
     printf("Parity bit is %d %d %d %d\n",p[0],p[1],p[2],p[3]);
     int decimal;
     decimal=p[3]*8+p[2]*4+p[1]*2+p[0]*1;
     if(decimal==0)
     {
         printf("data is correct\n");
     }
     else
     {
         printf("data is not correct at %d bit error is occur\n",decimal);
         if(h[decimal-1]==0)
         {
             h[decimal-1]=1;
         }
         if(h[decimal-1]==1)
         {
             h[decimal-1]=0;
         }
     }
     printf("correct codeword is \n");
     for(n=0;n<12;n++)
     {
         printf("%d",h[n]);
     }
}