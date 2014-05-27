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
const int maxn=1e5+10;
int f[100010];
int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
main()
{
	int x,y;
	while (scanf("%d",&x)==1)
	{
		pf(i,0,maxn+1) f[i]=i;
		int ans=0;
		while (x!=-1)
		{
			scanf("%d",&y);
			x=find(x);y=find(y);
			if (x==y) ++ans;
			else f[x]=y;
			scanf("%d",&x);
		};
		printf("%d\n",ans);
	}
	return 0;
}
