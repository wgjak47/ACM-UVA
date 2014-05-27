#include<stdio.h>
#include<string.h>
char s[200];
int next(int x)
{
	int i=x+1;
	while (s[i]=='*') i++;
	return i;
}
main()
{
	int i,j,k,l,m,n,yes,o,flag;
	scanf("%d",&n);
	getchar();
	for (o=0;o<n;o++)
	{
		yes=1;flag=1;
		gets(s);
		l=strlen(s);
		if (l!=0)
		{	
		for (j=0;j<l;j++)
		{
			if (s[j]=='[' && s[k=next(j)]==']')
			{
				s[j]='*';
				s[k]='*';
				flag=0;
			}
			if (s[j]=='(' && s[k=next(j)]==')')
			{
				s[j]='*';
				s[k]='*';
				flag=0;
			}
			if (j==l-1) 
			{
			  j=-1;
			  if (flag) break;
		      flag=1;
			}	  
		}
		for (i=0;i<l;i++)
			if (s[i]!='*')
			{
				yes=0;
				break;
			}
		if (yes) printf("Yes\n");
		else printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}
