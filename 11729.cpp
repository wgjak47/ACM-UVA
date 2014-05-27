#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int B[10011],J[10011];
int order[10011];
int cmp(int a,int b)
{
	return J[a]>J[b];
}
main()
{
	int N;
	int T=0;
	while (scanf("%d",&N),N)
	{
		for (int i=0;i<N;i++)
			scanf("%d%d",&B[i],&J[i]);
		for (int i=0;i<N;i++)
			order[i]=i;		
		sort(order,order+N,cmp);
		int sum=0,max=0;
		for (int i=0;i<N;i++)
		{
			sum+=B[order[i]];
			if (sum+J[order[i]]>max)
				max=sum+J[order[i]];
		}
		printf("Case %d: %d\n",++T,max);
	}
	return 0;
}
