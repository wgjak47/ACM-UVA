#include<stdio.h>
#include<string.h>
int G[30][30];
int vis[30][30];
int max;
int n;
void dfs(int k,int reg)
{
	int i;
	for (i=0;i<n;i++)
		if (G[k][i] && !vis[k][i])
		{
			vis[k][i]=vis[i][k]=1;
			dfs(i,reg+1);
			vis[k][i]=vis[i][k]=0;
		}
	if (reg>max) max=reg;
}
main()
{ 
	int i,j,k,l,m;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d%d",&n,&m)==2)
 	{
		if (n==0 && m==0) break;
		max=0;
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		for (i=0;i<m;i++)
 		{
			scanf("%d%d",&k,&l);
			G[k][l]=1;
			G[l][k]=1;
		}
		for (i=0;i<n;i++)
			dfs(i,0);
		printf("%d\n",max);
	}
	return 0;
}
