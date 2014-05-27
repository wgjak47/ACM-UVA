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
#define LLD long long
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
LLD a[500010];
LLD b[500010];
LLD total;
void merge_sort(int l,int r)
{
	if (l==r-1) return ;
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid,r);
	int ll=l,rr=mid;
	int k=0;
	while (ll<mid || rr<r)
	{
		if (ll>=mid) b[k++]=a[rr++];
		else 
			if(rr>=r) b[k++]=a[ll++];
		else 
			if (a[ll]<a[rr])
			{
				b[k++]=a[ll++];
			}
			else 
			{
				b[k++]=a[rr++];
				total+=mid-ll;
			}
	}
	int j=0;
	for (int i=l;i<r;i++)
		a[i]=b[j++];
}
main()
{
	int n;
	while (scanf("%d",&n)==1 && n!=0)
	{
		pf(i,0,n)
		scanf("%lld",&a[i]);
		total=0;
		merge_sort(0,n);
		//pf(i,0,n) printf("%d\n",a[i]);
		printf("%lld\n",total);
	}
	return 0;
}
