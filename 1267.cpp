#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
vector<int> G[1010];
int deep[1010];
vector<int> terminal;
int fa[1010];
bool vis[1010];
bool reachable[1010];
void init_tree(int N,int S,int K,int d)
{
	deep[S]=d;
	for (int i=0;i<G[S].size();i++)
	if (G[S][i]!=fa[S])
	{
		fa[G[S][i]]=S;
		init_tree(N,G[S][i],K,d+1);
	}
	if (G[S].size()==1) terminal.push_back(S);
}
int find(int a,int K)
{
	if (K==0) return a;
	return find(fa[a],K-1);
}
void mark(int f,int K)
{
	vis[f]=true;
	if (G[f].size()==1) {reachable[f]=true;return ;}
	if (K==0) return ;
	for (int i=0;i<G[f].size();i++)
			if (!vis[G[f][i]])
				mark(G[f][i],K-1);
}
main()
{
	int T;
	int N,S,K;
	scanf("%d",&T);
	while (T--)
	{
		memset(fa,-1,sizeof(fa));
		memset(vis,0,sizeof(vis));
		memset(reachable,0,sizeof(reachable));
		scanf("%d%d%d",&N,&S,&K);
		for (int i=1;i<=N;i++)
				G[i].clear();
		terminal.clear();
		memset(deep,0,sizeof(deep));
		int u,v;
		for (int i=0;i<N-1;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		init_tree(N,S,K,0);
		mark(S,K);
//		printf("init\n");
		int ans=0;
		while (1)
		{
			memset(vis,0,sizeof(vis));
			int max=-1,lt;
			for (int i=0;i<terminal.size();i++)
			{
				if (!reachable[terminal[i]] && deep[terminal[i]]>max)
				{
//						printf("%d ",terminal[i]);
						max=deep[terminal[i]];
						lt=terminal[i];
				}
			}
			if (max==-1) break;
			int father=find(lt,K);
//			printf("father\n");
			mark(father,K);
//			printf("mark\n");
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
