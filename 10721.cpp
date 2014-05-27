#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
#define LLD long long
using namespace std;
LLD dp[55][55][55];
LLD search(int n,int k,int m)
{
	if (k==1 && n<=m) return 1;
	else if (k==1) return 0;
	if (dp[n][k][m]!=-1) return dp[n][k][m];
	dp[n][k][m]=0;
	pf(i,1,m+1)
		if (n-i>0)
		dp[n][k][m]+=search(n-i,k-1,m);
	return dp[n][k][m];
}
main()
{
	int n,k,m;
	while (scanf("%d%d%d",&n,&k,&m)==3)
	{
		mt(dp,-1);
		printf("%lld\n",search(n,k,m));
	}
	return 0;
}
