#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b
int G[110][110];
int sum[110][110];
main()
{
	int N;
	int i,j,k,l,m,n;
	int f[110];
	while (scanf("%d",&N)!=EOF)
	{
		int result=G[0][0];
		memset(sum,0,sizeof(sum));
		for (i=0;i<N;i++)
		for (j=0;j<N;j++)
		{
			scanf("%d",&G[i][j]);
			if (i>0)
			sum[i][j]=G[i][j]+sum[i-1][j];
			else sum[i][j]=G[i][j];
		}
		for (i=0;i<N;i++)
		for (j=i+1;j<N;j++)
		{
			memset(f,0,sizeof(f));
			f[0]=sum[j][0]-sum[i][0];
			for (k=1;k<N;k++)
			{
				f[k]=max(f[k-1]+sum[j][k]-sum[i][k],sum[j][k]-sum[i][k]);
				result=result>f[k]?result:f[k];	
			}
		}
		printf("%d\n",result);
	}
	return 0;
}
