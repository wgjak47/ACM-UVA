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
vector<int> G[maxn];
vector<int> G2[maxn];
vector<int> S;
int sccno[maxn];
int scc_cnt;
bool vis[maxn];
bool in[maxn],out[maxn];
void dfs1(int u)
{
	if (vis[u]) return ;
	vis[u]=1;
	pf(i,0,G[u].size()) dfs1(G[u][i]);
	S.push_back(u);
}
void dfs2(int u)
{
	if (sccno[u]) return ;
	sccno[u]=scc_cnt;
	pf(i,0,G2[u].size()) dfs2(G2[u][i]);
}
void find_scc(int n)
{
	scc_cnt=0;
	S.clear();
	memset(sccno,0,sizeof(sccno));
	memset(vis,0,sizeof(vis));
	pf(i,1,n+1) dfs1(i);
	mf(i,n-1,-1) if (!sccno[S[i]]) {scc_cnt++;dfs2(S[i]);}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<=n;i++) 
		{
			G[i].clear();
			G2[i].clear();
		}
		for (int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G2[v].push_back(u);
		}
		find_scc(n);
		pf(i,1,scc_cnt+1) in[i]=out[i]=1;
		pf(u,1,n+1) pf(i,0,G[u].size())
		{
			int v=G[u][i];
			if (sccno[u]!=sccno[v]) in[sccno[v]]=out[sccno[u]]=0;
		}
		int a=0,b=0;
		pf(i,1,scc_cnt+1)
		{
			if (in[i]) a++;
			if (out[i]) b++;
		}
		int ans=max(a,b);
		if (scc_cnt==1) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
