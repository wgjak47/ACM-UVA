#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct ch
{
	char data[6][6];
	int x,y;
	int cur;
};
ch chess;
ch answer;
ch temp[100000];
int l;
int first[10210],next[1000100];
int hash(ch k)
{
	int sum=0;
	for (int i=0;i<5;i++)
	for (int j=0;j<5;j++)
	{
		sum=sum+k.data[i][j]*i*j;
		sum*=2+197;
		sum%=10199;
	}
	return sum;
}
bool cmp(ch a,ch b)
{
	if (a.x!=b.x || a.y!=b.y) return false;
	for (int i=0;i<5;i++)
	for (int j=0;j<5;j++)
		if (a.data[i][j]!=b.data[i][j])
			return false;
	return true;
}
bool insert(ch k)
{
	int h=hash(k);
	for (int i=first[h];i!=-1;i=next[i])
		if (cmp(temp[i],k)==1)
			return false;
	temp[l]=k;
	next[l]=first[h];
	first[h]=l;
	l++;
	return true;
}
int bfs(ch c)
{
	queue<ch> q;
	int step[9][3]={{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};			
	c.cur=0;
	q.push(c);
	while (!q.empty())
	{
		for (int i=0;i<8;i++)
		{
			ch t=q.front();
			if (cmp(t,answer)==1) return t.cur;
			t.cur++;
			if (t.cur>=11) 
				return -1;
			if (t.x+step[i][0]>=0 && t.x+step[i][0]<5 && t.y+step[i][1]>=0 && t.y+step[i][1]<5)
			{
				char k=t.data[t.x][t.y];
				t.data[t.x][t.y]=t.data[t.x+step[i][0]][t.y+step[i][1]];
				t.data[t.x+step[i][0]][t.y+step[i][1]]=k;
				t.x=t.x+step[i][0],t.y=t.y+step[i][1];
				if (cmp(t,answer)==1) return t.cur;
				if (insert(t))
					q.push(t);
			}
		}
		q.pop();
	}
	return -1;
}
inline void find(ch &chess)
{
	for (int i=0;i<5;i++)
	for (int j=0;j<5;j++)
		if (chess.data[i][j]==' ') 
		{
			chess.x=i;
			chess.y=j;
			return ;
		}
}
main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<5;i++)
	for (int j=0;j<5;j++)
	if (j>=i)
		answer.data[i][j]='1';
	else 
		answer.data[i][j]='0';
	answer.data[2][2]=' ';
	answer.data[4][4]=answer.data[3][3]='0';
	answer.x=answer.y=2;
	while (n--)
	{
		l=0;
		memset(first,-1,sizeof(first));
		for (int i=0;i<5;i++)
			gets(chess.data[i]);
		find(chess);
		insert(chess);
		int result=bfs(chess);
		if (result==-1)
			printf("Unsolvable in less than 11 move(s).\n");
		else printf("Solvable in %d move(s).\n",result);
	}
	return 0;
}
