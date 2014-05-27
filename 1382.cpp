//为什么m=2是不能适用，而x无关紧要呢？？
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)<(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
struct Point
{
	int x,y;
	bool operator<(const Point &a) const
	{
		if (x<a.x) return true;
		return false;
	}
};
Point data[110];
int y[110],on[110],on2[110],left[110];
main()
{
	int N,T=0;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		int ans=0;
		bool allx=true,ally=true;
		left[0]=0;
		pf(i,0,N)
		{
			scanf("%d%d",&data[i].x,&data[i].y);
			y[i]=data[i].y;
			if (i>0)
			{
				if (data[i].x!=data[i-1].x) allx=false;
				if (data[i].y!=data[i-1].y) ally=false;
			}
		}
		if (!allx && !ally)
		{
			sort(data,data+N);
			sort(y,y+N);
			int m=unique(y,y+N)-y;
			pf(i,0,m)
			pf(j,i+1,m)
			{
				int ymin=y[i],ymax=y[j];
				int num=0;
				pf(k,0,N)
				{
					if (k==0 || data[k].x!=data[k-1].x)
					{
						num++;
						on[num]=on2[num]=0;
						left[num]=num==0?0:left[num-1]+on2[num-1]-on[num-1];
					}
					if (data[k].y>ymin && data[k].y<ymax) on[num]++;
					if (data[k].y>=ymin && data[k].y<=ymax) on2[num]++;
				}
				int M=0;
				pf(k,1,num+1)
				{
					ans=max(ans,left[k]+on2[k]+M);
					M=max(M,on[k]-left[k]);
				}
			}
			printf("Case %d: %d\n",++T,ans);
		}
		else
			printf("Case %d: %d\n",++T,N);
	}
	return 0;
}
