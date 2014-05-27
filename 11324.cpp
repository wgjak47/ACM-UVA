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
const int maxn=1010;
vector<int> G[maxn],G2[maxn];
vector<int> S;
int vis[maxn],sccno[maxn],scc_cnt;
int w[maxn];
int d[maxn];
vector<int> DAG[maxn];
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
	pf(i,0,n) dfs1(i);
	mf(i,n-1,-1) if (!sccno[S[i]])
	{
		scc_cnt++;
		dfs2(S[i]);
	}
}
int find_ans(int u)
{
	if (d[u]!=-1) return d[u];
	d[u]=0;
	pf(j,0,DAG[u].size())
		d[u]=max(d[u],find_ans(DAG[u][j]));
	d[u]+=w[u];
	return d[u];
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		pf(i,0,n+1) 
		{
			G[i].clear();
			G2[i].clear();
		}
		pf(i,0,m)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			G[u].push_back(v);
			G2[v].push_back(u);
		}
		find_scc(n);
		memset(w,0,sizeof(w));
		pf(i,0,n)
			w[sccno[i]]++;
		pf(u,0,scc_cnt+1) DAG[u].clear();
		pf(u,0,n)
		{
			pf(j,0,G[u].size())
			{
				int v=G[u][j];
				if (sccno[u]!=sccno[v])
					DAG[sccno[u]].push_back(sccno[v]);
			}
		}
		memset(d,-1,sizeof(d));
		int ans=0;
		for (int i=1;i<=scc_cnt;i++)
			ans=max(ans,find_ans(i));
		printf("%d\n",ans);
	}
	return 0;
}
