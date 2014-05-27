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
int const maxn=100010;
int fa[maxn*2+10],d[maxn*2+10],num[maxn*2+10];
int find(int x)
{
	return fa[x]==x?x:x=find(fa[x]);
}
main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)==2)
	{
		pf(i,1,n+1) 
		{
			fa[i]=i+maxn;
			fa[i+maxn]=i+maxn;
			d[i+maxn]=i;
			num[i+maxn]=1;
		}
		pf(i,0,m)
		{
			int cmd,p,q;
			int fp,fq;
			scanf("%d",&cmd);
			switch(cmd)
			{
				case 1:
					scanf("%d%d",&p,&q);
					fp=find(p);
					fq=find(q);
					if (fp==fq) break;
					fa[fp]=fq;
					d[fq]+=d[fp];
					num[fq]+=num[fp];
					break;
				case 2:
					scanf("%d%d",&p,&q);
					fp=find(p);
					fq=find(q);
					if (fp==fq) break;
					fa[p]=fq;
					num[fp]--;
					d[fp]-=p;
					num[fq]++;
					d[fq]+=p;
					break;
				case 3:
					scanf("%d",&p);
					int fp=find(p);
					printf("%d %d\n",num[fp],d[fp]);
					break;
			}
		}
	}
	return 0;
}
