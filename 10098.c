#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int reg2[20];
void allsort(int l,char *sa,char *s,int now)
{
	int i,j;
	if (now==l)
	{
		for (i=0;i<l;i++)
		printf("%c",sa[i]);
		putchar('\n');
	}
	else for (i=0;i<l;i++)
		if (!i || s[i]!=s[i-1])
		{
			int reg1=0;
			for (j=0;j<now;j++) if (sa[j]==s[i]) reg1++;
			if (reg2[i]>reg1)
			{
				sa[now]=s[i];
				allsort(l,sa,s,now+1);
			}
		}
}
int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}
main()
{
	int i,j,k,l,m,n;
	char s[20];
	char sa[20];
	scanf("%d",&n);
	while (n--)
	{
		getchar();
		scanf("%s",s);
		memset(sa,0,sizeof(sa));
		memset(reg2,0,sizeof(reg2));
		l=strlen(s);
		qsort(s,l,sizeof(char),cmp);
		for (i=0;i<l;i++)
		for (j=0;j<l;j++)
			if (s[i]==s[j]) reg2[i]++;
		allsort(l,sa,s,0);
		 putchar('\n');
	}
	return 0;
}
