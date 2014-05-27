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
int ma[8];
int con[10][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
char s[100];
bool dfs(int n,int k,char *t,bool *vis)
{
	bool ans=false;
	char tmp[40];
	bool vist[40];
	if (k==n) return true;
	pf(i,0,8) 
	if (ma[i]==s[k]-'0')
	{
		memcpy(tmp,t,sizeof(tmp));
		memcpy(vist,vis,sizeof(vist));
		bool ok=true;
		pf(j,-1,2) 
			if (!vist[(k+n+j)%n])
			{
				vist[(k+n+j)%n]=true;
				tmp[(k+n+j)%n]=con[i][j+1]+'0';
			}
			else if(tmp[(k+n+j)%n]!=con[i][j+1]+'0') {ok=false;break;}
		if (ok)	ans=dfs(n,k+1,tmp,vist);
		if (ans) return true;
	}
	return false;
}
main()
{
	int machine,N;
	bool vis[40];
	while (scanf("%d%d",&machine,&N)==2)
	{
		scanf("%s",s);
		memset(vis,0,sizeof(vis));
		int k=7;
		while (machine!=0) 
		{
			ma[k--]=machine%2;
			machine/=2;
		}
		while (k>=0) ma[k--]=0;
		memset(vis,0,sizeof(vis));
		printf("%s\n",dfs(N,0,s,vis)==1?"REACHABLE":"GARDEN OF EDEN");
	}
	return 0;
}
