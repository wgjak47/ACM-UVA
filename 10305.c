#include<stdio.h>
#include<string.h>
int Gra[104][104];
int put[110];
int con[110];
int m,n,t;
int dfs(int x)
{
	con[x]=-1;
	int i;
	for (i=1;i<=m;i++)
		if (Gra[x][i])
		{
			if (con[i]<0) return 0;
			else if (con[i]==0 && dfs(i)==0) return 0;
		}
		con[x]=1;
		put[--t]=x;
		return 1;
}
int sort()
{
	t=m;
	int i;
	for (i=1;i<=m;i++)
		if (!con[i])
			if (!dfs(i)) return 0;
	 return 1;
}
main()
{ 
	int i,j,k,l,temp1,temp2,test;
	while (scanf("%d%d",&m,&n)==2)
 	{
		if (m==0 && n==0) break;
		memset(Gra,0,sizeof(Gra));
		memset(con,0,sizeof(con));
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&temp1,&temp2);
			Gra[temp1][temp2]=1;
 		}
		test=sort();
		for (i=0;i<m;i++)
		{
			printf("%d",put[i]);
			if (i!=m-1) putchar(' ');
		}
		printf("\n");
	}
	return 0;
}
