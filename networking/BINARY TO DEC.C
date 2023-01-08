#include<stdio.h>
#include<string.h>
int binary(int n)
{
	int c=0,b,mf=1;
	while(n>0)
	{
		b=n%2;
		n=n/2;
		c=b*mf+c;
		mf=mf*10;
	}
	return c;
}
int decimal(int n)
{
	int dv=0,base=1,rem;
	while(n>0)
	{
		rem=n%10; 
		dv=dv+rem*base; 
		n=n/10; 
		base=base*2; 
	}
	return dv;
}
int  main()
{
	char data[16];
	int a,i,n1,n2,n3,n4;
	printf("Enter 1 :- For converting data from decimal  IP adress to binary IP adress \nEnter 0 :- For converting data from binary IP adress to decimal IP adress \n ");
	scanf("%d",&a);
	getchar();
	if(a==1)
	{
	{
		printf("Enter the IP adress :- ");
				scanf("%s",data);
				sscanf(data,"%d.%d.%d.%d",&n1,&n2,&n3,&n4);
				
	}
		for(i=0;data[i]!='NULL';i++)
		{
				if(!(data[i]=='1' || data[i]=='0' || data[i]=='2' || data[i]=='3' || data[i]=='4' || data[i]=='5' || data[i]=='6' || data[i]=='7' || data[i]=='8' || data[i]=='9' || data[i]=='.'))
		{
			printf("Your data is not valid");
			break;
		}
	 }
	 if(data[i]=='NULL')
	 {
	if
	(n1<=255&&n2<=255&&n3<=255&&n4<=255)
	{
		n1=binary(n1);
		n2=binary(n2);
		n3=binary(n3);
		n4=binary(n4);
	printf("\n Binary IP adress is %d %d %d %d.",n1,n2,n3,n4);	
	}
	else
	{
		printf("\n ERROR !!!! IP adress is wrong please correct it ");
	}
	}
}
    else if(a==0)
	{
	{
		printf("Enter the Binary IP adress :- ");
		gets(data);
		sscanf(data,"%d %d %d %d",&n1,&n2,&n3,&n4);
		for(i=0;data[i]!='\0';i++)
		{
				if(!(data[i]=='1' || data[i]=='0' || data[i]==' '))
		{
			printf("Your data is not valid");
			break;
		}
		}
	}
	if(data[i]=='\0')
	{			
	{
		n1=decimal(n1);
		n2=decimal(n2);
		n3=decimal(n3);
		n4=decimal(n4);
	printf("\nDecimal IP adress is %d.%d.%d.%d",n1,n2,n3,n4);	
	
	}
	

    }
   
}
else
{
	printf("Your choice is wrong");
}
}

