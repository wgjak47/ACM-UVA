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
#define LLD long long
const int maxn=22;
const LLD INF=1LL<<60;
LLD S[maxn][maxn][maxn];
using namespace std;
void expand(int i,int &b0,int &b1,int &b2)
{
	b0=i&1;i>>=1;
	b1=i&1;i>>=1;
	b2=i&1;
}
int sign(int b0,int b1,int b2)
{
	return (b0+b1+b2)%2==1?1:-1;
}
LLD sum(int x1,int x2,int y1,int y2,int z1,int z2)
{
	int dx=x2-x1+1,dy=y2-y1+1,dz=z2-z1+1;
	LLD s=0;
	pf(i,0,8)
	{
		int b0,b1,b2;
		expand(i,b0,b1,b2);
		s-=S[x2-b0*dx][y2-b1*dy][z2-b2*dz] * sign(b0,b1,b2);
	}
	return s;
}
main()
{
	int  T;
	scanf("%d",&T);
	while (T--)
	{
		int a,b,c,b0,b1,b2;
		scanf("%d%d%d",&a,&b,&c);
		mt(S,0);
		pf(x,1,a+1) pf(y,1,b+1) pf(z,1,c+1) scanf("%lld",&S[x][y][z]);
		pf(x,1,a+1) pf(y,1,b+1) pf(z,1,c+1) pf(i,1,8)
		{
			expand(i,b0,b1,b2);
			S[x][y][z]+=S[x-b0][y-b1][z-b2]*sign(b0,b1,b2);
		}
		LLD ans=-INF;
		pf(x1,1,a+1) pf(x2,x1,a+1) pf(y1,1,b+1) pf(y2,y1,b+1)
		{
			LLD M=0;
			pf(z,1,c+1)
			{
				LLD s=sum(x1,x2,y1,y2,1,z);
				ans=max(s-M,ans);
				M=min(M,s);
			}
		}
		printf("%lld\n",ans);
		if (T) putchar('\n');
	}
	return 0;
}
