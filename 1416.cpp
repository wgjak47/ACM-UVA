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
#define LLD long long
const LLD INF=1e9;
const int maxn=110;
const int maxm=2010;
using namespace std;
struct Edge
{
	int from,to;
	LLD dist;
	vector<int> point;
};
struct HeapNode
{ 
	LLD d;
	int u;
	bool operator<(const HeapNode &rhs) const 
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
	LLD d[maxn];
	int p[maxn];
	void init(int n)
	{
		this->n=n;
		pf(i,0,n) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int dist)
	{
		Edge temp;
		temp.from=from;
		temp.dist=dist;
		temp.to=to;
		edges.push_back(temp);
		m=edges.size();
		G[from].push_back(m-1);
	}
	void dijkstra(int s)
	{
		memset(p,-1,sizeof(p));
		priority_queue<HeapNode> Q;
		pf(i,0,n) d[i]=INF;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while (!Q.empty())
		{
			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if (done[u]) continue;
			done[u]=true;
			pf(i,0,G[u].size())
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
bool vism[maxm];
bool visn[maxn];
void find(int u,int fa)
{
	if (u==fa) return ;
	int k=solver.p[u];
	if (k==-1) return ;
	int from=solver.edges[k].from;
	vism[k]=true;
	int m=solver.edges[k].point.size();
	if (m==0 || solver.edges[k].point[m-1]!=fa)
		solver.edges[k].point.push_back(fa);
	find(solver.edges[k].from,fa);
}
LLD dp[maxn];
main()
{
	int n,m,L;
	while (scanf("%d%d%d",&n,&m,&L)==3)
	{
		memset(vism,0,sizeof(vism));
		memset(dp,0,sizeof(dp));
		solver.init(n);
		pf(i,0,m) 
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			solver.AddEdge(u,v,w);
			solver.AddEdge(v,u,w);
		}
		LLD oc=0;
		pf(i,0,n)
		{
			solver.dijkstra(i);
			pf(j,0,n)
			{
				find(j,i);
				if (solver.d[j]<INF)
				{
					dp[i]+=solver.d[j];
					oc+=solver.d[j];
				}
				else 
				{
					dp[i]+=L;
					oc+=L;
				}
			}
		}
		//printf("%lld\n",oc);
		LLD ans=0;
		LLD occ=0;
		pf(i,0,solver.m)
		if (vism[i])
		{
			occ=0;
			vector<int> po;
			po.clear();
			memset(visn,0,sizeof(visn));
			LLD tmp=solver.edges[i].dist;
			if (i>0 && solver.edges[i].to==solver.edges[i-1].from && solver.edges[i-1].to==solver.edges[i].from && solver.edges[i].dist==solver.edges[i-1].dist) 
			{
				solver.edges[i-1].dist=INF;
				pf(l,0,solver.edges[i-1].point.size()) po.push_back(solver.edges[i-1].point[l]);
			}
			else 
			if (i<solver.m-1 && solver.edges[i].to==solver.edges[i+1].from && solver.edges[i+1].to==solver.edges[i].from && solver.edges[i].dist==solver.edges[i+1].dist) 
			{
				solver.edges[i+1].dist=INF;
				pf(l,0,solver.edges[i+1].point.size()) po.push_back(solver.edges[i+1].point[l]);
			}
			solver.edges[i].dist=INF;
			pf(j,0,solver.edges[i].point.size()) po.push_back(solver.edges[i].point[j]);
			pf(j,0,po.size())
			{
				int u=po[j];
				visn[u]=true;
		//		printf("%d\n",u+1);
				solver.dijkstra(u);
				pf(k,0,n)
				if (solver.d[k]<INF)
				occ+=solver.d[k];
				else occ+=L;
			}
		//	printf("%lld\n",occ);
			pf(j,0,n)
				if (!visn[j]) occ+=dp[j];
			if (i>0 && solver.edges[i].to==solver.edges[i-1].from && solver.edges[i-1].to==solver.edges[i].from && solver.edges[i-1].dist==solver.edges[i].dist) solver.edges[i-1].dist=tmp;
			else 
			if (i<solver.m-1 && solver.edges[i].to==solver.edges[i+1].from && solver.edges[i+1].to==solver.edges[i].from && solver.edges[i+1].dist==solver.edges[i].dist) solver.edges[i+1].dist=tmp;
			solver.edges[i].dist=tmp;
	//		printf("%d %d %lld %lld\n",solver.edges[i].from+1,solver.edges[i].to+1,solver.edges[i].dist,occ);
			ans=max(ans,occ);
		}
		printf("%lld %lld\n",oc,ans);
	}
	return 0;
}
