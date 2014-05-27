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
#define INF 1e6
#define maxn 1010
using namespace std;
struct Edge
{
	int from,to,dist;
};
struct HeapNode
{
	int d,u;
	bool operator<(const HeapNode & rhs) const 
	{
		return d>rhs.d;
	}
};
struct Dijkstra 
{   
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	
	void init(int n)
	{
		this->n=n;
		for (int i=0;i<n;i++)
			G[i].clear();
		edges.clear();
	}
	
	void AddEdge(int from,int to,int dist)
	{
		edges.push_back((Edge){from,to,dist});
		m=edges.size();
		G[from].push_back(m-1);
	}
	
	void dijkstra(int s)
	{ 
		priority_queue<HeapNode> Q;
		for (int i=1;i<=n;i++) d[i]=INF;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while (!Q.empty())
		{
 			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if (done[u]) continue;
			done[u]=true;
			for (int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if (d[e.to]>d[u]+e.dist)
				{
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
	 			}
	  		}
	 	}
	}
}; 
Dijkstra solver;
vector<int> G2[maxn];
int f[maxn];
int dfs(int node)
{
	if (f[node]!=-1) return f[node];
	f[node]=0;
	for (int i=0;i<G2[node].size();i++)
	{
		int u=G2[node][i];
		if (f[u]!=-1)
			f[node]+=f[u];
		else f[node]+=dfs(u);
	}
	return f[node];
}
main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)==2)
	{
		memset(f,-1,sizeof(f));
		solver.init(n);
		pf(i,0,m)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			solver.AddEdge(u,v,w);
			solver.AddEdge(v,u,w);
		}
		solver.dijkstra(2);
		for (int i=1;i<=n;i++)
			G2[i].clear();
		for (int i=1;i<=n;i++)
		{
	//		printf("%d: ",i);
			for (int j=0;j<solver.G[i].size();j++)
			{
				int u=solver.G[i][j];
				u=solver.edges[u].to; 
				if (solver.d[i]>solver.d[u])
				{
					G2[i].push_back(u);
	//				printf("%d ",u);
				}
			}
	//		printf("\n");
		}
		f[2]=1;
		dfs(1);
		printf("%d\n",f[1]);
	}
	return 0;
}
