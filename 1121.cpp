#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
int sum[100100];
main()
{
	int N,S;
	while (scanf("%d%d",&N,&S)==2)
	{
		sum[0]=0;
		for (int i=1;i<=N;i++) 
		{
			scanf("%d",&sum[i]);
			sum[i]+=sum[i-1];
		}
		if (sum[N]<S) {printf("0\n");continue;}
		int i=0,ans=N;
		for (int j=1;j<=N;j++)
		{
			if (sum[j]-sum[i]<S) continue;
			else
			{
				while (sum[j]-sum[i]>=S) i++;
				ans=min(ans,j-i+1);
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}
