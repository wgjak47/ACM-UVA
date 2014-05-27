#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
long long d[40011];
bool hasfa[40011];
vector<int> G[40011];
long long pl[40011];
const int mod=1e9+7;
void init()
{
	pl[0]=1;
	pl[1]=1; 
	for (int i=2;i<=40000;i++)
		pl[i]=pl[i-1]*i*1LL%mod;
}
int dfs(int u,int fa)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (v==fa) continue;
		d[u]+=dfs(v,u);
	}
	return d[u];
}
long long power(long long a,long long x)
{
	if (x==0) return 1;
	if (x==1) return a;
	long long tmp=power(a,x/2);
	if (x%2==0) return tmp*tmp%mod;
	else return tmp*tmp%mod*a%mod;
}
main()
{
	int n,m;
	init();
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		memset(hasfa,0,sizeof(hasfa));
		for (int i=0;i<=n;i++) G[i].clear(),d[i]=1;
		for (int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			hasfa[a]=true;
			G[b].push_back(a);
		}
		for (int i=1;i<=n;i++)
			if (!hasfa[i])
				G[0].push_back(i);
		dfs(0,-1);
		long long down=1;
		for (int i=1;i<=n;i++) down=down*d[i]%mod;
		down=power(down,mod-2);
		cout<<pl[n]*down%mod<<endl;
	}
	return 0;
}
