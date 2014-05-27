//网络流最大流（快）或者二分图多重匹配（简单）
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 100000
using namespace std;
struct edge
{
	int v,cap,flow,left;
};
struct Graph
{
	vector<edge> edges[1100];
	int n,m;
};
Graph G;
int d[1100];
bool BFS()
{
	bool vis[1100];
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(0);
	d[0]=0;
	vis[0]=1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for	(int i=0;i<G.edges[x].size();i++)
			if (!vis[G.edges[x][i].v] && G.edges[x][i].cap>G.edges[x][i].flow)
			{
				vis[G.edges[x][i].v]=1;
				d[G.edges[x][i].v]=d[x]+1;
				q.push(G.edges[x][i].v);
			}
	}
	return vis[G.n];
}
void find(int u,int v,int f)
{
	for (int i=0;i<G.edges[u].size();i++)
		if (G.edges[u][i].v==v)
		{
			G.edges[u][i].flow-=f;
			return ;
		}
}
int dfs(int x,int a,int *cur)
{
	if (x==G.n || a==0) return a;
	int flow=0,f;
	for (int i=cur[x];i<G.edges[x].size();i++)
	if (d[x]+1==d[G.edges[x][i].v] && (f=dfs(G.edges[x][i].v,min(a,G.edges[x][i].cap-G.edges[x][i].flow),cur))>0)
	{
		G.edges[x][i].flow+=f;
		find(G.edges[x][i].v,x,f);
		flow+=f;
		a-=f;
		if (a==0) break;
	}
	return flow;
}
int maxflow()
{
	int flow=0;
	int cur[1100];
	while (BFS())
	{
		memset(cur,0,sizeof(cur));
		flow+=dfs(0,INF,cur);
	}
	return flow;
}
main()
{
	int ink[22];
	int nk,np;
	while (scanf("%d%d",&nk,&np)==2)
	{
		if (nk==0 && np==0) break;
		for (int i=0;i<=nk+np+1;i++) G.edges[i].clear();
		int sum=0;
		for (int i=1;i<=nk;i++)
		{
			scanf("%d",&ink[i]);
			sum+=ink[i];
		}
		for (int i=nk+1;i<=nk+np;i++)
		{
			int t,s;
			edge tmp;
			tmp.flow=0,tmp.left=0;
			scanf("%d",&t);
			while (t--)
			{
				scanf("%d",&s);
				tmp.v=s,tmp.cap=1;tmp.flow=0;
				G.edges[i].push_back(tmp);
				tmp.v=i,tmp.cap=0;tmp.flow=0;
				G.edges[s].push_back(tmp);
			}
		}
		G.n=nk+np+1;
		for (int i=nk+1;i<=nk+np;i++)
		{
			edge tmp;
			tmp.v=i,tmp.cap=1;
			tmp.flow=0,tmp.left=0;
			G.edges[0].push_back(tmp);
			tmp.v=0;
			G.edges[i].push_back(tmp);
		}
		for (int i=1;i<=nk;i++)
		{
			edge tmp;
			tmp.v=i;
			tmp.flow=0;tmp.cap=0;
			G.edges[G.n].push_back(tmp);
			tmp.v=G.n;
			tmp.cap=ink[i];
			G.edges[i].push_back(tmp);
		}
		int ans=maxflow();
		if (ans==sum)
		{
			printf("1\n");
			for (int i=1;i<=nk;i++)
			{
				bool space=false;
				for (int j=0;j<G.edges[i].size();j++)
				if (G.edges[i][j].cap-G.edges[i][j].flow)
				{
					if (space) printf(" ");
					space=true;
					printf("%d",G.edges[i][j].v-nk);
				}
				putchar('\n');
			}
		}		
		else printf("0\n");
	}
	return 0;
}
