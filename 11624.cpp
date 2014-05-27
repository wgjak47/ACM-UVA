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
char s[1100][1100];
int t[1100][1100];
bool vis[1100][1100];
const int inf=1e9;
struct point
{
	int x,y;
	int num;
};
bool check(int x,int y,int m,int n)
{
	if (x>=1 && x<=m && y>=1 && y<=n)
		return 	true;
	return false;
}
void BFS_fire(int m,int n)
{
	queue<point> q;
	int a[5][2]={{0,1},{1,0},{-1,0},{0,-1}};
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		if (s[i][j]=='F') 
		{
			q.push((point){i,j,0});
			t[i][j]=0;
		}
		else t[i][j]=inf;
	while (!q.empty())
	{
		point b=q.front();
		for (int i=0;i<4;i++)
		if (s[b.x+a[i][0]][b.y+a[i][1]]=='.' && t[b.x+a[i][0]][b.y+a[i][1]]==inf &&  check(b.x+a[i][0],b.y+a[i][1],m,n))
		{
			q.push((point){b.x+a[i][0],b.y+a[i][1],b.num+1});
			t[b.x+a[i][0]][b.y+a[i][1]]=b.num+1;
		}
		q.pop();
 	}
} 
int BFS_escape(int m,int n)
{
	int a[5][2]={{0,1},{1,0},{-1,0},{0,-1}};
	queue<point> q;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		if (s[i][j]=='J')
		{
			q.push((point){i,j,0});
			vis[i][j]=1;
			break;
		}
	while (!q.empty())
	{
		point b=q.front();
		if (b.x==1 || b.x==m || b.y==1 || b.y==n) return b.num;
		for (int i=0;i<4;i++)
			if (!vis[b.x+a[i][0]][b.y+a[i][1]] && s[b.x+a[i][0]][b.y+a[i][1]]=='.' && b.num+1<t[b.x+a[i][0]][b.y+a[i][1]])
			{
				q.push((point){b.x+a[i][0],b.y+a[i][1],b.num+1});
	//			printf("%d %d\n",b.x+a[i][0],b.y+a[i][1]);
				vis[b.x+a[i][0]][b.y+a[i][1]]=true;
			}
		q.pop();
	}
	return -1;
}
main()
{
	int T;
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		pf(i,1,m+1)
			gets(s[i]+1);
		BFS_fire(m,n);
	/*	pf(i,1,m+1)
		{
			pf(j,1,n+1)
				printf("%d ",t[i][j]);
			putchar('\n');
		}*/
		int ans=BFS_escape(m,n);
		if (ans!=-1)
			printf("%d\n",ans+1);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
