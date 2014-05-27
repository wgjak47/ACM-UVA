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
const int maxn=100010;
int age[maxn];
struct TwoSAT
{
	int n;
	vector<int> G[maxn*2];
	bool mark[maxn*2];
	int S[maxn*2],c;
	bool dfs(int x)
	{
		if (mark[x^1]) return false;
		if (mark[x]) return true;
		mark[x]=true;
		S[c++]=x;
		for (int i=0;i<G[x].size();i++)
			if (!dfs(G[x][i])) return false;
		return true;
	}
	void init(int n)
	{
		this->n=n;
		for (int i=0;i<n*2;i++)  G[i].clear();
		memset(mark,0,sizeof(mark));
	}
	void add_clause(int x,int xval,int y,int yval)
	{
		x=x*2+xval;
		y=y*2+yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	bool solve()
	{
		for (int i=0;i<n*2;i+=2)
			if (!mark[i] && !mark[i+1])
			{
				c=0;
				if (!dfs(i))
				{
					while (c>0) mark[S[--c]]=false;
					if (!dfs(i+1)) return false;
				}
			}
		return true;
	}
};
TwoSAT solver;
main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)==2)
	{
		if (m==0 && n==0) break;
		int sum=0;
		for (int i=0;i<n;i++)
		{
			scanf("%d",&age[i]);
			sum+=age[i];
		}
		int average=sum/n;
		solver.init(n);
		for (int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			if ((age[u]<average)==(age[v]<average))
			{
				solver.add_clause(u,1,v,1);
				solver.add_clause(u,0,v,0);
			}
			else 
				solver.add_clause(u,1,v,1);
		}
		if (solver.solve())
		for (int i=0;i<n;i++)
		{
			if (!solver.mark[i*2])
			{
				if (age[i]<average) printf("B\n");
				else printf("A\n");
			}
			else 
				printf("C\n");
		}
		else printf("No solution.\n");
	}
	return 0;
}
