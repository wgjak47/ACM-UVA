#include<stdio.h>
#include<string.h>
struct trip
{
	int start,end,people,money;
};
struct trip a[30];
int vis[30];
int order,room,station;
int max;
int stack[10];
void dfs(int reg,int mon)
{
	int i,j,k;
	if (reg==order)
	{
		if (max<mon) max=mon;
		return ;
	}
	int flag=1;
	for (i=a[reg].start;i<a[reg].end;i++)
	{
		stack[i]+=a[reg].people;
		if (stack[i]>room)
			flag=0;
	}
	if (flag)
	{
		vis[reg]=1;
		dfs(reg+1,mon+a[reg].money);
	}
	for (i=a[reg].start;i<a[reg].end;i++)
		stack[i]-=a[reg].people;
	vis[reg]=0;
	dfs(reg+1,mon);
}
int cmp(const void *a,const void *b)
{
	return (((struct trip *)a)->start)-(((struct trip *)b)->start);
}
main()
{
	int i;
	freopen("data.txt","r",stdin);
	while (scanf("%d%d%d",&room,&station,&order))
	{
		max=0;
		if (room==station && station==order && order==0)
			break;
		memset(vis,0,sizeof(vis));
		memset(stack,0,sizeof(stack));
		for (i=0;i<order;i++)
		{
			scanf("%d%d%d",&a[i].start,&a[i].end,&a[i].people);
			a[i].money=(a[i].end-a[i].start)*a[i].people;
		}
		qsort(a,order,sizeof(struct trip),cmp);
		dfs(0,0);
		printf("%d\n",max);
	}
	return 0;
}
