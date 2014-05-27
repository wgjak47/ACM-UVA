#include<stdio.h>
#include<string.h>
int k;
int a[101]={0};
char s[100][100];
int dfs2(int x,int y)
{
	if (s[x][y]=='.' || s[x][y]=='*') 
		return ;
	s[x][y]='*';
	dfs2(x+1,y);
	dfs2(x,y+1);
	dfs2(x,y-1);
	dfs2(x-1,y);
}
int dfs1(int x,int y)
{
	if (s[x][y]=='.') return;
	if (s[x][y]=='X') 
	{ 
		a[k]++;
		dfs2(x,y);
	}
	if (s[x][y]=='*') s[x][y]='.';
	dfs1(x+1,y);
	dfs1(x,y+1);
	dfs1(x,y-1);
	dfs1(x-1,y);
}
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{ 
	int m,n,i,j,reg=0;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d%d",&n,&m)==2)
 	{ 
		memset(a,0,sizeof(a));
		getchar();
		k=0;
		if (m==0 && n==0) break;
		for (i=0;i<n+1;i++) {s[0][i]='.';s[m+1][i]='.';}
		for (j=0;j<m+1;j++) {s[j][0]='.';s[j][n+1]='.';}
		for (i=1;i<=m;i++)
		{
			for (j=1;j<=n;j++)
				s[i][j]=getchar();
			getchar();
		}
		for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
		if (s[i][j]=='*')
 		{
		   dfs1(i,j);k++;	
		}
	qsort(a,k,sizeof(int),cmp);
/*		for (i=1;i<m;i++)
		{
			for (j=1;j<n;j++)
				putchar(s[i][j]);
			putchar('\n');
		}*/
		printf("Throw %d\n",++reg);
		for (i=0;i<k;i++) 
		{
		   	printf("%d",a[i]);
			if (i!=k-1) printf(" ");
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
