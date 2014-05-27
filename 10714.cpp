#include<cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
int in[1000010];
main()
{
	int T;
	int L,N;
	int max,min;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&L,&N);
		for (int i=1;i<=N;i++)
			scanf("%d",&in[i]);
		min=0;
		max=0;
		for (int i=1;i<=N;i++)
			if (L-in[i]>in[i])
			{
				if (min<in[i]) min=in[i];
				if (max<L-in[i]) max=L-in[i];
			}
			else 
			{
				if (min<L-in[i]) min=L-in[i];
				if (max<in[i]) max=in[i];
			}
		printf("%d %d\n",min,max);
	}
}
