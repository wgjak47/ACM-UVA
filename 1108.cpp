#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
const int maxn=5*10000+10;
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> G[maxn],bcc[maxn];
struct Edge
{
	int u,v;
};
stack<Edge> S;
int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	pf(i,0,G[u].size())
	{
		int v=G[u][i];
		Edge e;
		e=u;
		e=v;
		if (!pre[v])
		{
			S.push(e);
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if (lowv>=pre[u])
			{
				iscut[u]=true;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				for(;;)
				{
					Edge x=S.top();
					S.pop();
					if (bccno[x.u]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.u);
						bccno[x.u]=bcc_cnt;
					}
					if (bccno[x.v]!=bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.v);
						bccno[x.v]=bcc_cnt;
					}
					if (x.u==u && x.v==v) break;
				}
			}
		}
		else if (pre[v]<pre[u] && v!=fa)
		{
			S.push(e);
			lowu=min(lowu,pre[v]);
		}
	}
		if (fa<0 && child==1) iscut[u]=0;
		return lowu;
}
void find_bcc(int n)
{
	mt(pre,0);
	mt(iscut,0);
	mt(bccno,0);
	dfs_clock=bcc_cnt=0;
	pf(i,1,n+1)
		if (!pre[i]) dfs(i,-1);
}
main()
{
	int N;
	int kase=0;
	while (scanf("%d",&N) && N)
	{
		int n=0;
		pf(i,0,N)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			n=max(n,u);
			n=max(n,v);
		}
		find_bcc(n);
		long long ans1=0,ans2=1;
		if (bcc_cnt==1)
		{
			ans1=2;
			ans2=bcc[1].size()*(bcc[1].size()-1)/2;
		}
		else
		for (int i=1;i<=bcc_cnt;i++)
		{
			int cut_cnt=0;
			for (int j=0;j<bcc[i].size();j++)
				if (iscut[bcc[i][j]]) cut_cnt++;
			if (cut_cnt==1)
			{
				ans1++;
				ans2*=1LL*(bcc[i].size()-cut_cnt);
			}
		}
		printf("Case %d: %lld %lld\n",++kase,ans1,ans2);
		pf(i,0,n+1) G[i].clear();
	}
	return 0;
}
