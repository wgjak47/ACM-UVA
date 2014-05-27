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
const int maxn=30;
long long P;
struct Edge
{
	int from,to;
	long long dist;
};
struct HeapNode
{
	long long d,u;
	bool operator<(const HeapNode &rhs) const
	{
		return d>rhs.d;
	}
};
long long cal(long long left,int place)
{
	if (place==0) return left+1;
	int k,r;
	k=left/20;
	if (left%20) k++;
	r=left+k;
	while (1)
	{
		int z=r/20;
		if (r%20) z++;
		if (z==k) return r;
		r+=z-k;
		k=z;
	}
	return r;
}
struct Dijkstra
{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	long long d[maxn];
	int p[maxn];
	void init(int n)
	{
		this->n=n;
		pf(i,0,n) G[i].clear();
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
	    pf(i,0,n) d[i]=2000000000LL;
		d[s]=P;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while (!Q.empty())
		{
			HeapNode x=Q.top();
			Q.pop();
			int u=x.u;
			if (done[u]) continue;
			done[u]=true;
			pf(i,0,G[u].size())
			{
				Edge &e=edges[G[u][i]];
				if (d[e.to]>cal(d[u],e.dist))
				{
					d[e.to]=cal(d[u],e.dist);
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
				else if (d[e.to]==cal(d[u],e.dist))
				{
					int k1=p[e.to],k2=G[u][i];
					if (edges[k1].from>edges[k2].from)
					{
						p[e.to]=G[u][i];
						Q.push((HeapNode){d[e.to],e.to});
					}
				}
			}
		}
	}
};
bool big(char c)
{
	return (c<='Z' && c>='A');
}
Dijkstra solver;
bool f[30];
int convert(char s)
{
	if (big(s))
		return s-'A';
	return s-'a';
}
void dfs(int s,int e)
{
	if (f[s])
	printf("%c",s+'A');
	else printf("%c",s+'a');
	if (s==e)
	{
		putchar('\n');
		return ;
	}
	else
	putchar('-');
	int m=solver.p[s];
	dfs(solver.edges[m].from,e);
}
main()
{
	int M;
	int kcase=1;
	while (scanf("%d",&M)==1)
	{
		if (M==-1) break;
		char x,y;
		getchar();
		solver.init(26);
		memset(f,0,sizeof(f));
		pf(i,0,M)
		{
			scanf("%c %c",&x,&y);
			getchar();
			int xx=convert(x);
			int yy=convert(y);
			if (big(x)) f[xx]=true;
			if (big(y)) f[yy]=true;
			if (big(x))
				solver.AddEdge(xx,yy,1);
			else solver.AddEdge(xx,yy,0);	
			if (big(y))
				solver.AddEdge(yy,xx,1);
			else solver.AddEdge(yy,xx,0);	
		}
		char S,E;
		scanf("%lld %c %c",&P,&S,&E);
		int s=convert(S);
		int e=convert(E);
		solver.dijkstra(e);
		printf("Case %d:\n",kcase++);
		printf("%lld\n",solver.d[s]);
		dfs(s,e);
	}
	return 0;
}
