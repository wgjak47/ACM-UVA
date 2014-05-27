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
#define INF 1e7
const int maxn=310;
using namespace std;
struct Edge
{
	int from,to,cap,flow;
};
struct Dinic
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	bool BFS()
	{
		memset(vis,0,sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s]=0;
		vis[s]=1;
		while (!Q.empty())
		{
			int x=Q.front();
			Q.pop();
			pf(i,0,G[x].size())
			{
				Edge & e=edges[G[x][i]];
				if (!vis[e.to] && e.cap>e.flow)
				{
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	void AddEdge(int from,int to,int cap)
	{
		edges.push_back((Edge){from,to,cap,0});
		edges.push_back((Edge){to,from,0,0});
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	int DFS(int x,int a)
	{
		if (x==t || a==0) 
			return a;
		int flow=0,f;
		for (int &i=cur[x];i<G[x].size();i++)
		{
			Edge &e=edges[G[x][i]];
			if (d[x]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if (a==0) break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t)
	{
		this->s=s;
		this->t=t;
		int flow=0;
		while (BFS())
		{
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,INF);
		}
		return flow;
	}
	void clear()
	{
		edges.clear();
		pf(i,0,maxn)
			G[i].clear();
	}
};
main()
{
	int N,M;
	Dinic data;
	int C;
	while (scanf("%d",&N)==1)
	{
		data.clear();
		pf(i,1,N+1)
		{
			scanf("%d",&C);
			data.AddEdge(i*2-1,2*i,C);
		}
		scanf("%d",&M);
		pf(i,0,M)
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			data.AddEdge(x*2,y*2-1,c);
		}
		int  B,D;
		scanf("%d%d",&B,&D);
		pf(i,0,B)
		{
			int x;
			scanf("%d",&x);
			data.AddEdge(0,x*2-1,INF);
		}
		pf(i,0,D)
		{
			int x;
			scanf("%d",&x);
			data.AddEdge(x*2,2*N+1,INF);
		}
		printf("%d\n",data.Maxflow(0,2*N+1));
	}
	return 0;
}
