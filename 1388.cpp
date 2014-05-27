#include<cstdio>
#include<cstring>
#include<cmath>
main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)==2)
	{
		double pos,ans=0;
		for (int i=1;i<n;i++)
		{
			pos=(double)i/n*(n+m);
			ans+=fabs(pos-floor(pos+0.5))/(n+m);
		}	
		printf("%f\n",ans*10000);
	}
	return 0;
}
