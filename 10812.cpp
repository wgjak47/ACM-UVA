#include<cstdio>
#include<cstring>
main()
{
	int N;
	scanf("%d",&N);
	while (N--)
	{
		long long p1,p2;
		scanf("%lld%lld",&p1,&p2);
		long long a=(p1+p2)/2;
		if (p1+p2!=a*2 || p1<p2)
			printf("impossible\n");
		else printf("%lld %lld\n",a,p1-a);
	}
	return 0;
}
