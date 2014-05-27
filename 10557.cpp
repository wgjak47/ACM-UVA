#include<cstdio>
#include<cstring>
#include<queue>
#define INF 100001
int N;
int w[200];
int node[110];
int G[110][110];
int d[200];
bool solve()
{
	using namespace std;
	queue <int> q;
	for (int i=1;i<=N;i++)
	d[i]=INF;
	d[1]=0;
	bool inq[200];
	memset(inq,false,sizeof(inq));
	q.push(1);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		inq[x]=false;
		for (int i=0;i<node[x];i++)
		if (d[G[x][i]]>d[x]+w[G[x][i]] && d[x]+w[G[x][i]]<100 && d[x]+w[G[x][i]]>=-INF)
		{
			if (G[x][i]==N) return true;
			d[G[x][i]]=d[x]+w[G[x][i]];
			if (!inq[G[x][i]])
			{
				inq[G[x][i]]=true;
				q.push(G[x][i]);
			}
		}
	}
	return false;
}
main()
{
	while (scanf("%d",&N)==1)
	{
		if (N==-1) break;
		memset(node,0,sizeof(node));
		for (int i=1;i<=N;i++)
		{
			int total;
			scanf("%d",&w[i]);
			w[i]=-w[i];
			scanf("%d",&node[i]);
			for (int j=0;j<node[i];j++)
				scanf("%d",&G[i][j]);
		}
		if (solve())
			printf("winnable\n",d[N-1]);
		else printf("hopeless\n");
	}
	return 0;
}
