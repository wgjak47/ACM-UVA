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
struct ractangle
{
	int x1,y1;
	int x2,y2;
};
ractangle data[50000000];
bool check(ractangle d,int x,int y)
{
	if (x>d.x1 && x<d.x2 && y>d.y1 && y<d.y2)
		return true;
	return false;
}
int l;
void push(int x1,int y1,int x2,int y2)
{
	data[l].x1=x1;
	data[l].x2=x2;
	data[l].y1=y1;
	data[l].y2=y2;
	l++;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,w,h;
		scanf("%d%d%d",&n,&w,&h);	
		data[0].x1=0;data[0].x2=w;
		data[0].y1=0;data[0].y2=h;
		l=1;
		int now=l;
		pf(i,0,n) 
		{
			int x,y;
			scanf("%d%d",&x,&y);
			for (int i=0;i<now;i++)
			if (check(data[i],x,y))
			{
				push(data[i].x1,y,data[i].x2,data[i].y2);
				push(data[i].x1,data[i].y1,data[i].x2,y);
				push(data[i].x1,data[i].y1,x,data[i].y2);
				data[i].x1=x;
			}
			now=l;
		}
		int ans=0;
		int xx,yy;
		pf(i,0,l)
		{
	//		printf("%d %d %d %d\n",data[i].x1,data[i].y1,data[i].x2,data[i].y2);
			int length=min(data[i].x2-data[i].x1,data[i].y2-data[i].y1);
			if (ans<length)
			{
				xx=data[i].x1;
				yy=data[i].y1;
				ans=length;
			}
		}
		printf("%d %d %d\n",xx,yy,ans);
		if (T) putchar('\n');
	}
	return 0;
}
