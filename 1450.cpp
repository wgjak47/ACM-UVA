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
const int maxn=5010;
int E[maxn],W[maxn];
bool check(int max_no,int N)
{
	int e=0,w=0;
	int k=0;
	for (int i=0;i<N;i++)
	{
		e+=E[i],w+=W[i];
		if (e>max_no)
		{
			if (e-max_no>e-E[i]) return false;
			k-=e-max_no;
			e=max_no;
		}
		if (w>max_no)
		{
			if (w-max_no>w-W[i]) return false;
			k-=w-max_no;
			w=max_no;
		}
		if (k<0) return false;
		if (w && e && w+e>k)
			k++;
		else if (w && !e)
			w--;
		else if (!w && e)
			e--;
	}
	return true;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		pf(i,0,n)
			scanf("%d%d",&W[i],&E[i]);
		int L=0,R=maxn*20;
		while (L<R)
		{
			int mid=(L+R)/2;
			if (check(mid,n)) R=mid;
			else L=mid+1;
		}
		while (!check(L,n)) L++;
		if (!L) printf("0\n");
		else printf("%d\n",L-1);
	}
	return 0;
}
