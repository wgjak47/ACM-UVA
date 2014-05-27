#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int V[]={1,5,10,25,50};
long long dp[30010];
main()
{
	int N;
	dp[0]=1;
	for (int i=0;i<5;i++)
	for (int j=0;j<=30001;j++)
		if (j>=V[i])
			dp[j]+=dp[j-V[i]];
	while (scanf("%d",&N)==1)
	{
		if (dp[N]==1)
			printf("There is only %lld way to produce %d cents change.\n",dp[N],N);
		else printf("There are %lld ways to produce %d cents change.\n",dp[N],N);
	}
	return 0;
}
