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
const int maxn=6100;
const int INF=1e9;
int N,S,E;
struct Edge
{
	int from,to,dist;
};
struct HeapNode
{
	int d,u;
	bool operator < (const HeapNode & rhs) const 
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
		for (int i=0;i<n;i++) G[i].clear();
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
		for (int i=0;i<n;i++) d[i]=INF;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while (!Q.empty())
		{
			HeapNode x=Q.top();
			Q.pop();
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
struct road
{
	int r[550];
	int num;
};
road ans_road;
Dijkstra GS,GE;
void find(int start,int end,const Dijkstra & G)
{
	int z;
	if (start==end) 
	{
	/*	z=ans_road.num;
		ans_road.r[z]=end;
		ans_road.num++;*/
		printf("%d",end+1);
		return ;
	}
	const Edge &e=G.edges[G.p[end]];
	find(start,e.from,G);
	printf(" %d",end+1);
}
void ffind(int start,int end,const Dijkstra & G)
{
	int z;
	if (start==end) 
	{
	/*	z=ans_road.num;
		ans_road.r[z]=end;
		ans_road.num++;*/
		printf(" %d",end+1);
		return ;
	}
/*	z=ans_road.num;
	ans_road.r[z]=end;
	ans_road.num++;*/
	printf(" %d",end+1);
	const Edge &e=G.edges[G.p[end]];
	ffind(start,e.from,G);
}
main()
{
	int kcase=0;
	while (scanf("%d%d%d",&N,&S,&E)==3)
	{
		if (kcase++) putchar('\n');
		GS.init(N);
		GE.init(N);
		S--,E--;
		int M;
		scanf("%d",&M);
		pf(i,0,M)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			GS.AddEdge(x,y,z);
			GS.AddEdge(y,x,z);
			GE.AddEdge(x,y,z);
			GE.AddEdge(y,x,z);
		}
		GS.dijkstra(S);
		GE.dijkstra(E);
		int K;
		scanf("%d",&K);
		int ans=GS.d[E];
		int a=-1,b=-1;
		pf(i,0,K)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			if (z+GS.d[x]+GE.d[y]<ans)
			{
				ans=z+GS.d[x]+GE.d[y];
				a=x;
				b=y;
			}
			if (z+GS.d[y]+GE.d[x]<ans)
			{
				ans=z+GS.d[y]+GE.d[x];
				b=x;
				a=y;
			}
		}
		if (a!=-1)
		{
			find(S,a,GS);
			ffind(E,b,GE);
			putchar('\n');
			printf("%d\n",a+1);
		}
		else 
		{
			find(S,E,GS);
			putchar('\n');
			printf("Ticket Not Used\n");
		}
/*		for (int i=0;i<ans_road.num;i++)
		{
			if (i) putchar(' ');
			printf("%d",ans_road.r[i]+1);
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
