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
const int MOD=1000007;
const int maxk=500;
int C[maxk+10][maxk+10];
main()
{
	memset(C,0,sizeof(C));
	C[0][0]=1;
	pf(i,0,maxk+1)
	{
		C[i][0]=C[i][i]=1;
		pf(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	int T;
	scanf("%d",&T);
	int cases=0;
	while (T--)
	{
		int n,m,k,sum=0;
		scanf("%d%d%d",&n,&m,&k);
		pf(S,0,16)
		{
			int b=0,r=n,c=m;
			if (S&1) {r--;b++;}
			if (S&2) {r--;b++;}
			if (S&4) {c--;b++;}
			if (S&8) {c--;b++;}
			if (b&1) sum=(sum+MOD -C[r*c][k])%MOD;
			else sum=(sum+C[r*c][k])%MOD;
		}
		printf("Case %d: %d\n",++cases,sum);
	}
	return 0;
}
