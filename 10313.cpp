#include<cstdio>
#include<cstring>
long long dp[310][310];
main()
{
	int n,l1=-1,l2=-1;
	char s[1000];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=0;i<=300;i++)
	for (int j=1;j<=300;j++)
	{
		if (i-j>=0)
		 dp[j][i]+=dp[j][i-j];
		if (j-1>=0) dp[j][i]+=dp[j-1][i];
	}
	while (gets(s)!=NULL)
	{
		sscanf(s,"%d%d%d",&n,&l1,&l2);
		if (l1>300) l1=300;
		if (l2>300) l2=300;
		if (l1==-1) printf("%lld\n",dp[n][n]);
		else if (l2==-1) printf("%lld\n",dp[l1][n]);
		else if (l1!=0) printf("%lld\n",dp[l2][n]-dp[l1-1][n]);
		else printf("%lld\n",dp[l2][n]);
		l2=l1=-1;
	}
	return 0;
}
