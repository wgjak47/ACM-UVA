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
const int maxn=4000000;
long long S[maxn+10],f[maxn+10];
int phi[maxn+10];
void phi_table (int n)
{
	mt(phi,0);
	phi[1]=1;
	pf(i,2,n+1) if (!phi[i])
	{
		for (int j=i;j<=n;j+=i){
			if (!phi[j]) phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
}
main()
{
	int n;
	phi_table(maxn);
	for (int i=1;i<=maxn;i++)
		for (int n=i*2;n<=maxn;n+=i) f[n]+=i*phi[n/i];
	S[2]=f[2];
	for (int n=3;n<=maxn;n++) S[n]=S[n-1]+f[n];
	while (scanf("%d",&n) && n)
	printf("%lld\n",S[n]);
	return 0;
}
