#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)<(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
bool dp[450*51][51];
int p[110];
int sum[110];
main()
{
	int T;
	while (T--)
	{
		scanf("%d\n",&n);
		memset(dp,0,sizeof(dp));
		int k=n/2;
		pf(i,0,n) scanf("%d",&p[i]);
		sort(p,p+i);
		sum[0]=p[0];
		pf(i,1,n) sum[i]=sum[i-1]+p[i];
		pf(i,0,k) 
		pf(j,0,n)
		pf(l,0,sum[j]+1)
		dp[]
	}
	return 0;
}
