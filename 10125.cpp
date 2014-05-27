#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct ab
{
	int sum,a,b;
};
ab vis[1000100];
int head[1000010],next[1000010];
int hash(long long k)
{
	return abs(k+200)%1200;
}
void insert(int s)
{
	int i,h=hash(vis[s].sum);
	next[s]=head[h];
	head[h]=s;
}
bool find(int x,int y,long long ans)
{
	int i,h=hash(ans);
	for (i=head[h];i!=-1;i=next[i])
	if (vis[i].sum==ans && vis[i].a!=x && vis[i].a!=y && vis[i].b!=x && vis[i].b!=y)
		break;
	if (i==-1)
		return false;
	return true;
}
main()
{
	int N;
	int a[1010];
	while (scanf("%d",&N),N!=0)
	{
		memset(head,-1,sizeof(head));
		for (int i=0;i<N;i++)
			scanf("%d",&a[i]);
		int k=0;
		for (int i=0;i<N;i++)
		for (int j=i+1;j<N;j++)
		{
			vis[k].sum=a[i]+a[j];
			vis[k].a=a[i];
			vis[k].b=a[j];
			insert(k);
			k++;
		};
		bool flag=false;
		long long max=-2000000000;
		for (int i=0;i<N;i++)
		for (int j=i+1;j<N;j++)
		{
			if (a[i]>max && find(a[i],a[j],a[i]-a[j])) {flag=1;max=a[i];}
			if (a[j]>max && find(a[j],a[i],a[j]-a[i])) {flag=1;max=a[j];}
		}
		if (flag==true) printf("%lld\n",max);
		else printf("no solution\n");
	}
	return 0;
}
