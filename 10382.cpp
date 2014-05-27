#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
struct circle
{
	double left,right;
};
circle d[10010];
int cmp(const void *a,const void *b)
{
	circle *x=(circle *)a;
	circle *y=(circle *)b;
	return x->left>y->left?1:-1;
}
main()
{
	int N,L,W;
	int K,c,r;
	while (scanf("%d%d%d",&N,&L,&W)==3)
	{
		K=0;
		for (int i=0;i<N;i++)
		{
		scanf("%d%d",&c,&r);
		if (r*2>=W)
		{
			d[K].right=(double)c+sqrt((double)r*r*1.0-(double)W*W/4.0);	
			d[K].left=(double)c-sqrt((double)r*r*1.0-(double)W*W/4.0);
			K++;
		}
	}	
	qsort(d,K,sizeof(circle),cmp);
	double max=0;
	double start=0;
	int sum=0;
	for (int i=0;i<K;i++)
	{
		if (d[i].left<=start)
		{
			if (max<d[i].right)
			max=d[i].right;
		}
		else 
		{
			if (max>=L || d[i].left>max) break;
			start=max;
			sum++;
			if (d[i].right>max) max=d[i].right;
		}	
	}
	if (max>=L)
	printf("%d\n",sum+1);
	else printf("-1\n");
	}
	return 0;
}
