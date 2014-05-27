#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
main()
{
	unsigned long long N,M;
	while (scanf("%lld%lld",&N,&M),N!=0)
	{
		
		unsigned long long a=N*(N-1)*M;
		unsigned long long b=N*(M-1)*M;
		unsigned long long m=max(N,M),n=min(N,M);
		//printf("%llu %llu\n",m,n);
		unsigned long long c=(m-n+1)*n*(n-1)+(n*(n-1)*(2*n-1)/3-(n-1)*n);
		//printf("%llu\n",a+b+c*2);
		printf("%llu\n",n*m*(m+n-2)+2*n*(n-1)*(3*m-n-1)/3);
	}
	return 0;
}
