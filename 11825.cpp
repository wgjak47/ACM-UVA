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
const int maxn=(1<<16)+10;
int cover[maxn],P[maxn],f[maxn];
main()
{
	int n,kase=0;
	while (scanf("%d",&n)==1)
	{
		if (n==0) break;
		for (int i=0;i<n;i++)
		{
			int m,x;
			scanf("%d",&m);
			P[i]=1<<i;
			while (m--)
			{
				scanf("%d",&x);
				P[i]|=(1<<x);
			}
		}
		for (int S=0;S<(1<<n);S++)
		{
			cover[S]=0;
			for (int i=0;i<n;i++)
				if (S&(1<<i)) cover[S]|=P[i];
		}
		f[0]=0;
		const int ALL=(1<<n)-1;
		for (int S=1;S<(1<<n);S++)
		{
			f[S]=0;
			for (int S0=S;S0;S0=(S0-1)&S)
				if (cover[S0]==ALL) 
					f[S]=max(f[S],f[S^S0]+1);
		}
		printf("Case %d: %d\n",++kase,f[ALL]);
	}
	return 0;
}
