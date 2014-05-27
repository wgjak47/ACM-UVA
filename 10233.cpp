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
#define pi atan(1)*4
#define mt(a,d) memset((a),(d),sizeof(a))
#define LLD long long
using namespace std;
vector<LLD> sum;
double cal(double x,double y)
{
	return sqrt(x*x+y*y);
}
double high(LLD m,int h)
{
	if (m%2==0 && (h+1)%2==0)
		return sin(pi/3)*2/3;
	if (m%2==1 && (h+1)%2==1)
		return sin(pi/3)*2/3;
	return sin(pi/3)/3;
}
void get_local(LLD m,double &x,double &y)
{
	LLD h;
	h=upper_bound(sum.begin(),sum.end(),m)-sum.begin();
	LLD l=m-h*h;
	if (l==0) h--;
	LLD tot=(2*(h)+1)/2;
	LLD mid=sum[h]-tot;
	y=h*sin(pi/3)+high(m,h);
	x=(m-mid)*0.5;
	return ;
}
main()
{
	LLD m,n;
	LLD k=1;
	sum.push_back(1);
	while (1)
	{
		k+=2;
		if (2147483647-sum.back()<k) 
		{
			sum.push_back(sum.back()+k);
			break;
		}
		sum.push_back(sum.back()+k);
	}
	while (scanf("%lld%lld",&m,&n)==2)
	{
		m++,n++;
		double x1,x2,y1,y2;
		get_local(m,x1,y1);
		get_local(n,x2,y2);
		printf("%.3f\n",cal(x1-x2,y1-y2));
	}
	return 0;
}
