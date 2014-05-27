#include<cstdio>
#include<cstring>
#include<cctype>
typedef strcut Graph
{
	int x[1000],y[1000];
	int node;
	void clear()
	{
		node=0;
	}
}G;
int value[1001][1001];
bool vis[1001][1001];
G[1001][1001][1001];
void init(int k,int j)
{
	char c=getchar();
	char temp[5000];
	if (isdigit(c))
	{
		ungetc(c,stdin);
		scanf("%d",&value[k][j]);
		vis[k][j]=true;
	}
	else if (c=='=')
	{
		
		ungetc(c,stdin);
		scanf("%s",temp);
		int l=strlen(temp);
		int i=1;
		while (i<l)
		{
			int sum=0;
			while (i<l && !isdigit(temp[i]))
			{
				sum+=(sum+1)*27+temp[i]-'A';
				i++;
			}
			int sum2=0;
			while (i<l && temp[i]!='+')
			{
				sum2+=sum*10+temp[i]-'0';
				i++;
			}
			i++;	
			int num=G[k][j].node;
			G[k][j].x[num]=sum;
			G[k][j].x[num]=sum2;
		}
	}
}
main()
{
	int total;
	scanf("%d",&total);
	while (total--)
	{
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		memset(node,0,sizeof(G));
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			inti(i,j);
	}
}
