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
struct sum
{
	int s,num;
};
sum data[100010];
int q[100010];
double K(int a,int b)
{
	return 1.0*(data[a].s-data[b].s)/(data[a].num-data[b].num);
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		data[0].s=0;
		pf(i,1,m+1)
		{
			char c;
			c=getchar();
			data[i].s=data[i-1].s+c-'0';
			data[i].num=i;
		}
		int front=0,tail=0;
		double ans=-1e9;
		int start,end;
		data[0].num=0;
		q[0]=0;
		pf(i,n,m+1)
		{
			while (front>tail && K(i,q[tail])<=K(i,q[tail+1])) tail++;
			if (K(i,q[tail])>ans)
			{
				start=q[tail]+1;
				end=i;
				ans=K(i,q[tail]);
			}
			int tmp=i-n+1;
			while (front>tail && K(q[front],q[front-1])>=K(tmp,q[front])) front--;
			q[++front]=tmp;
		}
	//	printf("%f\n",ans);
		printf("%d %d\n",start,end);
	}
	return 0;
}
