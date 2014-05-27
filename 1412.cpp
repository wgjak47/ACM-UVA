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
const int maxn=110;
vector<int> G[maxn];
int f[2*maxn][maxn];
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N,M;	
		scanf("%d%d",&N,&M);
		memset(f,0x7f,sizeof(f));
		pf(i,1,N+1) 
		{
			G[i].clear();
			G[i].push_back(i);
		}
		pf(i,0,M)
		{
			int v,u;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int l;
		scanf("%d",&l);
		pf(u,1,N+1) f[0][u]=0;
		pf(i,1,l+1)
		{
			int city;
			scanf("%d",&city);
			pf(u,1,N+1)
			pf(j,0,G[u].size())
			{
				int v=G[u][j];
				f[i][v]=min(f[i][v],f[i-1][u]+(v!=city));
			}
		}
		int ans=1e9;
		pf(u,1,N+1)
			ans=min(ans,f[l][u]);
		printf("%d\n",ans);
	}
	return 0;
}
