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
char s[30];
int z[30];
int reg[30];
bool vis[30];
void dfs(int i,int sum)
{
	if (vis[i])
	{
		reg[sum]++;
		return ;
	}
	vis[i]=true;
	dfs(z[i],sum+1);
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(reg,0,sizeof(reg));
		memset(vis,0,sizeof(vis));
		scanf("%s",s);
		for (int i=0;i<26;i++)
			z[i]=s[i]-'A';
		for (int i=0;i<26;i++)
			dfs(i,0);
		bool ok=true;
		for (int i=2;i<=26;i+=2)
		{
			if (reg[i]%2) ok=false;
			//printf("%d %d\n",i,reg[i]);
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}
