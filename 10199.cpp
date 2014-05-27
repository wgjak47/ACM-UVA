#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define mt(a) memset(a,0,sizeof(a))
using namespace std;
char s[110][40];
int G[111][111];
bool vis[110];
int point[110];
int p;
vector<int> start;
bool cmp(int a,int b)
{
	return strcmp(s[a],s[b])<0;
}
void dfs(int k,int n)
{
	vis[k]=true;
	for (int i=0;i<n;i++)
		if (!vis[i] && G[k][i]) dfs(i,n);
}
void find(int n)
{
	mt(vis);
	for (int i=0;i<n;i++)
		if (!vis[i])
		{
			dfs(i,n);
			start.push_back(i);
		}
}
void solve(int n)
{
	for (int i=0;i<n;i++)
	{
		mt(vis);
		vis[i]=true;
		for (int j=0;j<start.size();j++)
			if (i!=start[j])
			dfs(start[j],n);
			else for (int k=0;k<n;k++)
				if (G[start[j]][k])
				{
					dfs(k,n);
					break;
				}
		bool yes=false;
		for (int j=0;j<n;j++)
			if (!vis[j]) {yes=true;break;}
		if (yes) point[p++]=i;
	}
}
main()
{
	int N,M;
	int cases=0;
	while (scanf("%d",&N)==1,N!=0)
	{
		p=0;
		if (cases) putchar('\n');
		getchar();
		start.clear();
		for (int i=0;i<N;i++)
		scanf("%s",s[i]);
		scanf("%d",&M);
		getchar();
		mt(G);
		char a1[40],a2[40];
		for (int i=0;i<M;i++)
		{
			int u,v;
			scanf("%s%s",a1,a2);
			for (int i=0;i<N;i++)
				if (!strcmp(a1,s[i])) {u=i;break;}
			for (int i=0;i<N;i++)
				if (!strcmp(a2,s[i])) {v=i;break;}
			G[u][v]=G[v][u]=1;
		}
		find(N);
		solve(N);
		printf("City map #%d: %d camera(s) found\n",++cases,p);
		sort(point,point+p,cmp);
		for (int i=0;i<p;i++)
		printf("%s\n",s[point[i]]);
	}
	return 0;
}
