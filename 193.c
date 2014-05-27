#include<stdio.h>
#include<string.h>
int m,n;
int G[110][110];
int node[110];
int color[110];
int max;
int stack[110];
int result[110];
void dfs(int reg,int black)
{
	int i,j;
	int ok=1;
	if (reg==m+1) 
	{
		if (black>max) 
		{
			max=black;
			memcpy(result,stack,sizeof(int)*black);
		}
		return ;
	}
	for (i=0;i<node[reg];i++)
		if (color[G[reg][i]]==1) {ok=0;break;}
	if (ok) 
	{
		stack[black]=reg;
		color[reg]=1;
		dfs(reg+1,black+1);
	}
	color[reg]=0;
	dfs(reg+1,black);
}
main()
{
	int i,j,k,l;
	int N;
/*	freopen("in.txt","r",stdin);*/
	scanf("%d",&N);
	while (N--)
	{
		max=0;
		memset(stack,0,sizeof(stack));
		memset(result,0,sizeof(result));
		memset(node,0,sizeof(node));
		memset(color,0,sizeof(color));
		scanf("%d%d",&m,&n);
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&k,&l);
			G[k][node[k]++]=l;
			G[l][node[l]++]=k;
		}
		dfs(1,0);
		printf("%d\n",max);
		for (i=0;i<max;i++)
		{
			printf("%d",result[i]);
			if (i!=max-1) putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
