#include<stdio.h>
#include<string.h>
#define INF 1000000
int N;
int f[100];
int in[100];
int data[100];
int dp[100];
int init()
{
	int i,m;
	for (i=1;i<=N;i++)
	{
		if (scanf("%d",&m)==EOF) return 0;
		data[m]=i;
	}
	for (i=1;i<=N;i++)
		data[i]=f[data[i]];
	return 1;
}
int solve()
{
	int i,j,k,l;
	memset(dp,0,sizeof(dp));
	int result=0;
    for (i=N-1;i>=1;i--)
	{
		int max=0;
		for (j=i+1;j<=N;j++)
		if (data[i]<data[j])
		{
			int	temp=dp[j]+1;
			if (temp>max)
				max=temp;
		}	
		dp[i]=max;
		if (result<dp[i]) result=dp[i];
	}
	return result+1;
}
main()
{
	int i,j,k,l,m,n;
	scanf("%d",&N);
	for (i=1;i<=N;i++)
	{
		scanf("%d",&m);
		f[i]=m;
	}
	while (init())
		printf("%d\n",solve());
	return 0;
}
