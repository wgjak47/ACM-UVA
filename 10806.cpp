#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define INF 10010000
#define MAX 120
using namespace std;
int c,f;
int n,m;
int s,t;
int cost[MAX][MAX];
int cap[MAX][MAX];
void solve()
{
	queue<int> q;
	int d[MAX];
	int p[MAX];
	int flow[MAX][MAX];
	memset(flow,0,sizeof(flow));
	c=f=0;	
	while (true)
	{
		bool inq[MAX];
		for (int i=1;i<=n+1;i++) p[i]=i;
		for (int i=1;i<=n+1;i++)
			d[i]=(i==s?0:INF);
		memset(inq,false,sizeof(inq));
		q.push(s);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			inq[u]=false;
			for (int v=1;v<=n+1;v++)
				if (cap[u][v]>flow[u][v] && d[v]>d[u]+cost[u][v])
				{
					d[v]=d[u]+cost[u][v];
					p[v]=u;
					if (!inq[v])
					{
						inq[v]=true;
						q.push(v);
					}
				}
		}
		if (d[t]==INF) break;
		int a=INF;
		for (int u=t;u!=s;u=p[u]) 
			if (a>cap[p[u]][u]-flow[p[u]][u])
				a=cap[p[u]][u]-flow[p[u]][u];
			for (int u=t;u!=s;u=p[u])
			{
				flow[p[u]][u]+=a;
				flow[u][p[u]]-=a;
				cost[u][p[u]]=-cost[p[u]][u];
			}
			c+=d[t]*a;
			f+=a;
	}
}
void format()
{
	s=1;t=n+1;
	memset(cap,0,sizeof(cap));
	cap[n][n+1]=cap[n+1][n]=2;
	cost[n][n+1]=cost[n+1][n]=0;
//	cap[1][0]=cap[0][1]=2;
//	cost[1][0]=cost[0][1]=0;
}
main()
{
	int u,v;
	while (scanf("%d",&n),n!=0)
	{
		format();
		scanf("%d",&m);
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&u,&v);
			scanf("%d",&cost[u][v]);
			cost[v][u]=cost[u][v];
			cap[u][v]=cap[v][u]=1;
		}
		solve();
		if (f==2)
		printf("%d\n",c);
		else printf("Back to jail\n");
	}	
	return 0;
}
