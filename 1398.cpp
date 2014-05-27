#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct event
{
	double k;int type;
	friend bool operator<(const event &a,const event &b);
};
bool operator<(const event &a,const event &b)
{
	return (a.k<b.k || (a.k==b.k && a.type<b.type));
}
void get_t(double x,double a,double w,double &t1,double &t2)
{
	if (a==0) 
	{
		if ((x<=0 || x>=w)) {t2=t1-1; return ;}
	}
	else if (a>0)
	{
		t1=max(t1,-(x/a));
		t2=min(t2,(w-x)/a);
	}
	else 
	{
		t1=max(t1,(w-x)/a);
		t2=min(t2,-(x/a));
	}
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int w,h;
		vector<event> d;
		scanf("%d%d",&w,&h);	
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			int x,y,a,b;double t1=0,t2=1e9;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			get_t(x,a,w,t1,t2);
			get_t(y,b,h,t1,t2);
			if (t2>t1)
			{
				event z=(event){t1,1};
				d.push_back(z);
				z=(event){t2,0};
				d.push_back(z);
			}
		}
		sort(d.begin(),d.end());
		int l=d.size();
		int ans=0,tmp=0;
		for (int i=0;i<l;i++)
			if (d[i].type==1) 
			{
				tmp++;
				ans=max(ans,tmp);
			}
			else tmp--;
		printf("%d\n",ans);
	}
	return 0;
}
