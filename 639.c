#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char G[10][10];
int a[5][2]={{0,1},{1,0},{-1,0},{0,-1}};
int max;
int vis[10][10];
int n;
int judge_fuck(int x,int y)
{
	if (G[x][y]=='X') return 0;
	int i,j,k,l;
	l=y;
	while (G[x][l]!='X')
	{
		l++;
		if (G[x][l]=='F')
			return 0;
	}
	l=y;
	while (G[x][l]!='X')
	{
		l--;
		if (G[x][l]=='F')
			return 0;
	}
	l=x;
	while (G[l][y]!='X')
	{
		l++;
		if (G[l][y]=='F')
			return 0;
	}
	l=x;
	while (G[l][y]!='X')
	{
		l--;
		if (G[l][y]=='F')
			return 0;
	}
	return 1;
}
void dfs_fuck(int x,int y,int reg)
{
	int i,j,k,l;
	if (!vis[x][y])
	{
		vis[x][y]=1;
		if (judge_fuck(x,y))
		{
			G[x][y]='F';
			for (i=0;i<4;i++)
				if (x+a[i][0]>0 &&x+a[i][0]<=n && y+a[i][1]>0 & y+a[i][1]<=n)
				dfs_fuck(x+a[i][0],y+a[i][1],reg+1);
			G[x][y]='.';
		}
		for (i=0;i<4;i++)
			if (x+a[i][0]>0 &&x+a[i][0]<=n && y+a[i][1]>0 & y+a[i][1]<=n)
			dfs_fuck(x+a[i][0],y+a[i][1],reg);
		vis[x][y]=0;
	}
	if (reg>max) max=reg;
}
main()
{
	int i,j,k,l;
/*	freopen("in.txt","r",stdin);*/
	while(scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
		max=0;
		memset(G,'X',sizeof(G));
		getchar();
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			scanf("%c",&G[i][j]);
				getchar();
		}
		if (n!=1)
		dfs_fuck(1,1,0);
		else 
		{
			if (G[1][1]=='.')
				max=1;
			else max=0;
		}
		printf("%d\n",max);
	}
	return 0;
}
