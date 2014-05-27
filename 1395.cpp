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
int u[maxn*maxn],v[maxn*maxn],w[maxn*maxn];
int r[maxn*maxn];
int p[maxn];
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
bool cmp(const int a,const int b){return w[a]<w[b];}
int ans;
const int INF=1e9;
bool solver(int m,int N,int max_edge)
{
	int reg=0;
	int min_edge=INF;
	mf(k,m-1,-1)
	{
		int i=r[k];
		int x=find(u[i]);
		int y=find(v[i]);
		if (x!=y)
		{
			p[x]=y;
			reg++;
			min_edge=min(min_edge,w[i]);
		}
	}
	if (reg==N-2)
	{
		if (ans==-1) ans=INF;
		ans=min(max_edge-min_edge,ans);
		return true;
	}
	return false;
}
main()
{
	int N,M;
	while (scanf("%d%d",&N,&M)==2)
	{
		if (N==0 && M==0) break;
		pf(i,0,M)
		{
			r[i]=i;
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			u[i]--,v[i]--;
		}
		if (M==0)
		{
			printf("-1\n");
			continue;
		}
		if (M==1 && N==2)
		{
			printf("0\n");
			continue;
		}
		if (M==1 && N!=2)
		{
			printf("-1\n");
			continue;
		}
		ans=-1;
		sort(r,r+M,cmp);
		mf(k,M-1,-1)
		{
			int i=r[k];
			pf(j,0,N)
				p[j]=j;
			p[u[i]]=v[i];
			if (!solver(k,N,w[i])) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
