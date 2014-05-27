#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 1000000
int con[51][51];
int V[51];
int N,M;
int dp(int s,int t)
{
	if (t-s==1) return 0;
	if (con[s][t]!=-1) return con[s][t];
	int i,j;
	con[s][t]=INF;
	for (i=s+1;i<t;i++) 
	{
		int temp=dp(s,i)+dp(i,t)+V[t]-V[s];
		if (con[s][t]>temp)
			con[s][t]=temp;
	}
	return con[s][t];
}
main()
{
	int i,j,k,l;
	while (scanf("%d",&N),N!=0)
	{
		memset(con,-1,sizeof(con));
		scanf("%d",&M);
		for (i=1;i<=M;i++)
			scanf("%d",&V[i]);
		V[0]=0;V[M+1]=N;M++;
		printf("The minimum cutting is %d.\n",dp(0,M));
	}
	return 0;	
}
