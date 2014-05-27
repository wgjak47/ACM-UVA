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
const int maxn=20000+10;
int pa[maxn],d[maxn];
int findset(int x)
{
	if (pa[x]!=x)
	{
		int root=findset(pa[x]);
		d[x]+=d[pa[x]];
		return pa[x]=root;
	}
	else return x;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int u,v,n;
		char cmd[9];	
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			pa[i]=i;
			d[i]=0;
		}
		getchar();
		while (scanf("%s",cmd) && cmd[0]!='O')
		{
			if (cmd[0]=='E') {scanf("%d",&u);findset(u);printf("%d\n",d[u]);}
			if (cmd[0]=='I') {scanf("%d%d",&u,&v);pa[u]=v;d[u]=abs(u-v)%1000;}
		}
	}
	return 0;
}
