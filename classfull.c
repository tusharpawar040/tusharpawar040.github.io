//classfull
#include <stdio.h>
int main()
{
 int a,b,c ,d;
     printf("Enter ip address: ");
     scanf("%d.%d.%d.%d",&a,&b,&c,&d);
     if((a>=0&&a<=255)&&(b>=0&&b<=255)&&(c>=0&&c<=255)&&(d>=0&&d<=255))
     { 
       if(a>=0&&a<=127)
{ 
printf("\n Ip address belong to class: A\n");
printf("\n Network Address is: %d",a);
printf("\n Host Address is :%d.%d.%d",b,c,d);
printf("\n Default mass is : 255.0.0.0"); 

}

else if(a>=127&&a<=191)
{ 
printf("Ip address belong to class B\n");
printf("\n Network Address is: %d.%d",a,b);
printf("\n Host Address is :%d.%d",c,d);
printf("\n Default mass is : 255.255.0.0"); 

}
else if(a>=192&&a<=223)
{ 
printf("Ip address belong to class C\n");
printf("\n Network Address is:%d.%d.%d",a,b,c);
printf("\n Host Address is :%d",d);
printf("\n Default mass is : 255.0.0.0"); 

}
else if(a>=224&&a<=239)
{ 
printf("Ip address belong to class D\n");
printf("The IP address is used For multicasting\n");
}
else if (a>=240&&a<=255)
{ 
printf("Ip address belong to class E\n");
printf("The give IP address is used in Future\n");
}
     }
else 
{
printf("The given IP address is invalid\n");
}

     
  return 0;   
}