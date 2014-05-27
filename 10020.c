#include<stdio.h>
#include<string.h>
struct area
{
	int x,y;
};
struct area data[100100];
struct area stack[100100];
int m;
int l;
int cmp(const void *a,const void *b)
{
	return ((struct area *)a)->x-((struct area *)b)->x;
}
int sum;
void solve_it_fuck(int start,int lt)
{
	if (start>=m) return ;
	if (data[lt].x>start) {sum=0;return ;}
	int i;
	int max=data[lt].y,j=lt;
	for (i=lt;data[i].x<=start && i<l;i++)
		if  (data[i].y>max) {max=data[i].y;j=i;}
	stack[sum++]=data[j];
	solve_it_fuck(data[j].y,i);
}
main()
{
	int T;
	int N,i,j,k;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&m);
		l=0;
		while (scanf("%d%d",&i,&j))
		{
			if (i==j && j==0) break;
			if (j<=0 || i>=m) continue;
			data[l].x=i;
			data[l].y=j;
			l++;
		}
		qsort(data,l,sizeof(struct area),cmp);
		sum=0;
		if (data[0].x>0) sum=0;
		else 
		if (l) solve_it_fuck(0,0);
		printf("%d\n",sum);
		for (i=0;i<sum;i++)
			printf("%d %d\n",stack[i].x,stack[i].y);
		if (T) putchar('\n');
	}
	return 0;
}
