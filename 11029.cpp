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
int fast_mu(int a,int b)
{
	int tmp;
	if (b==1) return a%1000;
	if (b%2==0)
	{
		tmp=fast_mu(a,b/2);
		return (tmp)%1000*(tmp%1000)%1000;
	}
	else 
	{
		tmp=fast_mu(a,b/2);
		return (tmp)%1000*(tmp)%1000*(a%1000)%1000;
	}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		double t=log10(m)*n;
		t=fmod(t,1);
		int out=(int)(pow(10,t)*100.0);
		printf("%.3d...%.3d\n",out,fast_mu(m,n));
	}
	return 0;
}
