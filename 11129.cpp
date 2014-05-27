//分治法
#include<cstdio>
#include<cstring>
int data[10010];
int temp[10010];
void divide(int l,int r)
{
	if (r-l<=1) return ;
	for (int i=l;i<=r;i++)
		temp[i]=data[i];
	int i,j;
	for (i=l,j=l;j<=r;j+=2,i++)
		data[i]=temp[j];
	for (j=l+1;j<=r;j+=2,i++)
		data[i]=temp[j];
	divide(l,(l+r)/2);
	divide((l+r)/2+1,r);
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		for(int i=0;i<N;i++) data[i]=i;
		printf("%d:",N);	
		divide(0,N-1);
		for (int i=0;i<N;i++)
			printf(" %d",data[i]);
		putchar('\n');
	}
	return 0;
}
