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
int a[10];
int f[10];
bool p[20];
bool check[41000];
int input()
{
	pf(i,0,8) scanf("%d",a[i]);
	if (a[0]==0) return 0;
	return 1;
}
void init()
{
	f[1]=1;
	for (int i=2;i<9;i++)
		f[i]=f[i-1]*i;
	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=true;
	p[17]=p[19]=true;
}
struct kk
{
	int w[10];
};
int bfs()
{
	vector<kk>
}
main()
{
	int k=0;
	init();
	while (input())
	{
		memset(check,0,sizeof(check));
		int ans=bfs();
		printf("Case %d: %d\n",++k,ans);
	}
	return 0;
}
