#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 1000000
int N;
int a[100010];
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (int i=0;i<N;i++)
			scanf("%d",&a[i]);
		int max=a[0];
		int result=-INF;
		for (int i=1;i<N;i++)
		{
			if (max-a[i]>result) result=max-a[i];
			if (a[i]>max) max=a[i];
		}
		printf("%d\n",result);	
	}
	return 0;
}
