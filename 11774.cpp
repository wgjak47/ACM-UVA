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
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
main()
{
	int T;
	scanf("%d",&T);
	int k=0;
	while (T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("Case %d: %lld\n",++k,(n+m)/gcd(n,m));
	}
	return 0;
}
