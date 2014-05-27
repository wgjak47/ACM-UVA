#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int x[510],y[510];
struct dis
{
	double d;
	int u,v;
};
dis G[510*510];
int fx[510];
bool cmp(dis a,dis b)
{
	return a.d<b.d;
}
int find(int a)
{
	return fx[a]==a?a:fx[a]=find(fx[a]);
}
double cal(int a,int b,int c,int d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void solve(int N,int S,int P)
{
	for (int i=0;i<P;i++) fx[i]=i;
	double sum=0;
	sort(G,G+N,cmp);
	int z=0;
	for (int i=0;i<N;i++)
	{
		int x=find(G[i].u);
		int y=find(G[i].v);
		if (x!=y)
		{
			z++;
			fx[x]=find(fx[y]);
			if (z==P-S)
			{
			sum=G[i].d;
			break;
			}
		}	
	}	
	printf("%.2f\n",sum);
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int S,P;
		scanf("%d%d",&S,&P);
		for (int i=0;i<P;i++)
			scanf("%d%d",&x[i],&y[i]);
		int k=0;
		for (int i=0;i<P;i++)
		for (int j=i+1;j<P;j++)
		{
			G[k].d=cal(x[i],y[i],x[j],y[j]);
			G[k].u=i,G[k].v=j;
			k++;
		}
		solve(k,S,P);
	}
	return 0;
}
