#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct fun
{
	int x,y;
};
fun data[100100];
int vj;
int S;
int N,vh,W;
bool cal(double k)
{
	double x=data[0].x,y=data[0].x+W;
	for (int i=1;i<N;i++)
	{
		x-=vh*1.0*(data[i].y-data[i-1].y)*1.0/(k*1.0);
		y+=vh*1.0*(data[i].y-data[i-1].y)*1.0/(k*1.0);
		if (x<data[i].x) x=data[i].x*1.0;
		if (y>data[i].x+W)	y=data[i].x*1.0+W*1.0;
		if (x>y+1e-10)
		return 0;
	}
	return 1;
}
double mid(int l,int r)
{
	double x=l,y=r;
	while (y-x>1e-5)
	{
		double m=(y-x)/2+x;
		if (cal(m)==0) y=m;
		else x=m;
	}
	return x+1e-5;
/*	while (1)
	{
		int m=(x+y)/2;
		if (m==x) break;
		if (cal(m)) x=m;
		else y=m;
	}
	return x;*/
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&W,&vh,&N);
		for (int i=0;i<N;i++)
			scanf("%d%d",&data[i].x,&data[i].y);
		double result=mid(0,1000010);
	//	printf("%lf\n",result);
		int ans=-1;
		scanf("%d",&S);
		for (int i=0;i<S;i++)
		{
			scanf("%d",&vj);	
			if (vj<=result)
			ans=max(ans,vj);
		}
		if (ans!=-1)
			printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
