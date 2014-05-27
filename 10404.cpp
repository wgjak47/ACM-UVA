#include<cstdio>
#include<cstring>
bool dp[1000100];
main()
{
	int in[20];
	int M,N;	
	while (scanf("%d%d",&N,&M)==2)
	{
		memset(dp,0,sizeof(dp));
		for (int i=0;i<M;i++)
		{
			scanf("%d",&in[i]);
			dp[in[i]]=true;
		}
		for (int i=0;i<=N;i++)
		for (int j=0;j<M;j++)
			if (i>in[j] && !dp[i-in[j]])
				dp[i]=true;
		if (dp[N]) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}
