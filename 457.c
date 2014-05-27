#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int n,d[100]={0},y[100]={0},t[100]={0},i,j,k,l,m;
      
        while(scanf("%d",&n)>0)
	{
          for (m=1;m<=n;m++)
	{
   	   for (i=0;i<10;i++)
	   scanf("%d",&d[i]);
	   memset(t,0,sizeof(t));
	   	t[20]=1;
	for (l=0;l<50;l++)
	{
	   	for (j=1;j<=40;j++)
	   switch (t[j])
	   {
		   case 0:printf(" ");break;
		   case 1:printf(".");break;
		   case 2:printf("x");break;
		   case 3:printf("W");break;
		   default:break;
	   }	  
	   putchar('\n');
	   memcpy(y,t,sizeof(y));
           for (j=2;j<=40;j++)
	   t[j]=d[y[j]+y[j-1]+y[j+1]];
	   t[1]=d[y[1]+y[2]];
	}
       if (m<n) putchar('\n');
	}
        }
	 return 0;
}
