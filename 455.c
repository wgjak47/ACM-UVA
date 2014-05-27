#include<stdio.h>
#include<string.h>
main()
{
	int a,b,c,d,e,j,l,i;
	char m;
	a=0;
/*	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); */
	while((m=getchar())>0)
	{
		if (m>='0'&&m<='9')
          a=a+m-48;
	    if (m=='b')
		{
			for (i=1;i<=a;i++)
				putchar(' ');
			a=0;
		}
		if (m<='Z'&& m>='A' || m=='*')
		{
         	for (i=1;i<=a;i++)
          putchar(m);
			a=0;
		}
		if (m=='\n' || m=='!')
			putchar('\n');
/*		if (m==' ')
			putchar('\n');*/

	}
return 0;
}
