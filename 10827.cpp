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
int G[200][200];
int sum[200][200];
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		pf(i,1,n+1) pf(j,1,n+1)
		{
			scanf("%d",&G[i][j]);
			G[i+n][j]=G[i][j];
			G[i][j+n]=G[i][j];
			G[i+n][j+n]=G[i][j];
		}
		int max_ans=G[1][1];
		memset(sum,0,sizeof(sum));
		pf(i,1,n*2+1) 
		{
			pf(j,1,n*2+1)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+G[i][j];
		}
		pf(i,0,n+1) pf(j,i+1,i+n+1)
		pf(k,0,n+1) pf(l,k+1,k+n+1)
		{
			max_ans=max(sum[j][l]-sum[j][k]-sum[i][l]+sum[i][k],max_ans);
		//	printf("%d %d %d %d\n",i,k,j,l);
		}
	/*	pf(i,1,n+1) pf(j,i,i+n)
		{
			int top=i;
			int bot=j;	
			int ans=0;
			int min=0;
			for (int k=1;k<=2*n;k++)
			{
				ans+=sum[bot][k]-sum[top-1][k];
				max_ans=max(ans-min,ans);
				min=min(min,ans);
			}
		}*/
		printf("%d\n",max_ans);
	}
	return 0;
}
