#include<cstdio>
#include<cstring>
#define inf 0x7f 
#define min(a,b) a<b?a:b
int chop[5001];
int dp[1002][5002];
int GW(int i,int j)
{
	return (chop[i]-chop[j])*(chop[i]-chop[j]);
}
main()
{
	int T;
	int k,n;
	scanf("%d",&T);
	while (T--)
	{
		memset(dp,inf,sizeof(dp));
		scanf("%d%d",&k,&n);	
		for (int i=n-1;i>=0;i--)
			scanf("%d",&chop[i]);
		for (int i=0;i<=n;i++) dp[0][i]=0;
		for (int i=1;i<=k+8;i++)
		for (int j=i*3-1;j<n;j++)
			dp[i][j]=min(dp[i][j-1],dp[i-1][j-2]+GW(j,j-1));	
		printf("%d\n",dp[k+8][n-1]);
	}
	return 0;
}
