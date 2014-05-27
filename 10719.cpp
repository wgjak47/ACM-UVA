//证明：对于任意N，先考虑其本身的因子，如果没有lcm限制，则和最小的方式应该是个数尽可能多如27=3×3×3×3 sum=12<18 27=9×9,而由于lcm限制，不可能取到完全分解的形式，要满足条件，必须将相同素因子相乘，这样既可以使因子的lcm必然是N，又可以使sum最小。
//而对于不是N本身的因子，假设b=gcd（..）则对于b×N的sum必然要大于N的sum，故不可能是N的非因子。
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=(1<<16)+10;
bool notp[maxn];
vector<int> prime;
void get_prime()
{
	memset(notp,0,sizeof(notp));
	for (int i=2;i<maxn;i++)
	{
		if (!notp[i]) prime.push_back(i);
		for (int j=0;j<prime.size() && prime[j]*i<maxn;j++)
		{
			notp[prime[j]*i]=true;
			if (i%prime[j]==0) break;
		}
	}
}
main()
{
	int N;
	get_prime();
	int cases=1;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		int m=sqrt((double)N)+1;
		int tmpn=N;
		int cnt=0;
		long long ans=0;
		for (int i=0;prime[i]<=m;i++)
		{
			int tmp=1;
			if (tmpn%prime[i]==0)
			{
				cnt++;
				while (tmpn%prime[i]==0) 
				{
					tmpn/=prime[i];
					tmp*=prime[i];
				}
				ans+=tmp;
			}
		}
		if (tmpn==N) ans=(long long)N+1;
		else if (tmpn!=1) 
			ans+=tmpn;
		else if (tmpn==1 && cnt==1) ans++;
		printf("Case %d: %lld\n",cases++,ans);
	}
	return 0;
}
