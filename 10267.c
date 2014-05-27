#include<stdio.h>
#include<string.h>
char G[300][300];
int M,N;
void C()
{
	int i,j;
	for (i=1;i<=N;i++)
	for (j=1;j<=M;j++)
		G[i][j]='O';
}
void I()
{
	int i,j;
	scanf("%d%d",&M,&N);
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)
			G[i][j]='O';
}
void L()
{
	int X,Y;
	char color;
	scanf("%d%d",&X,&Y);
	while (color=getchar(),color==' ');
	if (X<=M && Y<=N)
		G[Y][X]=color;
}
void V()
{
	int X,Y1,Y2;
	int temp;
	char color;
	int i;
	scanf("%d%d%d",&X,&Y1,&Y2);
	if (X>M || Y1>N || Y2>N) return ;
	while (color=getchar(),color==' ');
	if (Y1>Y2) 
	{
		temp=Y1;
		Y1=Y2;
		Y2=temp;
	}
	for (i=Y1;i<=Y2;i++)
		G[i][X]=color;
}
void H()
{
	int Y,X1,X2;
	int temp;
	char color;
	int i;
	scanf("%d%d%d",&X1,&X2,&Y);
	if (X1>M || X2>M || Y>N) return ;
	while (color=getchar(),color==' ');
	if (X1>X2) 
	{
		temp=X1;
		X1=X2;
		X2=temp;
	}
	for (i=X1;i<=X2;i++)
		G[Y][i]=color;
}
void K()
{
	int X1,X2,Y1,Y2;
	char color;
	int i,j,k;
	int temp;
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	while (color=getchar(),color==' ');
	if (X1>M || X1>M || Y1>N || Y2>N)
		return ;
	if (X1>X2)
	{
		temp=X1;
		X1=X2;
		X2=temp;
	}
	if (Y1>Y2)
	{
		temp=Y1;
		Y1=Y2;
		Y2=temp;
	}
	for (j=Y1;j<=Y2;j++)
		for (i=X1;i<=X2;i++)
			G[j][i]=color;
}
void dfs(int Y,int X,char color,char last)
{
	if (G[Y][X]==last)
	{
		G[Y][X]=color;
		if (Y+1<=N)
		dfs(Y+1,X,color,last);
		if (Y-1>0)
		dfs(Y-1,X,color,last);
		if (X+1<=M)
		dfs(Y,X+1,color,last);
		if (X-1>0)
		dfs(Y,X-1,color,last);
	}
}
void F()
{
	int X,Y;
	char color;
	scanf("%d%d",&X,&Y);
	while (color=getchar(),color==' ');
	if (X<=M && Y<=N && G[Y][X]!=color)
	dfs(Y,X,color,G[Y][X]);
}
void S()
{
	char s[1000];
	int i,j;
	scanf("%s",s);
	puts(s);
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		putchar(G[i][j]);
		putchar('\n');
	}
}
main()
{
	char com;
/*	freopen("data.txt","r",stdin);*/
	while (com=getchar())
	{
		switch (com)
		{
			case 'X': return 0;
			case 'I': I();break; 
			case 'L': L();break;
			case 'S': S();break;
			case 'C': C();break;
			case 'V': V();break;
			case 'H': H();break;
			case 'F': F();break;
			case 'K': K();break;
			default:break;
		}
	}
	return 0;
}
