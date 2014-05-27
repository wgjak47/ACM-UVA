#include<stdio.h>
#include<string.h>
char s[104][104];	
int flag[104][104];
void find (int x,int y)
{
	if (flag[x][y] || s[x][y]=='*') return ;
	flag[x][y]=1;
    find(x+1,y);
	find(x+1,y+1);
	find(x+1,y-1);
	find(x,y+1);
	find(x,y-1);
	find(x-1,y-1);
	find(x-1,y);
	find(x-1,y+1);
}
main()
{
	int x,y,i,j,k,l,m,n,reg;
/*	freopen("in.txt","r",stdin);*/
    while (scanf("%d%d",&m,&n))
	{
		reg=0;
		if (m==0 && n==0) break;
		for (i=0;i<=m+1;i++)  { s[i][0]='*';s[i][n+1]='*';}
		for (j=0;j<=n+1;j++)  { s[0][j]='*';s[m+1][j]='*';}
		memset(flag,0,sizeof(flag));
		getchar();
		for (i=1;i<=m;i++)
		{
			for (j=1;j<=n;j++)
				scanf("%c",&s[i][j]);
			getchar();
		}
		for (i=1;i<=m;i++)
			for (j=1;j<=n;j++)
			if (!flag[i][j] && s[i][j]=='@')
			{
				reg++;find(i,j);
			}
		printf("%d\n",reg);
	}
	return 0;
}

