#include<cstdio>
#include<cstring>
int in[510][8];
int dp[510][8];
int opp[8]={1,0,3,2,5,4};
int road[510][8][2];
char lt[8][10]={"front","back","left","right","top","bottom"};
main()
{
	int N;
	int s,p;
	int T=0;
	while (scanf("%d",&N)==1)
	{ 
		if (N==0) break;
		if (T) putchar('\n');
		printf("Case #%d\n",++T);
		for (int i=0;i<N;i++)
		for (int j=0;j<6;j++)
			scanf("%d",&in[i][j]);
	//	for (int j=0;j<6;j++)
	//		dp[0][j]=1;
		int max=0;
		memset(dp,0,sizeof(dp));
		memset(road,-1,sizeof(road));
		for (int i=0;i<6;i++)
			dp[N-1][i]=1;
		for (int i=N-2;i>=0;i--)
		for (int j=0;j<6;j++)
		{
			dp[i][j]=1;
			for (int k=i+1;k<N;k++)
			for (int l=0;l<6;l++)
				if (in[i][opp[j]]==in[k][l] && dp[i][j]<dp[k][l]+1)
				{
					dp[i][j]=dp[k][l]+1;	
					road[i][j][0]=k;
					road[i][j][1]=l;
					if (dp[i][j]>max)
					{
						max=dp[i][j];
						s=i;
						p=j;	
					}
			}
		}
		printf("%d\n",max);
		while (1)
		{
			printf("%d %s\n",s+1,lt[p]);
			if (road[s][p][0]==-1) break;
			int temp=road[s][p][0];
			p=road[s][p][1];
			s=temp;
		}
	}	
	return 0;
}
