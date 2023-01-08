#include<stdio.h>
#include<string.h>
struct product
{
	char pname[20];
	int Price;
};

void main(){

FILE *fp;
fp=fopen("product.txt","w");

struct product p[5];

for(i=0;i<5;i++)
{
	printf("\n Enterr name of product=");
	scanf("%s",&P[i].pname);
	printf("\n Enterr price of product=");
	scanf("%d",&P[i].Price);
	fprintf(fp,"%s\n%d\n",P[i].P[name],P[i].Price);
}

FILE *temp;

temp=fopen("temp.txt","W");

while(fscanf(FP,"%s%d",&p[0].pname,&p[0].Price)!=eof);
{
	if(strcmp[p[0].pname,name!=0)
	{
		fprintf(temp,"%s\n%d",p[0].pname,p[0].Price);
	}
}
remove("product.txt");
rename("temp.txt","product.txt");
return;
}
