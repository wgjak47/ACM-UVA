#include<cstdio>
#include<cstring>
long long cal(int a,int b)
{
	if (a==0) return 1;
	if (b<=a) return 1;
	long long plus=1;
	for (int i=1;i<=a;i++)	
		plus*=b-i+1;
	long long divide=1;
	for (int i=1;i<=a;i++)
		divide*=i;
	return plus/divide;
}
main()
{
	int n,k;
	while (scanf("%d%d",&n,&k)==2)
	{
		int sum=0,z;
		long long ans=1; 
		for (int i=1;i<=k;i++)
		{
			scanf("%d",&z);
			ans*=cal(z,n-sum);
			sum+=z;
		}
		printf("%lld\n",ans);	
	}
	return 0;
}
