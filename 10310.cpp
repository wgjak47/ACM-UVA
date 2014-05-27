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
double hx[1010],hy[1010];
double cal(double x,double y)
{
	return sqrt(x*x+y*y);
}
main()
{
	int N;
	double gx,gy,dx,dy;
	while (cin>>N)
	{
		cin>>gx>>gy>>dx>>dy;
		int ans=-1;
		pf(i,0,N) cin>>hx[i]>>hy[i];
		pf(i,0,N) 
		{
			double disg=cal(gx-hx[i],gy-hy[i]);
			double disd=cal(dx-hx[i],dy-hy[i]);	
			if (disg*2<=disd) 
			{
				ans=i;
				break;
			}
		}
		if (ans==-1) printf("The gopher cannot escape.\n");
		else printf("The gopher can escape through the hole at (%.3f,%.3f).\n",hx[ans],hy[ans]);
	}
	return 0;
}
