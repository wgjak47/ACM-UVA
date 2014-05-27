#include<cstdio>
#include<cstring>
#include<cmath>
main()
{
	int S;
	scanf("%d",&S);
	while (S--)
	{
		int n,k;
		double p;
		scanf("%d%lf%d",&n,&p,&k);
		double plus=0,sum=0;
		int i=0;
		while (1)
		{
			plus=pow(1-p,k+n*i-1)*p;
			sum+=plus;
			i++;
			if (plus<1e-6) break;
		}
		printf("%.4f\n",sum);
	}
	return 0;
}
