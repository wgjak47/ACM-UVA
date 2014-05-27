#include<cstdio>
#include<cstring>
#define inf 100000000
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b 
int fs[510];
bool vis[510];
int G[510][510];
int F,I;
int init_road()
{
	char s[100];
	if (gets(s)==NULL) return -1;
	int u,v,w;
	if (sscanf(s,"%d%d%d",&u,&v,&w)==3)
	{
		G[u][v]=w;
		G[v][u]=w;
		return 3;
	}
	return -1;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&F,&I);
		for (int i=1;i<=I;i++)
		for (int j=1;j<=I;j++)
			G[i][j]=inf;
		memset(vis,0,sizeof(vis));
		for (int i=0;i<F;i++)
		{
			scanf("%d",&fs[i]);
			vis[fs[i]]=true;
		}
		getchar();
		while (init_road()!=-1);
		for (int i=1;i<=I;i++)
		for (int j=1;j<=I;j++)
		for (int k=1;k<=I;k++)
			if (G[j][i]+G[k][i]<G[j][k])
				G[j][k]=G[j][i]+G[k][i];
		for (int i=1;i<=I;i++) G[i][i]=0;	
		int ans=inf;
		int min;
		int lt=0;
		for (int j=1;j<=I;j++)
		{
				int max=0;
				fs[F]=j;
				for (int k=1;k<=I;k++)
				{
					min=inf;
					for (int i=0;i<=F;i++)	
						min=min(min,G[k][fs[i]]);
					max=max(max,min);
				}
				//printf("%d ",max);
				if (ans>max)
					ans=max,lt=j;	
		}
		printf("%d\n",lt);
		if (T) putchar('\n'); 
	}
	return 0;
}
