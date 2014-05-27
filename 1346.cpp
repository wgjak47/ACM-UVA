#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
const int maxn=1100;
struct Edge
{
	int u,v;
};
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> G[maxn],bcc[maxn];
stack<Edge> S;
int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		Edge e=(Edge){u,v};
		if (!pre[v])
		{
			S.push(e);
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if (lowv>=pre[u])
			{
				iscut[u]=true;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				for(;;)
				{
					Edge x=S.top();
					S.pop();
					if (bccno[x.u]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u]=bcc_cnt;
					}
					if (bccno[x.v]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v]=bcc_cnt;
					}
					if (x.u==u && x.v==v) break;
				}
			}
	  	} 
		else if (pre[v]<pre[u] && v!=fa)
		{ 
			S.push(e);
			lowu=min(lowu,pre[v]);
	 	}
	}
		if (fa<0 && child==1) iscut[u]=0;
		return lowu;
}
void find_bcc(int n)
{
	memset(pre,0,sizeof(pre));
	memset(iscut,0,sizeof(iscut));
	memset(bccno,0,sizeof(bccno));
	dfs_clock=bcc_cnt=0;
	for (int i=0;i<n;i++)
		if (!pre[i]) dfs(i,-1);
}
int odd[maxn],color[maxn];
bool bipartite(int u,int b)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (bccno[v]!=b) continue;
		if (color[v]==color[u]) return false;
		if (!color[v])
		{
			color[v]=3-color[u];
			if (!bipartite(v,b)) return false;
		}
	}
	return true;
}
int A[maxn][maxn];
main()
{
	int m,n;
	int kases=0;
	while (scanf("%d%d",&n,&m)==2 && n)
	{
		pf(i,0,n)  G[i].clear();
		memset(A,0,sizeof(A));
		pf(i,0,m)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			A[u][v]=A[v][u]=1;
		}
		pf(u,0,n)
		pf(v,u+1,n)
			if (!A[u][v])
			{
				G[u].push_back(v);
				G[v].push_back(u);
			}
		find_bcc(n);
		//bcc_cnt=0;
		memset(odd,0,sizeof(odd));
		pf(i,1,bcc_cnt+1)
		{
			memset(color,0,sizeof(color));
			pf(j,0,bcc[i].size()) bccno[bcc[i][j]]=i;
			int u=bcc[i][0];
			color[u]=1;
			if (!bipartite(u,i))
				pf(j,0,bcc[i].size()) odd[bcc[i][j]]=1;
		}
		int ans=n;
		pf(i,0,n) if (odd[i]) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
