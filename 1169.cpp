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
int weight[maxn],dist_o[maxn];
int dists[maxn];
int x[maxn],y[maxn];
int q[maxn],d[maxn];
int fun(int x)
{
	return d[x]-dists[x+1]+dist_o[x+1];
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,c;
		scanf("%d",&c);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int w;
			scanf("%d%d%d",&x[i],&y[i],&w);
			weight[i]=weight[i-1]+w;
			dists[i]=dists[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
			//printf("%d %d %d\n",dists[i],dists[i-1],abs(y[i]-y[i-1]),abs(x[i]-x[i-1]));
			dist_o[i]=abs(x[i])+abs(y[i]);
		}
		int front=1,rear=1;
		q[front]=0;
		for (int i=1;i<=n;i++)
		{
			while (front<=rear && weight[i]-weight[q[front]]>c) front++;
			d[i]=fun(q[front])+dists[i]+dist_o[i];
		//	printf("%d %d %d %d\n",d[i],q[front],fun(q[front]),dists[i]);
			while (front<=rear && fun(i)<=fun(q[rear])) rear--;
			q[++rear]=i;
		}
		printf("%d\n",d[n]);
		if (T) putchar('\n');
	}
	return 0;
}
