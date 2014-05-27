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
vector<int> G[310];
int dgree[310];
int color[310];
bool bipartite(int u)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (color[v]==color[u]) return false;
		if (!color[v])
		{
			color[v]=3-color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
}
main()
{
	int V;
	while (scanf("%d",&V) && V)
	{
		pf(i,1,V+1) G[i].clear();
		memset(dgree,0,sizeof(dgree));
		memset(color,0,sizeof(color));
		int u,v;
		//while (scanf("%d%d",&u,&v)==2)
		pf(i,0,V*3/2+1)
		{
			scanf("%d%d",&u,&v);
			if (u==v && u==0) break;
			G[u].push_back(v);
			G[v].push_back(u);
			dgree[u]++;
			dgree[v]++;
		}
	/*	pf(i,1,V+1)
		if (dgree[i]==3)
		{
			dgree[i]=0;
			pf(j,0,G[i].size())
				dgree[G[i][j]]--;
		}
		bool ok=true;
		pf(i,1,V+1)
		if (dgree[i]!=0) ok=false;*/
		color[1]=1;
		bool ok=bipartite(1);
		printf("%s",ok?"YES\n":"NO\n",ok);
	}
	return 0;
}
