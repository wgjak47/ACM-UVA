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
char s[1100];
int dp[1010];
bool check(int l,int r)
{
	while (l<=r)
	{
		if (s[l]!=s[r])
			return false;
		l++;r--;
	}
	return true;
}
int dfs(int l,int r)
{
	if (l==r) return 1;
	if (dp[r]!=-1) return dp[r];
	dp[r]=1e8;
	int &ans=dp[r];
	for (int i=l;i<=r;i++)
		if (s[i]==s[r])
		{
			if (check(i,r))
				ans=min(ans,dfs(l,i-1)+1);
		}
	return ans;
}
main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);
		memset(dp,-1,sizeof(dp));
		int l=strlen(s);
		printf("%d\n",dfs(0,l-1));
	}
	return 0;
}
