#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
int turn[26][6]={
{2,1,5,0,4,3},{2,0,1,4,5,3},{2,4,0,5,1,3},{2,5,4,1,0,3},{4,2,5,0,3,1},{5,2,1,4,3,0},{1,2,0,5,3,4},{0,2,4,1,3,5},{0,1,2,3,4,5},{4,0,2,3,5,1},{5,4,2,3,1,0},{1,5,2,3,0,4},{5,1,3,2,4,0},{1,0,3,2,5,4},{0,4,3,2,1,5},{4,5,3,2,0,1},{3,4,5,0,1,2},{3,5,1,4,0,2},{3,1,0,5,4,2},{3,0,4,1,5,2},{1,3,5,0,2,4},{0,3,1,4,2,5},{4,3,0,5,2,1},{5,3,4,1,2,0}};
using namespace std;
vector<string> in;
int d[7];
int ans=0;
int n;
int color[7][7];
int getnum(char *s)
{
	string tmp(s);
	int l=in.size();
	for (int i=0;i<l;i++)
		if (tmp==in[i]) return  i;
	in.push_back(tmp);
	return in.size()-1;
}
void check()
{
	int col[30];
	int face[7][7];
	for (int i=0;i<n;i++)
	for (int j=0;j<6;j++)
		face[i][turn[d[i]][j]]=color[i][j];
	int sum=0;
	for (int i=0;i<6;i++)
	{
		int maxs=0;
		memset(col,0,sizeof(col));
		for (int j=0;j<n;j++)
			maxs=max(maxs,++col[face[j][i]]);
		sum+=n-maxs;
	}
	ans=min(sum,ans);
}
void dfs(int i)
{
	if (i==n) {check();return ;}
	else 
	{
		for (int j=0;j<24;j++)
		{
			d[i]=j;
			dfs(i+1);
		} 
	}
}
main()
{
	while (scanf("%d",&n)==1,n!=0)
	{
		in.clear();
		getchar();
		char s[30];
		for (int i=0;i<n;i++)
		for (int j=0;j<6;j++)
		{ 
			scanf("%s",s);
			color[i][j]=getnum(s);
		}
		d[0]=0;
		ans=n*6;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
