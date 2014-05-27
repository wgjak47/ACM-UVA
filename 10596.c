#include<stdio.h>
#include<string.h>
int G[210][210];
int reg[210];
int vis[210];
int n,r;
void dfs(int x)
{
	int i;
	vis[x]=1;
	for (i=0;i<n;i++)
		if (G[x][i])
		{
			G[x][i]=0;
			dfs(i);
		}
}
main()
{ 
	int i,ok,flag,k,l;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d%d",&n,&r)==2)
 	{
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		memset(reg,0,sizeof(reg));
		flag=1;
		ok=1;
		for (i=0;i<r;i++)
 		{
			scanf("%d%d",&k,&l);
			G[k][l]=1;
			G[l][k]=1;
			reg[k]++;
			reg[l]++;
		}
		dfs(0);
		for (i=0;i<n;i++)
			if (!vis[i])
			{
				ok=0;
				break;
			}
		if (ok)
		{
			flag=0;
			for (i=0;i<n;i++)
			{
				if (reg[i]%2!=0)
				{
					flag=1;
					break;
				}
			}
		}
		if (!flag) printf("Possible\n");
		else printf("Not Possible\n");
	}
	return 0;
}
