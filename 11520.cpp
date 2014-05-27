#include<cstdio>
#include<cstring>
#define edge(a,b) (a>=0 && b>=0 && b<N && a<N) 
char G[11][11];
int T,N;
bool check(char c,int i,int j)
{
	if (edge(i,j+1) && c==G[i][j+1]) return false;
	if (edge(i+1,j) && c==G[i+1][j]) return false;
	if (edge(i,j-1) && c==G[i][j-1]) return false;
	if (edge(i-1,j) && c==G[i-1][j]) return false;
	return true;
}
main()
{
	scanf("%d",&T);
	int reg=0;
	while (T--)
 	{
		scanf("%d",&N);
		getchar();
		for (int i=0;i<N;i++)
			gets(G[i]);
		for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		if (G[i][j]!='.') continue;
		else
		{
			for (char k='A';k<='Z';k++)
				if (check(k,i,j))
				{
					G[i][j]=k;
					break;
				}
 		}
		printf("Case %d:\n",++reg);
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
				putchar(G[i][j]);
			putchar('\n');
		}
 	}	
	return 0;
}
