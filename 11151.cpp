#include<cstdio>
#include<cstring>
int dp[2][1001];
main()
{
	char s[1001];
	char sd[1001];
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(s);
		int l=strlen(s);
		int k=0;
		for (int i=l-1;i>=0;i--)
			sd[k++]=s[i];
		sd[k]='\0';
		memset(dp,0,sizeof(dp));
		bool x=true;
		for (int i=1;i<=l;i++)
		{
			for (int j=1;j<=l;j++)
			{
			if (s[i-1]==sd[j-1])
				dp[x][j]=dp[!x][j-1]+1;
			else if (dp[!x][j]>dp[x][j-1])
				dp[x][j]=dp[!x][j];
			else dp[x][j]=dp[x][j-1];
			}	
			x=!x;
		}
		printf("%d\n",dp[!x][l]);
	}
}
