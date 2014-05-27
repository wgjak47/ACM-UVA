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
const double pi=atan(1)*4;
main()
{
	double n;
	while (cin>>n)
	{
		double S=n*n;
		double tS=S*sqrt(3)/6-pi*n*n/12;
		tS=tS*2-S*sqrt(3)/4*(1-sqrt(3)/2)/(sqrt(3)/2)*(1-sqrt(3)/2)/(sqrt(3)/2);
		tS*=4;
		double mid=S*pi/2-S;
		mid*=2;
		mid=mid-(S-tS);
		printf("%.3f %.3f %.3f\n",mid,S-tS-mid,tS);
	}
	return 0;
}
