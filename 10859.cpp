#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
vector<int> adj[1010];
bool vis[1010][2];
int d[1010][2],n,m;
int dp(int i,int j,int f)
{
	if (vis[i][j]) return d[i][j];
	vis[i][j]=true;
	int &ans=d[i][j];
	ans=2000;
	for (int k=0;k<adj[i].size();k++)
		if (adj[i][k]!=f)
			ans+=dp(adj[i][k],1,i);
	if (!j && f>=0) ans++;
	if (j || f<0)
	{
		int sum=0;
		for (int k=0;k<adj[i].size();k++)
			if (adj[i][k]!=f)
				sum+=dp(adj[i][k],0,i);
		if (f>=0) sum++;
		ans=min(ans,sum);
	}
	return ans;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) adj[i].clear();
		for (int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(vis,0,sizeof(vis));
		int ans=0;
		for (int i=0;i<n;i++)
			if (!vis[i][0])
				ans+=dp(i,0,-1);
		printf("%d %d %d\n",ans/2000,m-ans%2000,ans%2000);
	}
	return 0;
}
