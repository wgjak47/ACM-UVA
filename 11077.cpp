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
#define ULL unsigned long long
using namespace std;
const int maxn=30;
ULL f[maxn][maxn];
main()
{
	f[1][0]=1;
	for (int i=2;i<=21;i++)
	for (int j=0;j<i;j++)
		f[i][j]=f[i-1][j]+(j>0?f[i-1][j-1]*(i-1):0);
	int n,k;
	while (scanf("%d%d",&n,&k)==2 && n+k)
		printf("%llu\n",f[n][k]);
	return 0;
}
