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
using namespace std;
int dp[80][80];
int solve(int n,int k)
{
	if (n==1) return 1;
	if (k==0) return 1;
	if (dp[n][k]!=-1) return dp[n][k];
	dp[n][k]=0;
	for (int i=0;i<=k;i++)
		dp[n][k]+=solve(n-1,i);
	return dp[n][k];
}
main()
{
	int K;
	cin>>K;
	memset(dp,-1,sizeof(dp));
	while (K--)
	{
		int N,T,P;
		scanf("%d%d%d",&N,&T,&P);
		int k=T-N*P;
		if (k<0) 
		{
			printf("0\n");
			continue;
		}
		else
		printf("%d\n",solve(N,k));
	}
	return 0;
}
