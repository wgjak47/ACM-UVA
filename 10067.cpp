#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
bool stop[10001];
struct d
{
	int num,value;
};
int getnum(int a,int b,int c,int d)
{
	return (a+10)%10*1000+(b+10)%10*100+(c+10)%10*10+(d+10)%10;
}
int bfs(int start,int end)
{
	queue<d> q;
	d t;
	t.num=0,t.value=start;
	q.push(t);
	while (!q.empty())
	{
		d now=q.front();
		if (now.value==end) return now.num;	
		int a=now.value/1000,b=(now.value/100)%10,c=(now.value/10)%10,e=now.value%10;
		int tmp[10];
		memset(tmp,-1,sizeof(tmp));
		tmp[1]=getnum(a-1,b,c,e);
		tmp[2]=getnum(a+1,b,c,e);
		tmp[3]=getnum(a,b-1,c,e);
		tmp[4]=getnum(a,b+1,c,e);
		tmp[5]=getnum(a,b,c-1,e);
		tmp[6]=getnum(a,b,c+1,e);
		tmp[7]=getnum(a,b,c,e-1);
		tmp[8]=getnum(a,b,c,e+1);
		for (int i=1;i<=8;i++)
			if (tmp[i]!=-1 && !stop[tmp[i]]) 
			{
				now.num=q.front().num+1;
				now.value=tmp[i];
				q.push(now);
				stop[tmp[i]]=true;
			}
		q.pop();
	}
	return -1;
}
main()
{
	int T;
	int start,goal;
	scanf("%d",&T);
	while (T--)
	{
		memset(stop,0,sizeof(stop));
		start=0,goal=0;
		int t;
		for (int i=0;i<4;i++)
		{
			scanf("%d",&t);
			start=start*10+t;
		}
		for (int j=0;j<4;j++)
		{
			scanf("%d",&t);
			goal=goal*10+t;
		}
		scanf("%d",&t);
		for (int i=0;i<t;i++)
		{
			int a,b,c,d,s;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			s=a*1000+b*100+c*10+d;
			stop[s]=1;
		}
		int ans=bfs(start,goal);
		printf("%d\n",ans);
	}
	return 0;
}
