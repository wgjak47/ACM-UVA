//二分，注意F的意义。。
#include<cstdio>
#include<cstring>
#include<cmath>
const double pi=atan(1)*4;
double pie[10010];
bool cal(double mid,int N,int F)
{
	double num=0;
	for (int i=0;i<N;i++)
		num+=floor(pie[i]/mid);	
	if (num>=F) return true;
	return false;
}
main()
{
	int T;
	scanf("%d",&T);
	int N,F;
	while (T--)
	{
		scanf("%d%d",&N,&F);
		F++;
		double sum=0;
		for (int i=0;i<N;i++)
		{
			scanf("%lf",&pie[i]),pie[i]*=pie[i]*pi,sum+=pie[i];	
		//	printf("%f ",pie[i]);
		}
		double l=0,r=sum;
		while (r-l>=1e-4)
		{
			double mid=(r+l)/2;
			if (cal(mid,N,F)) l=mid;
			else r=mid;
		}
		printf("%.4f\n",l);
	}
	return 0;
}
