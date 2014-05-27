#include<cstdio>
#include<cstring>
#define MAX 10000000
#define max(a,b) a>b?a:b
struct mybig
{
	int num[40],l;
};
mybig big[1002];
void plus(int i)
{
	int l1=big[i-1].l;
	int l2=big[i-2].l;
	int l=max(l1,l2);
	int k=0;
	for (int j=0;j<l;j++)
	{
		big[i].num[j]=big[i-1].num[j]+big[i-2].num[j]+k;
		k=0;
		big[i].l=j+1;
		if (big[i].num[j]>=MAX)
		{
			big[i].num[j]-=MAX;
			k=1;
			big[i].l++;
		}
	}
	if (big[i].l==l+1) big[i].num[l]=1;
}
void outputs(mybig a)
{
	int l=a.l;
	printf("%d",a.num[l-1]);
	for (int i=l-2;i>=0;i--)
		printf("%.7d",a.num[i]);
	putchar('\n');
}
main()
{
	int n;
	big[0].num[0]=1;
	big[0].l=1;
	big[1].num[0]=2;
	big[1].l=1;
	for (int i=2;i<=1000;i++)
		plus(i);
	while (scanf("%d",&n)==1)
		outputs(big[n]);
	return 0;
}
