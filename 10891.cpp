#include<cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) a>b?a:b
int data[110];
int dp[110][110];
bool vis[110][110];
int min(int a,int b)
{
	if (a<b)
		return a;
	return b;
}
int search(int l,int r)
{
	if (l>r) return 0;
	if (vis[l][r]) return dp[l][r];
	int sum=0;
	int ans=10000000;
	int temp=0;
	for (int i=l;i<=r;i++)
	{
		temp=search(i+1,r);	
		ans=min(temp,ans);
	}
	sum=0;
	for (int i=r;i>=l;i--)
	{
		sum+=data[i];
		temp=search(l,i-1);	
		ans=min(temp,ans);
	}
	vis[l][r]=true;
	return dp[l][r]=sum-ans;
}
main()
{
	int N;
	while (scanf("%d",&N) && N!=0)
	{
		memset(vis,0,sizeof(vis));
		for (int i=0;i<N;i++)
			scanf("%d",&data[i]);
		int l=0,r=N-1,sum=0;
		for (int i=0;i<N;i++)
			sum+=data[i];
		printf("%d\n",2*search(l,r)-sum);
	}
	return 0;
}
