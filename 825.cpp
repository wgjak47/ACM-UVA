#include<cstdio>
#include<cstring>
#include<cctype>
int G[101][101];
void init()
{
	char c;
	int t[1010];
	int reg=0;
	while (1)
	{
		c=getchar();
		if (c=='\n') break;	
		else 
		{
			ungetc(c,stdin);
			scanf("%d",&t[reg++]);
		}
	}
	for (int i=1;i<reg;i++)
		G[t[0]][t[i]]=0;
}
/*void init()
{
	int first;
	scanf("%d",&first);
	int sum=0;
	char s[10010];
	gets(s);
	int l=strlen(s);
	for (int i=0;i<l;i++)
	{
		if (s[i]==' ') 
		{
			G[first][sum]=0;	
			sum=0;
		}
		else sum=sum*10+s[i]-'0';
	}
	if (sum) G[first][sum]=0;
}*/
main()
{
	int T;
	int M,N;
	scanf("%d",&T);
	while (T--)
	{
		memset(G,0,sizeof(G));
		scanf("%d%d",&M,&N);	
		getchar();
	/*	G[1][1]=1;
		vis[1][1]=true;*/
		for (int i=1;i<=M;i++)
		for (int j=1;j<=N;j++)
			G[i][j]=1;
		for (int i=0;i<M;i++)
			init();
		for (int i=M;i>0;i--)
		for (int j=N;j>0;j--)
			if (i==M && j==N) continue;
		else 
			if (G[i][j])
			G[i][j]=G[i+1][j]+G[i][j+1];
		printf("%d\n",G[1][1]);
		if (T) putchar('\n');
	}
	return 0;
}
