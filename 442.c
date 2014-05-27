#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct matrix
{
	int x,y;
}; 
struct matrix sm[900],stack[900];
main()
{
	char c;
	long long  switch1,switch2,aswitch;
	long long  n; char s[9000];
	long long  i,j,k,l,m,error,sum;
    scanf("%lld",&n);
	getchar();
	for (i=0;i<n;i++)
	{
		c=getchar();
		scanf("%d%d",&sm[c].x,&sm[c].y);
		getchar();
	}
	while (gets(s)!=NULL)
	{
		l=strlen(s);error=0;
		k=0;sum=0;
		for (i=0;i<l;i++)
		{
			if (isalpha(s[i]))
				stack[k++]=sm[s[i]];
			if (s[i]==')')
			{
				if (stack[k-1].x==stack[k-2].y)
				{
					sum+=stack[k-1].y*stack[k-1].x*stack[k-2].x;
					stack[k-2].y=stack[k-1].y;
					k--;
				}
				else 
				{
					error=1;
					break;
				}
			}
		}
			if (!error) printf("%lld\n",sum);
			else printf("error\n");
	}
		return 0;
}
