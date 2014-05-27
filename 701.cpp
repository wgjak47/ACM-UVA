// N * 10^K < 2^X < (N + 1) * 10^K  
// ((logN + K) / log2) < X < ((log(N + 1) + K) / log2)  
#include<cstdio>
#include<cstring>
#include<cmath>
int lg(int N)
{
	int reg=0;
	while (N)
	{
		reg++;
		N/=10;
	}
	return reg;
}
main()
{
	double N,N1;
	while (scanf("%lf",&N)==1)
	{
		int l=lg((int)N)+1;
		N1=N+1;
		while (1)
		{
			int t=(int)floor(log2(N+1)+log2(10)*l);
		//	printf("%f %f %d %d\n",log2(N)+log2(10)*l,log2(N+1)+log2(10)*l,l,t);
			if (t<=log2(N+1)+log2(10)*l && t>=log2(N)+log2(10)*l)
			{
				printf("%d\n",t);
				break;
			}
			l++;
		}
	}
	return 0;
}
