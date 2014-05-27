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
struct plant
{
	int x,y,z;
	int stat;
};
struct dis
{
	long long d;
	int p1,p2;
	bool operator<(const dis &a) const
	{
		return d<a.d;
	}
};
plant d[1010];
dis data[1010*1010];
long long cal(int i,int j)
{
	long long a=(d[i].x-d[j].x);
	long long b=(d[i].y-d[j].y);
	long long c=(d[i].z-d[j].z);
	return a*a+b*b+c*c;
}
int na[1010];
bool vis[1010];
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		memset(vis,0,sizeof(vis));
		pf(i,0,N)
		{
			scanf("%d%d%d%d",&d[i].x,&d[i].y,&d[i].z,&d[i].stat);
			na[i]=-1;
		}
		if (N==1) 
		{
			printf("0\n0.0000\n");
			continue;
		}
		int k=0;
		pf(i,0,N)
		pf(j,i+1,N)
		{
			data[k].d=cal(i,j);
			data[k].p1=i;
			data[k].p2=j;
			k++;
		}
		sort(data,data+k);
		int max=0;double ansd=0;
		int ansm=0;
		for (int i=0;i<k;i++)
		{
			int z=i;
			while (data[z].d==data[i].d && z<k)
			{
				if (d[data[z].p1].stat!=d[data[z].p2].stat)
					na[data[z].p1]++,na[data[z].p2]++;
				else na[data[z].p1]--,na[data[z].p2]--;
				if (vis[data[z].p1] && na[data[z].p1]<=0) max--,vis[data[z].p1]=false;
				if (!vis[data[z].p1] && na[data[z].p1]>0) max++,vis[data[z].p1]=true;
				if (vis[data[z].p2] && na[data[z].p2]<=0) max--,vis[data[z].p2]=false;
				if (!vis[data[z].p2] && na[data[z].p2]>0) max++,vis[data[z].p2]=true;
				z++;
			}
			if (max>ansm)
			{
				ansm=max;
				ansd=data[z-1].d;
			}
			i=z-1;
		}
		//if (ansm==0) ansd=0;
		printf("%d\n%.4f\n",ansm,sqrt(ansd*1.0)+1e-8);
	}
	return 0;
}
