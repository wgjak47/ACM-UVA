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
const int maxn=10010;
struct Edge
{
	int u,v;
};
vector<int> G[maxn],bcc[maxn];
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
stack<Edge> S;
int reg[maxn];
struct out
{
	int num,w;
	bool operator<(const out &a) const
	{
		if (w==a.w)
			return num<a.num;
		return w>a.w;
	}
};
out output[maxn];
int dfs(int u,int fa)
{ 
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		Edge e=(Edge){u,v};
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
				while (1)
				{
					Edge x=S.top();S.pop();
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
	memset(pre,0,sizeof(pre));
	memset(iscut,0,sizeof(iscut));
	memset(bccno,0,sizeof(bccno));
	dfs_clock=bcc_cnt=0;
	for (int i=0;i<n;i++)
		if (!pre[i]) dfs(i,-1);
} 
void solve(int n)
{
	find_bcc(n);
	memset(&output,0,sizeof(output));
	memset(reg,0,sizeof(reg));
	for (int i=1;i<=bcc_cnt;i++)
	for (int j=0;j<bcc[i].size();j++)
	{
		int u=bcc[i][j];
		reg[u]++;
	}
	for (int i=0;i<n;i++)
	{
		output[i].num=i;
		output[i].w=reg[i];
	}
	sort(output,output+n);
}
main()
{
	int m,n;
	while (scanf("%d%d",&n,&m)==2)
	{
		int x,y;
		if (n==0 && m==0) break;
		pf(i,0,n) G[i].clear();
		while (scanf("%d%d",&x,&y)==2)
		{
			if (x==-1 && y==-1) break;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		solve(n);
		for (int i=0;i<m;i++)
			printf("%d %d\n",output[i].num,output[i].w);
		putchar('\n');
	}
	return 0;
}
