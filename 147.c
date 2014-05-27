#include<stdio.h>
#include<string.h>
main()
{
	unsigned long long total[6200];
	int i,j,k,l,m;
	int V[]={2000,1000,400,200,100,40,20,10,4,2,1};
	memset(total,0,sizeof(total));
	total[0]=1;
	for (i=10;i>=0;i--)
	for (j=1;j<=6000;j++)
	if (j>=V[i])
	total[j]+=total[j-V[i]];
	double in;
	while (scanf("%lf",&in))
	{
		if (in<1e-6) break;
		int s=(int) (in * 20);
		printf("%6.2lf%17llu\n",in,total[s]);
	}
	return 0;
}
