#include<stdio.h>
#include<string.h>
#include<math.h>
main()
{
	char s[100];
	int i,j=1,k=256,l,m,n,sum;
	while(gets(s)!=NULL)
	{
		sum=0;k=256;j=1;
		if (s[0]!='_' && strlen(s)==11)
		{
		for (i=1;i<=5;i++)
		{
		k/=2;
		if (s[i]=='o')
			sum+=k;
		}
		for(i=9;i>=7;i--)
		{
		j*=2;
		if (s[i]=='o')
		sum+=j/2;
		}
		printf("%c",sum);
		}
	}
	return 0;
}
