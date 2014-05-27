//c1*(n1*n2)/n1
//c2*(n1*n2)/n2
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
#define LLD long long
using namespace std;
LLD gcd(LLD a,LLD b,LLD &X,LLD &Y)
{
	if (b==0)
	{
		X=1,Y=0;
		return a;
	};
	LLD r=gcd(b,a%b,X,Y);
	LLD t=X;
	X=Y;
	Y=t-a/b*Y;
	return r;
}
LLD gcds(LLD a,LLD b)
{
	return b==0?a:gcds(b,a%b);
}
LLD c1,c2,n1,n2,g;
bool format(LLD &a,LLD &b,bool big)
{
	int aa,bb;
	int t;
	if (big) aa=-1,bb=1,t=a/(n2/g);
	else aa=1,bb=-1,t=b/(n1/g);
	a+=n2/g*aa*t;
	b+=n1/g*bb*t;
	if (a<0 || b<0) return false;	
	return true;
}
void mincost(LLD &a,LLD &b)
{
	int aa,bb,t;
	if (c1*n2>=c2*n1) aa=-1,bb=1,t=a*g/n2;
	else aa=1,bb=-1,t=b*g/n1;
		a+=aa*n2/g*t;
		b+=bb*n1/g*t;
}
main()
{
	LLD N;
	LLD x,y;
	while (scanf("%lld",&N)==1)
	{
		if (N==0) break;
		scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
		if (N%gcds(n1,n2)!=0) 
		{
			printf("failed\n");
			continue;
		}
		else 
		{
			g=gcd(n1,n2,x,y);
			x=x*(N/g);
			y=y*(N/g);
		}
		if (x>y)
		{
			if (format(x,y,true))
			{
				mincost(x,y);
				printf("%lld %lld\n",x,y);
			}
			else printf("failed\n");
		}
		else 
		{
			if (format(x,y,false))
			{
				mincost(x,y);
				printf("%lld %lld\n",x,y);
			}
			else printf("failed\n");
		}
	}
	return 0;
}
