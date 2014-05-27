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
int a[3100];
int pos[3100];
main()
{
	int N;
	while (scanf("%d",&N)==1,N!=0)
	{
		int ans=0;
		pf(i,1,N+1) scanf("%d",&a[i]);
		pf(i,1,N+1) 
		{
			int b;
			scanf("%d",&b);
			pos[b]=i;
		}
		pf(i,1,N+1)
		{
			int max_a=pos[a[i]],min_a=pos[a[i]];
			pf(j,i+1,N+1)
			{
				max_a=max(max_a,pos[a[j]]);
				min_a=min(min_a,pos[a[j]]);
				if (j-i==max_a-min_a)
					ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
