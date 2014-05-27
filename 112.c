#include<stdio.h>
#include<string.h>
#include<ctype.h>
main()
{
	char c;
	char s[10000];
	int stack[10000];
	int i,j,k,l,m,n,flag,yes;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d",&n)==1)
	{
		i=0;k=1;yes=0;
		while ((c=getchar())!=EOF)
 		{
			if (c==')'||c=='(' || isdigit(c) || c=='-')
				s[i++]=c;
			if (c=='(')  k++;
			else if (c==')')  
			{
				k--;
				if (k==1) break;
			}
		}
		s[i]='\0';l=i;
		s[i+1]=s[i+2]=s[i+3]='\0';
		for (i=0;i<l;i++)
			if (s[i]=='(' && s[i+1]==')')
			{
				s[i+1]=s[i]=' ';
				if (s[i+2]=='('&&s[i+3]==')')
				{
				  s[i+2]='*';
				  s[i+3]=' ';
				}
			}
        j=0;
		for (i=0;i<=l;i++)
			if(s[i]!=' ')
			s[j++]=s[i];
/*		puts(s);*/
		l=strlen(s);
		k=1;flag=0;
		stack[0]=0;
		for (i=0;i<l;i++)
		{
			if (isdigit(s[i]) || s[i]=='-')
			{
				flag=1;
				sscanf(s+i,"%d",&stack[k]);
				k++;
				while (isdigit(s[i+1])) i++;
		/*		printf(" %d ",stack[k-1]);*/
				stack[k-1]+=stack[k-2];
			}
			else if (s[i]==')') k--;
			if (s[i]=='*')
			{
		/*		printf(" aaa%daaa ",stack[k-1]);*/
				if (stack[k-1]==n)
				{
				  yes=1;
				  break;
				}
			}
		}
		if (yes) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
