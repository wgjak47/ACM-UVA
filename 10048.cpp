#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
int W[110][110];
int max(int a,int b)
{
	return a>b?a:b;
}
main()
{
	int C,S,Q;
	int reg=0;
	while (scanf("%d%d%d",&C,&S,&Q)==3)
	{
		if (C==0) break;
		if (reg) putchar('\n');
		memset(W,0x7f,sizeof(W));//clear
		int u,v,w;//edge & weight
		for (int i=0;i<S;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			W[u][v]=W[v][u]=w;//initial && undirected Graph
		}
		for (int k=1;k<=C;k++)//floyd
		for (int i=1;i<=C;i++)
		for (int j=1;j<=C;j++)
		{
			int temp=max(W[i][k],W[k][j]);	
//			printf("%d %d %d %d\n",k,i,j,temp);
			W[i][j]=min(W[i][j],temp);
		}
		printf("Case #%d\n",++reg);
		for (int i=0;i<Q;i++)
		{
			scanf("%d%d",&u,&v);
			if (W[u][v]!=2139062143)
			printf("%d\n",W[u][v]);
			else printf("no path\n");
		}
	}	
	return 0;
}
