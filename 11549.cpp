#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
const long long num[11]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
long long sqr(long long n,int k)
{
	long long tmp=k*k;
//	printf("%llda  ",tmp);
	while (tmp) 
	{
		if (tmp<num[n])
		{
//		printf("%lldb\n",tmp);
			return tmp;
		}
		tmp/=10;
	}
	return tmp;
}
main()
{
	long long n,k;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld",&n,&k);
		long long max=k;
		long long slow=k,fast=k;
		do
		{
			slow=sqr(n,slow);
			fast=sqr(n,fast);
			max=max(fast,max);
			fast=sqr(n,fast);
			max=max(fast,max);
		}
		while (slow!=fast);
		printf("%lld\n",max);
	}
	return 0;
}
