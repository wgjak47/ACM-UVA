#include<cstdio>
#include<cstring>
#include<stdlib.h>
#define min(a,b) a<b?a:b
#define INF 1010000
int N;
struct max
{
	int x,y;
};
max data[20];
int dp[20][20];
void solve(int N)
{
	for (int i=0;i<N;i++)
	for (int j=i+1;j<N;j++)
	{
		for (int k=i;k<j;k++)
		dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+data[k].x*data[k].y*data[k+1].y);
	}
	printf("%d\n",dp[0][N-1]);
}
main()
{
	int N;
	while (scanf("%d",&N),N!=0)
	{
		for (int i=0;i<N;i++)
			scanf("%d%d",&data[i].x,&data[i].y);
		solve(N);	
	}	
	return 0;
}
