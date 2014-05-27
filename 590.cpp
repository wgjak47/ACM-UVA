#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
#define inf	10000000	
int dp[20][1001];
int d[11][11];
int data[11][11][33];
bool vis[20][1001];
int n,k;
int kk;
int dfs(int city,int day)
{
	kk++;
	if (vis[city][day]) return dp[city][day];
	if (day==k-1)
		if (d[city][n]!=0)
		return ((data[city][n][day%d[city][n]]==0)?inf:data[city][n][day%d[city][n]]);
		else return inf;
	int temp;
	for (int i=1;i<=n;i++)
		if (i!=city)
		{
			temp=dfs(i,day+1)+((data[city][i][day%d[city][i]]==0)?inf:data[city][i][day%d[city][i]]);
			dp[city][day]=min(dp[city][day],temp);
		}
	vis[city][day]=1;
	return dp[city][day];	
}
main()
{
	int reg=0;
	while (scanf("%d%d",&n,&k)==2)
	{
		for (int i=0;i<=n+1;i++)
		for (int j=0;j<=k+1;j++)
			dp[i][j]=inf;
		memset(vis,0,sizeof(vis));
		if (n==k && k==0) break;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			scanf("%d",&d[i][j]);
			for (int k=0;k<d[i][j];k++)
				scanf("%d",&data[i][j][k]);
		}	
		printf("Scenario #%d\n",++reg);
		kk=0;
		int result=dfs(1,0);
//		printf("%d\n",kk);
		if (result>=inf)
			printf("No flight possible.\n");
		else printf("The best flight costs %d.\n",result);
		putchar('\n');
	}
	return 0;
}
