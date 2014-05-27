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
LLD dp[30][200];
LLD find(int n,int x)
{
	if (n==1) return x<=6?x:6;
	if (dp[n][x]!=-1) return dp[n][x];
	dp[n][x]=0;
	pf(i,1,7)
		if (x>i)
		dp[n][x]+=find(n-1,x-i);
	return dp[n][x];
}
LLD gcd(LLD a,LLD b)
{
	return b==0?a:gcd(b,a%b);
}
main()
{
	int x,n;
	memset(dp,-1,sizeof(dp));
	while (scanf("%d%d",&n,&x)==2)
	{
		if (n==0 && x==0) break;	
		x--;
		LLD fm=1;
		pf(i,0,n) fm*=6;
		LLD fz=1;
		if (x>0)
			fz=find(n,x);
		else fz=0;
		LLD z=gcd(fm-fz,fm);
		if (fm-fz==0)
			printf("0\n");
		else if (fm-fz==fm)
			printf("1\n");
		else
		printf("%lld/%lld\n",(fm-fz)/z,fm/z);
	}
	return 0;
}
