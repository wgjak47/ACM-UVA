//递推 ans=dp[N-1]+dp[N];
//dp[N]=dp[N-3]+dp[N-2];
#include<cstdio>
#include<cstring>
int dp[100];
int solve(int N)
{
	if (N<=0) return 0;
	if (N<=3) return 1;
	if (dp[N]!=-1) return dp[N];
	dp[N-3]=solve(N-3);dp[N-2]=solve(N-2);
	return dp[N-3]+dp[N-2];
}
main()
{
	int N;
	memset(dp,-1,sizeof(dp));
	while (scanf("%d",&N)==1)
	{
		printf("%d\n",solve(N)+solve(N-1));
	}
	return 0;
}
