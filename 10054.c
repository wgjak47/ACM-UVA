#include<stdio.h>
#include<string.h>
int G[60][60];
int vis[60][60];
int n;
int dgree[60];
int p[60];
int reg;
void fuck(int u)
{
	int i;
	for (i=1;i<=50;i++)
	{
		if (G[u][i])
		{
			G[u][i]--;
			G[i][u]--;
			fuck(i);
		    printf("%d %d\n",i,u);
		}
	}
}
int find (int x)
{
	return p[x]==x?x:(p[x]=find(p[x]));
}
int judge()
{
	int i,j;
	for (i=0;!dgree[i];i++);
	for (j=i+1;j<=50;j++)
		if (dgree[j] && find(i)!=find(j))
			return 1;
	for (i=0;i<=50;i++)
		if (dgree[i]%2!=0) return 1;
	return 0;
}
main()
{
	int m,n,total,i,j,k,flag,ces=0,max;
	freopen("in.txt","r",stdin);
	scanf("%d",&total);
	while (total--)
	{
		max=0;
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		memset(dgree,0,sizeof(dgree));
		for (i=1;i<=50;i++)
			p[i]=i;
		flag=1;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&m,&k);
			G[m][k]++;
			G[k][m]++;
			dgree[m]++;
			dgree[k]++;
			if (find(m)!=find(k))
			p[find(m)]=find(k);
		}
/*		for (i=1;i<10;i++)
			printf("%d %d\n",p[i],i)
			;*/
		printf("Case #%d\n",++ces);
		if (judge()) printf("some beads may be lost\n");
		else 
		{
			i=0;
			while (dgree[i]==0 && i<=51) i++;
			fuck(i);
		}
		if (total!=0) printf("\n");
	/*	for (i=1;i<10;i++)
			printf("%d %d\n",p[i],i);*/
	}
	return 0;
}
