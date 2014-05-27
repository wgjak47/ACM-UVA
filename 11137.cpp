#include<cstdio>
#include<cstring>
int coin[30];
long long dp[10000];
main()
{
	int N;
	for (int i=1;i<22;i++)
		coin[i]=i*i*i;
	while (scanf("%d",&N)==1)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for (int i=1;i<22;i++)
		for (int j=1;j<=N;j++)
		if (j-coin[i]>=0)
			dp[j]+=dp[j-coin[i]];	
		printf("%lld\n",dp[N]);
	}
	return 0;	
}
