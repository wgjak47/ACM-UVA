#include<stdio.h>
#include<string.h>
int a[100000],b[100000];
main()
{
	long long z,l,m,i,reg,k=0,q=0;
	while (scanf("%lld%lld%lld%lld",&z,&i,&m,&l)==4)
	{ 
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if (!z&&!i&&!m&&!l) break;
		reg=1;
		b[0]=l;
		while (!a[l])
		{
			a[l]=1;
			l=(z*l+i)%m;
			b[reg]=l;
			reg++;
		}
		for (q=0;q<reg;q++) if (b[q]==l) break;
		printf("Case %lld: %lld\n",++k,reg-q-1);
	}
	return 0;
}
		




