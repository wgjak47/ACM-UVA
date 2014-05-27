#include<cstdio>
#include<cstring>
long long dp[13][13][13];
long long dfs(int N,int P,int R)
{
	if (N==P&& P==R && R==1) return 1;
	if (P==R && R==1) return 0;
	if (P==0 || R==0) return 0;
	if (N<P+R-1) return 0;
	return dp[N][P][R]=dfs(N-1,P,R)*(N-2)+dfs(N-1,P-1,R)+dfs(N-1,P,R-1);
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,P,R;
		scanf("%d%d%d",&N,&P,&R);
		printf("%lld\n",dfs(N,P,R));
	}
	return 0;
}
