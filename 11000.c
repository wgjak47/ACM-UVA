#include<stdio.h>
long long males[1000],sum[1000]={0};
void bee(long long female,long long male,int n)
{
   sum[n]+=male+female;
   males[n]=male-1;
   if (n==1000) return;
   bee(male-1,female+male+1,n+1);
}
main()
{
	int n;
	bee(0,2,1);
	males[0]=0;sum[0]=1;
	while (scanf("%d",&n))
	{
		if (n==-1) break;
		printf("%lld %lld\n",males[n],sum[n]);
	}
	return 0;
}
	
