#include<stdio.h>
main()
{
  int a,b,c,d,e,f,j,i;
/*  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);*/
  scanf("%d",&a);
  for (i=1;i<=a;i++)
  {
   getchar();
   scanf("%d",&b);
   scanf("%d",&c);
   for(j=1;j<=c;j++)
   {  
		 for (d=1;d<=b;d++)
		 {
			 for (e=1;e<=d;e++)
				 printf("%d",d);
			 putchar('\n');
		 }
		 for (d=b-1;d>=1;d--)
	   {
		   for (e=1;e<=d;e++)
			printf("%d",d);
		    putchar('\n');
	   }
		 if(i!=a) putchar('\n');
		 else if (j!=c) putchar('\n');
    }
  }
  return 0;
}
