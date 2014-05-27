#include<cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) a>b?a:b
struct turtle
{
	int weight,measure;
};
int cmp(const void *a,const void *b)
{
	turtle *x=(turtle *)a;
	turtle *y=(turtle *)b;
	return x->measure-y->measure;
}
turtle input[6000];
int dp[6000];
main()
{
	int N=0;
	memset(dp,0x7f,sizeof(dp));
	while (scanf("%d%d",&input[N].weight,&input[N].measure)==2) N++;
		qsort(input,N,sizeof(turtle),cmp);
	int ans=0;
	dp[0]=0;
	for (int i=0;i<N;i++)
	for (int j=ans;j>=0;j--)
	if (dp[j]+input[i].weight<=input[i].measure && dp[j]+input[i].weight<=dp[j+1])
		dp[j+1]=dp[j]+input[i].weight,ans=max(ans,j+1);
	printf("%d\n",ans);
	return 0;
}
