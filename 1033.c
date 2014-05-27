#include<stdio.h>
#include<string.h>
main()
{
	long long maxline=0,i,j,k,l,m,n,s[1010],sum[1010]={0},reg;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		
		scanf("%lld",&reg);
		for (j=1;j<=reg;j++)
			scanf("%lld",&s[j]);
		if (reg>maxline) maxline=reg;
        for (l=1;l<=reg;l++)
			sum[l]+=s[l];
	if (i%2==0) 
	{
		for (m=1;m<maxline;m++)
			printf("%lld ",sum[m]);
		if (maxline>=1) printf("%lld",sum[maxline]);
		maxline=0;
		memset(sum,0,sizeof(sum));	
		putchar('\n');
	}
	}
	if (n%2!=0)
	{
		for (m=1;m<reg;m++)
			printf("%lld ",sum[m]);
	    if (s[1]!=0) printf("%lld",sum[reg]);
		else putchar('\n');
	}
	return 0;
	}
