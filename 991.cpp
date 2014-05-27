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
main()
{
	int f[12];
	memset(f,0,sizeof(f));
	f[0]=1;
	pf(i,1,11)
	pf(j,1,i+1)
	{
		f[i]+=f[i-j]*f[j-1];
	}
	int n;
	int T=0;
	while (scanf("%d",&n)==1)
	{
		if (T++) putchar('\n');
		printf("%d\n",f[n]);
	}
	return 0;
}
