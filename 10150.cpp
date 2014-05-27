#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
char dict[25200][18];
int fd[16][25200];
int ls[16];
bool vis[25200];
int f[25200];
bool G(char *a,char *b)
{
	int l=strlen(a);
	int reg=0;
	for (int i=0;i<l;i++)
		if (a[i]!=b[i]) reg++;
	if (reg==1) return true;
	return false;
}
bool bfs(int s1,int s2,int l)
{
	queue<int> q;
	int t;
	q.push(s1);
	while (!q.empty())
	{
		t=q.front();
		int le=strlen(dict[t]);
		for (int i=0;i<ls[le];i++)
		if (!vis[fd[le][i]] && G(dict[t],dict[fd[le][i]]))
		{
			f[fd[le][i]]=t;
			if (s2==fd[le][i])
			   	return true;
			vis[fd[le][i]]=true;
			q.push(fd[le][i]);
		}
		q.pop();
	}
	return false;
}
void print(int k)
{
	if (f[k]!=-1)
		print(f[k]);
	puts(dict[k]);
}
main()
{
	char s1[20],s2[20];
	int l=0;
	while (gets(dict[l]),dict[l][0]!='\0')
	{
		fd[strlen(dict[l])][ls[strlen(dict[l])]]=l;		
		ls[strlen(dict[l])]++;
		l++;
	}
	int reg=0;
	while (scanf("%s%s",s1,s2)==2)
	{
		memset(vis,0,sizeof(vis));
		memset(f,-1,sizeof(f));
		if (reg++) putchar('\n');
		if (strlen(s1)!=strlen(s2)) 
		{
			printf("No solution.\n");
			continue;
		}
		int k=-1,j=-1;
		for (int i=0;i<l;i++)
			if (strcmp(s1,dict[i])==0) {k=i;vis[k]=true;break;} 
		for (int i=0;i<l;i++)
			if (strcmp(s2,dict[i])==0) {j=i;break;} 
	if (k==-1 || j==-1 || !bfs(k,j,l)) printf("No solution.\n");
	else print(j);
	}
	return 0;
}
