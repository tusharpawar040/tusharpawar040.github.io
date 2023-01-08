#include<bios.h>
#include<conio.h>
#include<stdio.h>
#define DATA_READY 0x100
#define TRUE       1
#define FALSE      0
#define SETTINGS 0xA3

void main()
{
   int status, DONE=FALSE,crc[12],i=0,j,k=0,temp[12],arr[8];
   int gen[5]={1,0,0,1,1},asc=0;
   char out;
   clrscr();
   bioscom(0,SETTINGS,0);
   printf("\n\nCRC (Cyclic Redundancy Check - Error Detection & Correction Tech.\n)");
   printf("\n\nReceiving Bits...\n");
   printf("\n\nCRC Frame: ");
   while (!DONE)
   {
      status=bioscom(3,0,0);
      if ((status & DATA_READY)==0x100)
	{
	 out=bioscom(2,0,0);
	 if (out!= '$')
	 {
	  crc[i]=out;
	  temp[i]=out;
	  i++;
	  printf("%d",out);
	 }
	 else
	  DONE = TRUE;
       }
   }
   //EX-ORING
   printf("\n\nDividing the generator frame, Remainder is: ");
   k=0;
   for(i=0;i<5;i++)
    {
      if(temp[i]==1)
	{
	   for(j=i;j<i+5;j++)
	      {
		temp[j]=temp[j]^gen[k];
		k++;
	      }
	}
     k=0;
   }
   k=0;
   for(i=8;i<12;i++)
   {
    printf("%d",temp[i]);
    if(temp[i]==0)
     k++;
    else
     k=0;
   }
   if(k==4)
   {
    printf("\n\nCRC Frame received correctly");
    printf("\n\n Original Frame is: ");
    for(i=0;i<8;i++)
    {
     arr[i]=crc[i];
     printf("%d",crc[i]);
    }
   }
   else
    {
     printf("\n\nFrame received with errors");
     getch();
    }

   for(i=6;i>=0;i--)
    asc+=(arr[i]*pow(2,i));
   printf("\n\nThe equivalent Character for above binary frame is: ");
   printf("%c",asc);
getch();
}