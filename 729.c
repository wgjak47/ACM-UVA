#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[20];
char c;
int k,x;
int judge(int l)
{
	int i,j;
	for (i=l-1;i>0;i--)
	for (j=i-1;j>=0;j--)
		if (s[i]>s[j])
		{
			k=j;
			x=i;
			c=s[i];
			return 1;
		}
	return 0;
}

int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}
main()
{
	int i,j;
	int h,n,total;
/*	freopen("in.txt","r",stdin);*/
	scanf("%d",&total);
	while (total--)
	{
		scanf("%d%d",&n,&h);
		memset(s,0,sizeof(s));
		for (i=0;i<n-h;i++)
			s[i]='0';
		for (i=n-h;i<n;i++)
			s[i]='1';
		puts(s);
		while (judge(n))
		{
			for (i=x;i>k;i--)
				s[i]=s[i-1];
				s[k]=c;
				qsort(s+k+1,n-k-1,sizeof(char),cmp);
				puts(s);
		}
		if (total) putchar('\n');
	}
	return 0;
}
