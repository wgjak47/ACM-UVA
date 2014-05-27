#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x,i,j,k;
char s[60];
char c;
int judge(int l)
{
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
	int l;
	while (scanf("%s",s),s[0]!='#')
	{
		l=strlen(s);
		if (judge(l))
		{
			for (i=x;i>k;i--)
				s[i]=s[i-1];
				s[k]=c;
				qsort(s+k+1,l-k-1,sizeof(char),cmp);
				puts(s);
		}
		else printf("No Successor\n");
	}
	return 0;
}	
