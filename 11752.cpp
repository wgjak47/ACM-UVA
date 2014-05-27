#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
const unsigned long long Max=1LL<<16;
bool notp[Max+10];
vector<unsigned long long> prime;
void get_prime()
{
	for (unsigned long long i=2;i<=Max;i++)
	{
		if (!notp[i]) prime.push_back(i);
		for (unsigned long long j=0;j<prime.size() && prime[j]*i<=Max;j++)
		{
			notp[prime[j]*i]=1;
			if (i%prime[j]==0) break;
		}
	}
}
vector<unsigned long long> d;
const unsigned long long M=ULONG_LONG_MAX;
main()
{
	get_prime();
	for (unsigned long long i=2;i<=Max;i++)
	{
		unsigned long long k=i*i*i;
		unsigned long long z=k;
		long long sum=3;
		while (z<M/i)
		{
			z*=i;
			sum++;
			if (notp[sum])
			d.push_back(z);
		}
	}
	sort(d.begin(),d.end());
	printf("1\n");
	for (int i=0;i<d.size();i++)
		if (i+1<d.size() && d[i]==d[i+1]) continue;
		else 
		printf("%llu\n",d[i]);
	return 0;
}
