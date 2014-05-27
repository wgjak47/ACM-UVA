#include<cstdio>
#include<cstring>
#include<cmath>
int bit(unsigned int K)
{
	if (K==0) return 0;
	return log2((double)K);
}
main()
{
	unsigned int N,L,U,M;	
	while (scanf("%u%u%u",&N,&L,&U)==3)
	{
		int n=bit(U);
		M=0;
		for (int i=n;i>=0;i--)
			if (((M+(1<<i))<=U) && ((N&1<<i)==0 || (M<L && (L&(1<<i)))))
				M+=1<<i;
		printf("%u\n",M);
	}
	return 0;
}
