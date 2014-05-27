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
#define LL long long
using namespace std;
LL cal(LL n,LL m)
{
	LL ans=1;
	int k=1;
	pf(i,0,n) 
	{
		ans*=m-i;
		ans/=k++;
	}
	return ans;
}
LL C(LL m,LL n)
{
	double ans=1;
	for (int i=0;i<m;i++)
		ans*=n-i;
	for (int i=0;i<m;i++)
		ans/=i+1;
	return (LL)(ans+0.5);
}
const int maxn=30+5;
LL f[maxn];
LL d[maxn][maxn];
int main()
{
	int n;
	f[1]=1;
	memset(d,0,sizeof(d));
	pf(i,0,31) d[i][0]=1;
	pf(i,1,31) d[i][1]=1,d[0][i]=0;
	pf(i,1,31) 
	{
		pf(j,2,31) 
		{
			d[i][j]=0;
			for (int p=0;p*i<=j;p++)
			d[i][j]+=C(p,f[i]+p-1)*d[i-1][j-p*i];
		}
		f[i+1]=d[i][i+1];
	}
	while (scanf("%d",&n)==1)
	{
		if (n==0) break;
		printf("%lld\n",n==1?1:2*f[n]);
	}
	return 0;
}
