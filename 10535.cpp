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
};
struct wall
{
	point a,b;
};
wall d[510];
const double pi=atan(1)*4;
bool in(double a,double x,double y)
{
	if (x-y>pi)
	{
		if (a<=y || a>=x)
			return true;
		return false;
	}
	else if (a>=y && a<=x)
		return true;
	return false;
}
double cal_angle(point &a,point &b)
{
	int dx=b.x-a.x;
	int dy=b.y-a.y;
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
main()
{
	int N;
	while (scanf("%d",&N) && N)
	{
		point liser;
		pf(i,0,N)
		cin>>d[i].a.x>>d[i].a.y>>d[i].b.x>>d[i].b.y;
		cin>>liser.x>>liser.y;
		int ans=0;
		pf(i,0,N)
		{
			double angle=cal_angle(liser,d[i].a);
			int tmp=0;
			pf(j,0,N)
			{
				double max_angle=cal_angle(liser,d[j].a);
				double min_angle=cal_angle(liser,d[j].b);
				if (max_angle<min_angle)
					swap(max_angle,min_angle);
				if (in(angle,max_angle,min_angle)) tmp++;
			}
			ans=max(tmp,ans);
			angle=cal_angle(liser,d[i].b);
			tmp=0;
			pf(j,0,N)
			{
				double max_angle=cal_angle(liser,d[j].a);
				double min_angle=cal_angle(liser,d[j].b);
				if (max_angle<min_angle)
					swap(max_angle,min_angle);
				if (in(angle,max_angle,min_angle)) tmp++;
			}
			ans=max(tmp,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
