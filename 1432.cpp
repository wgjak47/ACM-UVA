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
struct point
{
	int x,y;
	double angle,high;
	bool operator<(const & point a)
	{
		return angle<a.angle;
	}
};
double cal_angle(int dx,int dy)
{
	if (dy==0)
	{
		if (dx>0) return pi/2;
		else return pi/2*3;
	}
	if (dx==0)
	{
		if (dy>0) return 0;
		else return pi;
	}
	double angle=atan(fabs(1.0*dx/dy));
	if (dx>=0 && dy>=0)
		angle+=0;
	else if (dx>0 && dy<0)
		angle=pi-angle;
	else if (dx<0 && dy<0)
		angle+=pi;
	else if (dx<0 && dy>0)
		angle=2*pi-angle;
	return angle;
}
point d[5100];
double solve(int n)
{
	double ans=1e9;
	vector<int> tmp;
	for (int i=0;i<n;i++)
	{
		int h=i;
		int reg=0;
		tmp.clear();
		bool found=true;
		for (int j=0;j<n;j++)
			if (j!=h && d[h].high>=d[j].high)
			{
				reg++;
				tmp.push_back(j);
				if (reg==k) found=true;
			}
		if (!found) continue;
	}
}
main()
{
	int n,k;
	int kcase=0;
	while (scanf("%d%d",&n,&k)==2)
	{
		if (n==0 && k==0) break;	
		pf(i,0,n)
		{
			scanf("%d%d",&d[i].x,&d[i].y);
			d[i].angle=cal(d[i].x,d[i].y);
		}
		sort(d,d+n,cmp);
		printf("Case #%d: %.2f",kcase++,solve(n));
	}
	return 0;
}
