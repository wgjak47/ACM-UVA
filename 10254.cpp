//bignumber  k=0,1,2,2,2,3,3,3,3....
//fn=f(n-k)*2+1<<k-1;
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)<(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
long long fuck[10010];
main()
{
	int N;
	memset(fuck,0x7f,sizeof(fuck));
	fuck[1]=1;
	for (int i=2;i<=64;i++)
	{
		int min=-1;
	for (int j=1;j<i && j<32;j++)
	{
		if (min==-1 || fuck[i-j]*2+((long long)1<<j)-1<fuck[i-min]*2+((long long)1<<min)-1)
			min=j;
	}
		fuck[i]=fuck[i-min]*2+((long long)1<<min)-1;
		printf("%lld %d %d\n",fuck[i],min,i);
	}
	while (scanf("%d",&N)==1)
	printf("%lld\n",fuck[N]);
	return 0;
}
