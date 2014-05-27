#include<cstdio>
#include<cstring>
main()
{
	int N;
	int dp[32];
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	dp[1]=0;
	dp[2]=3;
	for (int i=3;i<=30;i++)
	{
		for (int j=2;j<i;j+=2)
		if (j!=2)
			dp[i]+=dp[i-j]*2;
		else dp[i]+=dp[i-j]*3;
		if (i%2==0) dp[i]+=2;
	}
	while (scanf("%d",&N)==1,N!=-1)
	printf("%d\n",dp[N]);
	return 0;
}
