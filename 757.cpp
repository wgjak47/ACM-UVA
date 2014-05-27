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
int hh[30],f[30],d[30],out[30];
int ans;
void solve(int h,int l)
{
	int tmp[30];
	int time[30];
	memset(time,0,sizeof(time));
	memcpy(tmp,f,sizeof(f));
	int sum=0;
	while (h>=5)
	{
		int maxs=1;
		for (int i=1;i<=l;i++)
			if (f[maxs]<f[i])
				maxs=i;
		sum+=f[maxs];
		f[maxs]-=d[maxs];
		if (f[maxs]<0) f[maxs]=0;
		h-=5;
		time[maxs]+=5;
	}
	if (ans<sum)
	{
		ans=sum;
		memcpy(out,time,sizeof(out));
	}
	memcpy(f,tmp,sizeof(f));
}
main()
{
	int N,T,H;
	int t=0;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		if (t++) putchar('\n');
		scanf("%d",&H);
		hh[1]=0;
		ans=-1;
		pf(i,1,N+1)
			scanf("%d",&f[i]);
		pf(i,1,N+1)
			scanf("%d",&d[i]);
		pf(i,2,N+1)
		{
			scanf("%d",&hh[i]);
			hh[i]+=hh[i-1];
		}
		pf(i,1,N+1)
			if (H*60>hh[i]*5)
				solve(H*60-hh[i]*5,i);
			else break;
		for (int i=1;i<=N;i++)
		{
			if (i-1) printf(", ");
			printf("%d",out[i]);
		}
		printf("\nNumber of fish expected: %d\n",ans);
	}
	return 0;
}
