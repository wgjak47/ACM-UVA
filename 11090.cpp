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
struct Edge
{
	int from,to;
	double dist;
};
const int maxn=60;
struct BellmanFord
{
	int m,n;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	double d[maxn];
	int p[maxn];
	int cnt[maxn];
	void init(int n)
	{
		this->n=n;
		for (int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int dist)
	{
		edges.push_back((Edge){from,to,dist});
		m=edges.size();
		G[from].push_back(m-1);
	}
	bool negativeCycle()
	{
		queue<int> Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++) 
		{
			d[i]=0;
			inq[0]=true;
			Q.push(i);
		}
		while (!Q.empty())
		{
			int u=Q.front();Q.pop();
			inq[u]=false;
			for (int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if (d[e.to]>d[u]+e.dist)
				{
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					if (!inq[e.to]) 
					{
						Q.push(e.to);
						inq[e.to]=true;
						if (++cnt[e.to]>n) return true;
					}
				}
			}
		}
		return false;
	}
};
BellmanFord solver;
int m,n;
bool test(double M)
{
	pf(i,0,solver.m)
		solver.edges[i].dist-=M;
	bool ok=solver.negativeCycle();
	pf(i,0,solver.m)
		solver.edges[i].dist+=M;
	return ok;
}
main()
{
	int T;
	scanf("%d",&T);
	int kk=1;
	while (T--)
	{
		scanf("%d%d",&n,&m);
		solver.init(n);
		int maxw=0;
		pf(i,0,m)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			maxw=max(w,maxw);
			solver.AddEdge(u,v,w);
		}
		printf("Case #%d: ",kk++);
		if (!test(maxw+1)) printf("No cycle found.\n");
		else 
		{
			double L=0,R=maxw;
			while (R-L>1e-3)
			{
				double M=L+(R-L)/2;
				if (test(M)) R=M;
				else L=M;
			}
			printf("%.2f\n",L);
		}
	}
	return 0;
}
