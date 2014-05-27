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
int G[20][20];
int d[200];
bool vis[20];
int l;
int sum[20];
void solve(int n)
{
	int count=0,low=-10;
	while (count!=n+1)
	{
		int tag[20];
		memset(tag,0,sizeof(tag));
		pf(i,0,n+1)
			if (d[i]==0)
			{
				sum[i]=low;
				tag[i]=1;
				d[i]=-1;
				count++;
			}
		low++;
		pf(i,0,n+1)
			if (tag[i])
				pf(j,0,n+1)
					if (G[i][j]) d[j]--;
	}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(G,0,sizeof(G));
		memset(d,0,sizeof(d));
		int n;
		scanf("%d",&n);
		getchar();
		int k=0;
		for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
		{
			char c=getchar();
			if (c=='+') 
			{
				G[i-1][j]=1;
				d[j]++;
			}
			else if (c=='-')
			{
				G[j][i-1]=1;
				d[i-1]++;
			}
	 	}
		solve(n);
		for (int i=1;i<=n;i++)
		{
			if (i!=1) putchar(' ');
			printf("%d",sum[i]-sum[i-1]);
		}
		putchar('\n');
	} 
	return 0;
}
