/*
 *			{0 j-i<2 the size is less than 2
 * dp[i,j]= {dp[i+1,j-1] Si==Sj
 *			{1+min(dp[i+1,j-1](删除),dp[i,j-1],dp[i-1,i](替换)) otherwise
 *			*/
#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
int dps[1001][1001];
bool vis[1001][1001];
int dp(char *s,int x,int y)
{
	if (vis[x][y]) return dps[x][y];
		vis[x][y]=true;
	if (x>=y) return dps[x][y]=0;
	if (s[x]==s[y]) return dps[x][y]=dp(s,x+1,y-1);
	else 
	{
		int a=dp(s,x+1,y-1)+1,b=dp(s,x+1,y)+1,c=dp(s,x,y-1)+1;
		dps[x][y]=min(a,b);
		dps[x][y]=min(c,dps[x][y]);
		return dps[x][y];
	}
}
main()
{
	int T;
	char input[1001];
	char input_t[1001];
	scanf("%d",&T);
	getchar();
	int reg=0;
	while (T--)
	{
		gets(input);	
		int l=strlen(input);
		memset(vis,0,sizeof(vis));
		memset(dps,0x7f,sizeof(dps));
		printf("Case %d: %d\n",++reg,dp(input,0,l-1));
	}
	return 0;
}
