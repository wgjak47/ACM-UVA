#include<cstdio>
#include<cstring>
#include<cstdlib>
long long f(int *a,int i,int goal)
{
	if (i==0) return 0;
	if (a[i]==goal) return f(a,i-1,goal);
	else return f(a,i-1,6-a[i]-goal)+(1LL<<(i-1));
}
main()
{
	int N;
	int start[70];
	int end[70];
	int cases=1;
	while (scanf("%d",&N)==1)
 	{
		if (N==0) break;
		for (int i=1;i<=N;i++)
			scanf("%d",&start[i]);
		for (int i=1;i<=N;i++)
			scanf("%d",&end[i]);	
		int max=0;
		for (int i=N;i>=1;i--)
			if (end[i]!=start[i])
 			{
				max=i;break;
			}
		printf("Case %d:",cases++);
		long long ans=0;		
		if (max>=1) 
		{
			int m=6-start[max]-end[max];
			ans=f(start,max-1,m)+f(end,max-1,m)+1;
		}
		printf(" %lld\n",ans);
	}
	return 0;
}
