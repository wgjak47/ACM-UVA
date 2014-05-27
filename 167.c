#include<stdio.h>
#include<string.h>
int score;
int G[10][10];
int lei[10],xie1[100],xie2[100];
void queen(int reg,int sum)
{
	int i;
	if (reg==8)
	{
		if (sum>score) score=sum;
	}
	else for (i=0;i<8;i++)
	{
		if (!lei[i] && !xie1[i+reg] && !xie2[i-reg+8])
		{
			lei[i]=xie1[i+reg]=xie2[i-reg+8]=1;
			queen(reg+1,sum+G[reg][i]);
			lei[i]=xie1[i+reg]=xie2[i-reg+8]=0;
		}
	}
}
main()
{ 
	int i,j,k,l,m,n;
	scanf("%d",&n);
	while (n--)
	{
		score=0;
		memset(lei,0,sizeof(lei));
		memset(xie1,0,sizeof(xie1));
		memset(xie2,0,sizeof(xie2));
		memset(G,0,sizeof(G));
		for (i=0;i<8;i++)
		for (j=0;j<8;j++)
			scanf("%d",&G[i][j]);
		queen(0,0);
		printf("%5d\n",score);
	} 
	return 0;
}
