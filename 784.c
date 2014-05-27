#include<stdio.h>
#include<string.h>
char s[35][85];
int a[5][2]={{1,0},{0,1},{0,-1},{-1,0}};
int find,total;
int terminal(int x,int *a,int *b)
{
	int l,i;
	l=strlen(s[x]);
	if (find==0)	for (i=0;i<l;i++)
	if (s[x][i]=='*')
	{
		find=1;
		*a=x;
		*b=i;
	}
	for (i=0;i<l;i++)
	if (s[x][i]!='_') 
	
		return 0;
		
		return 1;
} 
void dfs(int x,int y)
{
	int i,hx,hy;
	if (s[x][y]=='*' || s[x][y]==' ' || s[x][y]=='_' )
	     s[x][y]='#';
	else return ;
	for (i=0;i<4;i++)
	{
	hx=x+a[i][0];hy=y+a[i][1];
	if (hx>0 && hy>0&& s[hx][hy]!='#')
		dfs(x+a[i][0],y+a[i][1]);
	}
}	
main()
{
	int n,i,l,k,x,y;
/*	freopen("in.txt","r",stdin);*/
	scanf("%d",&n);
	getchar();
	while(n--)
	{

		i=0;
		while (gets(s[i++])!=NULL)
			if (terminal(i-1,&x,&y)==1) break;
		total=i-1;
		dfs(x,y);
		for (i=0;i<total;i++)
			puts(s[i]);
		puts(s[total]);
		find=0;
	}
	return 0;
}
