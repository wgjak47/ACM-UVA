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
char s[310];
int d[310][310];
const int mod=1e9;
int dp(int start,int end)
{
	if (start==end) return 1;
	else if (s[start]!=s[end]) return 0;
	int &ans=d[start][end];
	if (ans>=0) return ans;
	ans=0;
	for (int k=start+2;k<=end;k++)
		if (s[start]==s[k])
			ans=(ans+1LL*dp(start+1,k-1)*dp(k,end))%mod;
	return ans%mod;
}
main()
{
	while (gets(s)!=NULL)
	{
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(0,strlen(s)-1));
	}
	return 0;
}
