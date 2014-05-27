#include<stdio.h>
#include<string.h>
int sum[30010];
int v[30010];
int M,N;
int find(int a)
{
	if (a!=v[a]) v[a]=find(v[a]);
	return v[a];
}
void fuck(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if (x==y) return;
	if (sum[x]>sum[y])
	{
		sum[x]+=sum[y];
		v[y]=x;
	}	
	else 
	{
		sum[y]+=sum[x];
		v[x]=y;
	}
}
void ainit()
{
	int i,j,k;
	for (i=1;i<=N;i++)
	{
		v[i]=i;
		sum[i]=1;
	}		
}
main()
{
	int T;
	int i,l,j;
	int a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&N,&M);
		ainit();
		for (i=0;i<M;i++)
		{
			scanf("%d%d",&a,&b);
			fuck(a,b);
		}
		int max=0;
		for (i=1;i<=N;i++)
			if (sum[i]>max) max=sum[i];
		printf("%d\n",max);
	}
	return 0;
}
