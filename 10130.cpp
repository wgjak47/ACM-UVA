#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
struct bag
{
	int value,weight;
};
struct bag data[1020];
int people[120];
int N,M;
int f[1001];
int solve(int C)
{
	memset(f,0,sizeof(f));
	for (int i=0;i<N;i++)
	for (int j=C;j>=0;j--)
		if (j>=data[i].weight)
			f[j]=max(f[j],f[j-data[i].weight]+data[i].value);
	return f[C];
}
main()
{
	int i,j,k;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (i=0;i<N;i++)
			scanf("%d%d",&data[i].value,&data[i].weight);
		scanf("%d",&M);
		for (i=0;i<M;i++)
			scanf("%d",&people[i]);
		int sum=0;
		for (i=0;i<M;i++)
			sum+=solve(people[i]);
		printf("%d\n",sum);
	}
	return 0;
}
