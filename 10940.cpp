#include<cstdio>
#include<cstring>
int dp[2][500020];
main()
{
	int N;
	dp[0][1]=1;
	dp[0][2]=2;
	dp[0][3]=2;
	dp[1][2]=1;
	dp[1][3]=3;
	for (int i=2;i<=500010/2;i++)
	{
		dp[0][i*2]=dp[0][i]*2;
		dp[1][i*2]=dp[1][i]*2-1;
		dp[1][i*2+1]=dp[0][i+1]*2-1;
		dp[0][i*2+1]=dp[1][i]*2;
	}
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		printf("%d\n",dp[0][N]);
	}
	return 0;
}
