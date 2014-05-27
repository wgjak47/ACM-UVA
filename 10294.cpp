#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL pow[70];
LL _gcd(LL a,LL b){return b==0?a:_gcd(b,a%b);}
main()
{
	int N,T;
	while (scanf("%d%d",&N,&T)==2)
	{
		LL a=0;
		pow[0]=1;
		for (int i=1;i<=N;i++) pow[i]=pow[i-1]*T;
		for (int i=1;i<=N;i++)
			a+=pow[_gcd(i,N)];
		LL b=a;
		if (N%2==0) b+=N/2*pow[(N+2)/2]+pow[N/2]*N/2;
		else b+=pow[(N+1)/2]*N;
		printf("%lld %lld\n",a/N,b/2/N);
	}
	return 0;
}
