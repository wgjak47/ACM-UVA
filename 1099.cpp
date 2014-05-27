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
const int maxn=16;
const int maxw=100+10;
int A[maxn],sum[1<<maxn],f[1<<maxn][maxw],vis[1<<maxn][maxw];
int bitcount(int x) {return x==0?0:bitcount(x/2)+(x&1);}
int dp(int S,int x)
{
	if (vis[S][x]) return f[S][x];
	vis[S][x]=1;
	int &ans=f[S][x];
	if (bitcount(S)==1) return ans=1;
	int y=sum[S]/x;
	for (int S0=(S-1)&S;S0;S0=(S0-1)&S)
	{
		int S1=S-S0;
	/*	printf("%d %d %d %d\n",sum[S1],sum[S0],x,y);
		if (sum[S1]==3 && sum[S0]==9) 
			printf("aaa\n");*/
		if (sum[S0]%x==0&&dp(S0,min(x,sum[S0]/x))&&sum[S1]%x==0 && dp(S1,min(sum[S1]/x,x))) 
			return ans=1;
		if (sum[S0]%y==0&&dp(S0,min(y,sum[S0]/y))&&sum[S1]%y==0 && dp(S1,min(sum[S1]/y,y))) 
			return ans=1;
	}
	return ans=0;
}
main()
{
	int N;
	int ck=0;
	while (scanf("%d",&N)==1)
	{
		int x,y;
		if (N==0) break;
		scanf("%d%d",&x,&y);
		pf(i,0,N) 
			scanf("%d",&A[i]);
		memset(sum,0,sizeof(sum));
		for (int S=0;S<(1<<N);S++)
		for (int i=0;i<N;i++)
			if (S&(1<<i)) sum[S]+=A[i];
		memset(vis,0,sizeof(vis));
		int ALL=(1<<N)-1;
		int ans;
		if (sum[ALL]!=x*y || sum[ALL]%x!=0) ans=0;
		else ans=dp(ALL,min(x,y));
		printf("Case %d: %s\n",++ck,ans==1?"Yes":"No");
	}
	return 0;
}
