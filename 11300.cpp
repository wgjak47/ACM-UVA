#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000010];
long long c[1000010];
main()
{
	int N;
	long long mid=0;
	long long sum=0;
	while (scanf("%d",&N)==1)
	{
		mid=0,sum=0;
		for (int i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			mid+=a[i];
		}
		mid/=N;
		c[0]=a[0]-mid;
		for (int i=1;i<N;i++)
			c[i]=c[i-1]+a[i]-mid;
		sort(c,c+N);
		long long m=c[N/2];	
		for (int i=0;i<N;i++)
			sum+=abs(m-c[i]);	
		printf("%lld\n",sum);
	}
	return 0;
}
