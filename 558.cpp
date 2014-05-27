#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int G[1001][1001];
int node[1001];
int value[1001][1001];
int M,N;
int solve()
{
	int d[1001];
	queue<int> q;
	bool ind[1001];
	int reg[1001];
	memset(reg,0,sizeof(reg));
	memset(ind,false,sizeof(ind));
	for (int i=0;i<N;i++) d[i]=i==0?0:3000000;
	q.push(0);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		ind[x]=false;
		for (int e=0;e<node[x];e++)
			if (d[G[x][e]]>d[x]+value[x][G[x][e]])
			{
				d[G[x][e]]=d[x]+value[x][G[x][e]];
				if (!ind[G[x][e]])
				{
					ind[G[x][e]]=true;
					q.push(G[x][e]);
				}
				reg[G[x][e]]++;
				if (reg[G[x][e]]>=N) return 1;
			}
	}
	return 0;
}
main()
{
	int T;
	int i,j,k;
	scanf("%d",&T);
	while (T--)
	{
		memset(node,0,sizeof(node));
		scanf("%d%d",&N,&M);
		for (i=0;i<M;i++)
		{
			scanf("%d%d",&j,&k);
			scanf("%d",&value[j][k]);
			G[j][node[j]++]=k;
		}
		if (solve())
			printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}
