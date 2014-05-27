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
int n;
const int maxn=1010;
int u[maxn*maxn],v[maxn*maxn];
double dis[maxn*maxn];
int x[maxn],y[maxn],P[maxn];
int p[maxn],r[maxn*maxn];
vector<int> G[maxn];
double mincost[maxn][maxn];
double pp[maxn][maxn];
double cal(int a,int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])*1.0+(y[a]-y[b])*(y[a]-y[b])*1.0);
}
int cmp(const int i,const int j) {return dis[i]<dis[j];}
int find(int x) {return p[x]==x?x:p[x]=find(p[x]);}
double kruskal(int m)
{
	double ans=0;
	pf(i,0,n) p[i]=i,G[i].clear();
	pf(i,0,m) r[i]=i;
	sort(r,r+m,cmp);
	pf(i,0,m)
	{
		int a=r[i];
		int x=find(u[a]);
		int y=find(v[a]);
		if (x!=y)
		{
			G[u[a]].push_back(v[a]);
			G[v[a]].push_back(u[a]);
			ans+=dis[a];
			p[x]=y;
		}
	}
	return ans;
}
bool vis[maxn];
void dfs(int u,int root)
{
	if (vis[u]) return ;
	vis[u]=true;
	pf(i,0,G[u].size())
	{
		int v=G[u][i];
		if (!vis[v])
		{
			mincost[root][v]=max(pp[v][u],mincost[root][u]);
			dfs(v,root);
		}
	}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		pf(i,0,n)
			scanf("%d%d%d",&x[i],&y[i],&P[i]);
		int m=0;
		pf(i,0,n) pf(j,i+1,n)
		{
			u[m]=i;v[m]=j;
			dis[m++]=cal(i,j);
			pp[i][j]=pp[j][i]=dis[m-1];
		}
		double min_tree=kruskal(m);
		memset(mincost,0,sizeof(mincost));
		pf(i,0,n) 
		{
			memset(vis,0,sizeof(vis));
			dfs(i,i);
		}
		double ans=0;
		pf(i,0,n) pf(j,i+1,n)
		{
			double A=P[i]+P[j];
			ans=max(ans,A/(min_tree-mincost[i][j]));
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
