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
const long long mod=1000000007;
long long solve(int N)
{
	if (N==0) return 1;
	if (N==1) return 2;
	long long ans=solve(N/2);
	if (N%2!=0)
		return (ans*ans*2)%mod;
	else return (ans*ans)%mod;
}
main()
{
	int N;
	int T;
	scanf("%d",&T);
	int k=0;
	while (T--)
	{
		scanf("%d",&N);
		long long mi=solve(N-1);
		printf("Case #%d: %lld\n",++k,((mi%mod)*(N%mod))%mod);
	}
	return 0;
}
