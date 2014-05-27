#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
#define MAX 10000*2000
int dp[110][210];
main()
{
	int T;
	char s[100];
	int dis[110],price[110];
	scanf("%d",&T);
	while (T--)
	{
		int N;
		memset(dp,0x7f,sizeof(dp));
		dp[0][100]=0;
		bool IM=false;
		scanf("%d",&N);
		getchar();
		int k=1;
		dis[0]=0,price[0]=0;
		while (gets(s)!=NULL)
		{
			if (strlen(s)==0) break;
			sscanf(s,"%d%d",&dis[k],&price[k]);
			k++;
		}
		while (dis[k-1]>N) k--;
		for (int i=1;i<k;i++)
		for (int j=0;j<=200;j++)
		{
			for (int l=0;l<=j;l++)
			if (dis[i]-dis[i-1]+l<=200)
			dp[i][j]=min(dp[i][j],dp[i-1][dis[i]-dis[i-1]+l]+(j-l)*price[i]);
		}
		if (dp[k-1][100+N-dis[k-1]]>10000*2000 || N-dis[k-1]>100)
		printf("Impossible\n");
		else 
		printf("%d\n",dp[k-1][100+N-dis[k-1]]);
		if (T) putchar('\n');
	}
	return 0;
}
