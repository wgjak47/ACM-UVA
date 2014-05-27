#include<cstdio>
#include<cstring>
#define MOD 1000000
long long  dp[101][101];
main()
{
	int M,N;
	for (int i=0;i<=100;i++) dp[0][i]=1;
	for (int i=1;i<=100;i++)
	for (int k=1;k<=100;k++)
	{
		dp[i][k]=(dp[i][k-1]%MOD+dp[i][k]%MOD)%MOD;
		for (int j=1;j<=100;j++)
		if (i-j>=0)
		dp[i][k]=(dp[i-j][k-1]%MOD+dp[i][k]%MOD)%MOD;		
		else break;
	}
	while (scanf("%d%d",&M,&N)==2)
	{
		if (M==N && N==0) break;
		printf("%lld\n",dp[M][N]%MOD);
	}	
	return 0;
}
