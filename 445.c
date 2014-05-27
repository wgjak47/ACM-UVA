#include<stdio.h>
main()
{
	char s;
	int i,j,k,l,len,sum=0;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    while((s=getchar())>0)
	{
		if (s>='0' && s<='9')
			sum+=s-48;
		else if (s>='A' && s<='Z' || s=='*')
			{
				for (i=1;i<=sum;i++)
					putchar(s);
				sum=0;
			}
		if (s=='\n' || s=='!')
			putchar('\n');
        if (s=='b')
		{
			for (i=1;i<=sum;i++)
				putchar(' ');
			sum=0;
		}
	}
	return 0;
}
