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
char s[110][110];
bool vis[30];
bool check(char key,int x,int y)
{
	int xx=x,yy=y;
	while (s[xx][y]==key) xx++;xx--;
	while (s[x][yy]==key) yy++;yy--;
	if (xx-x+1<3 || yy-y+1<3) return false;
	for (int i=x;i<=xx;i++) if (s[i][yy]!=key) return false;
	for (int i=y;i<=yy;i++) if (s[xx][i]!=key) return false;
	int x1=x+1,y1=y+1,x2=xx-1,y2=yy-1;
	for (int i=x1;i<=x2;i++)
	for (int j=y1;j<=y2;j++)
		if (s[i][j]!='.') return false;
	return true;
}
void solve(int n,int m)
{
	memset(vis,0,sizeof(vis));
	pf(i,0,n) pf(j,0,m)
		if (s[i][j]!='.' && !vis[s[i][j]-'A'] && check(s[i][j],i,j))
			vis[s[i][j]-'A']=true;
}
main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)==2)
	{
		getchar();
		if (n==0 && m==0) break;
		pf(i,0,n) 
			gets(s[i]);
		solve(n,m);
		pf(i,0,26) 
			if (vis[i]) putchar(i+'A');
		putchar('\n');
	}
	return 0;
}
