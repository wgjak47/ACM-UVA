#include<cstdio>
#include<cstring>
struct big
{
	int num[100];
	int l;
};
big a[1011];
void plus(int i)
{
	int m=a[i-1].l;		
	for (int j=0;j<=m;j++)
	{
		a[i].num[j]+=a[i-1].num[j]*2+a[i-2].num[j]+a[i-3].num[j];
		a[i].l=j;
		while (a[i].num[j]>=1000000)
		{
			a[i].num[j+1]+=1;
			a[i].num[j]-=1000000;
			a[i].l=j+1;
		}
	}
}
void print(int N)
{
	printf("%d",a[N].num[a[N].l]);	
	for (int i=a[N].l-1;i>=0;i--)
		printf("%.6d",a[N].num[i]);
	putchar('\n');
}
main()
{
	int N;
	memset(&a,0,sizeof(a));
	a[1].l=0;
	a[1].num[0]=2;
	a[2].l=0;
	a[2].num[0]=5;
	a[3].l=0;
	a[3].num[0]=13;
	for (int i=4;i<=1001;i++)	
		plus(i);
	while (scanf("%d",&N)==1)
	print(N);
}
