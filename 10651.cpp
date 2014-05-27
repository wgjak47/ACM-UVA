#include<cstdio>
#include<cstring>
bool in[20];
int dp[(1<<13)+2];
int dfs(int n)
{
	int temp;
	int t=-1;
	int reg=-1;
	if (dp[n]!=-1) return dp[n]; 
	for (int i=0;i<10;i++)
		if ((n&(1<<i))==0 && n&(1<<(i+1)) && n&(1<<(i+2)))
		{
			temp=n;
			temp=temp|(1<<i);
			temp=temp^(1<<(i+1));
			temp=temp^(1<<(i+2));
			t=dfs(temp);
			if (t<reg || reg==-1) reg=t;
		}
		else if (n&(1<<i) && n&(1<<(i+1)) && (n&(1<<(i+2)))==0)
		{
			temp=n;
			temp=temp^(1<<i);
			temp=temp^(1<<(i+1));
			temp=temp|(1<<(i+2));
			t=dfs(temp);
			if (t<reg || reg==-1) reg=t;
		}	
	if (reg==-1)
	{
		reg=0;
		for (int i=0;i<12;i++)
		if ((n&(1<<i))!=0) reg++;
	}
	if (reg<dp[n] || dp[n]==-1)
		dp[n]=reg;
	return dp[n];
}
int solve()
{
	int key=0;
	for (int i=11;i>=0;i--)
		key=key*2+in[i];
	if (dp[key]==-1)
		dfs(key);
	return dp[key];
}
main()
{
	char c;
	int N;
	scanf("%d",&N);
	while (N--)
	{
		getchar();
		for (int i=0;i<12;i++)
		{
			c=getchar();
			if (c=='o') in[i]=true;
			else in[i]=false;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",solve());
	}
	return 0;
}
