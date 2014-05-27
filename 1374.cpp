#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)<(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
struct ss
{
	int value,i;
	vector<int> p;
};
int bfs(int N)
{
	queue<ss> q;
	bool vis[2100];
	memset(vis,0,sizeof(vis));
	q.push((ss){1,0});
	vis[1]=1;
	while (!q.empty())
	{
		int l=p.size();
		if (q.front().value==N) 
			return q.front().i;
		pf(i,0,l) 
		{
			if (q.front().value+p[i]==N) 
				return q.front().i+1;
			if (!vis[q.front().value+p[i]])
			{
				q.push((ss){q.front().value+p[i],q.front().i+1});
				p.push_back(q.front().value+p[i]);
				vis[q.front().value+p[i]]=1;
			}
		}
		if (q.front().i==12)
			return 13;
		q.pop();
	}
}
main()
{
	int N;
	while (scanf("%d",&N)==1 && N!=0)
	{
		int ans=bfs(N);
		printf("%d\n",ans);
	}
	return 0;
}
