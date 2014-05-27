#include<cstdio>
#include<cstring>
#include<cstdlib>
int N;
char dp[110][65012];
int in[110];
char s[110];
int goal;
void solve()
{
	memset(dp,0,sizeof(dp));
	memset(s,0,sizeof(s));
	dp[N][goal+32000]='e';
	for (int i=N-1;i>0;i--)
	for (int j=-32000;j<=32000;j++)
	{
		if (j+in[i]<=32000 && j+in[i]>=-32000 && dp[i+1][j+in[i]+32000])
			dp[i][j+32000]='+';
		if (j-in[i]<=32000 && j-in[i]>=-32000 && dp[i+1][j-in[i]+32000])
			dp[i][j+32000]='-';
		if (in[i]!=0 && j/in[i]<=32000 && j/in[i]>=-32000 && dp[i+1][j/in[i]+32000])
			dp[i][j+32000]='/';
		if (j*in[i]<=32000 && j*in[i]>=-32000 && dp[i+1][j*in[i]+32000])
			dp[i][j+32000]='*';
	}
	if (!dp[1][in[0]+32000]) printf("NO EXPRESSION\n");
	else 
	{
		int sum=in[0];
		for (int i=1;i<N;i++)
		{
			s[i]=dp[i][sum+32000];
			switch(s[i])
			{
				case '+':sum+=in[i];break;
				case '-':sum-=in[i];break;
				case '*':sum*=in[i];break;
				case '/':sum/=in[i];break;
			}
		}
		for (int i=0;i<N;i++)
		{
			printf("%d",in[i]);
			if (i!=N-1) putchar(s[i+1]);	
		}	
		printf("=%d\n",goal);
	}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (int i=0;i<N;i++)
			scanf("%d",&in[i]);
		scanf("%d",&goal);
		solve();
	}
}
