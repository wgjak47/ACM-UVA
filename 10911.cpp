#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
double dp[(2<<16)+10];
double distant[20][20];
bool vis[(2<<16)+10];
double cal(int x1,int y1,int x2,int y2)
{
	double a=x1,b=y1,c=x2,d=y2;
	return sqrt(((a-c)*(a-c)+(b-d)*(b-d)));
}
void solve(int N)
{
	queue<int> data;
	data.push(0); dp[0]=0;		
	while (!data.empty())
	{
		int k=data.front();	
		for (int i=0;i<N;i++)
		for (int j=i+1;j<N;j++)
		if ((k&(1<<i))==0 && (k&(1<<j))==0)
		{
			int last=data.front();
			k=k|(1<<i),k=k|(1<<j);
			if (!vis[k])
			{
				dp[k]=dp[last]+distant[i][j];
				vis[k]=true;
				data.push(k);
			}
			else dp[k]=min(dp[k],dp[last]+distant[i][j]);
			k=last;
		}
		data.pop();
	}
}
main()
{
	int N;
	int x[20],y[20];
	char s[100];
	int cases=1;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		getchar();
		for (int i=0;i<N*2;i++)
			scanf("%s%d%d",s,&x[i],&y[i]);
		for (int i=0;i<N*2;i++)
		for (int j=i+1;j<N*2;j++)
			distant[i][j]=cal(x[i],y[i],x[j],y[j]);
		solve(N*2);
		printf("Case %d: %.2f\n",cases++,dp[(1<<(N*2))-1]);
	}
	return  0;
}
