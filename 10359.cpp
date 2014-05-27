#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
struct big
{
	int num[20];
	int l;
};
big dp[260];
const int base=10000000;
void printf_big(struct big & a)
{
	printf("%d",a.num[a.l]);
	for (int i=a.l-1;i>=0;i--)
		printf("%.7d",a.num[i]);
	putchar('\n');
}
void plus(big &a,big &b,big &c)
{
	int max=max(b.l,c.l);	
	int k=0;
	for (int i=0;i<=max;i++)
	{
		a.num[i]=b.num[i]+c.num[i]*2+k;
		k=0;
		a.l=i;
		if (a.num[i]>base)
		{
			k=a.num[i]/base;
			a.num[i]%=base;
			if (i==max) max++;	
		}
	}
}
main()
{
	int N;
	dp[1].l=0;dp[1].num[0]=1;
	dp[2].l=0;dp[2].num[0]=3;
	for (int i=3;i<=251;i++)
	{
		plus(dp[i],dp[i-1],dp[i-2]);
	}
	while (scanf("%d",&N)==1)
	if (N!=0)
	printf_big(dp[N]);
	else printf("1\n");
	return 0;
}
