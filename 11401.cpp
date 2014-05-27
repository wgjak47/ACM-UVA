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
long long f[1000010];
main()
{
	f[3]=0;
	for (long long i=4;i<=1000000;i++)
		f[i]=f[i-1]+((i-1)*(i-2)/2-(i-1)/2)/2;
	int n;
	while (scanf("%d",&n),!(n<3))
	printf("%lld\n",f[n]);
	return 0;
}
