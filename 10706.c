#include<stdio.h>
#include<string.h>
#include<ctype.h>
int data[165636];
long long sum[165636];
char max[1000000];
int lgs(int n)
{
	int reg=0;
	while (n)
	{
		n/=10;
		reg++;
	}
	return reg;
}
void advance()
{
	int n;
	int j=0;
	for (n=1;n<=65536;n++)
	{
		sprintf(&max[j],"%d",n);
		while (isdigit(max[j])) j++;
	}
	data[1]=1;
	sum[1]=1;
	for (n=2;n<=65536;n++)
	{
		data[n]=data[n-1]+lgs(n);
		sum[n]=sum[n-1]+data[n];
	}
	return  ;
}
int bsearch(int x,int y,int v)
{
	int m;
	while (x<y)
	{
		m=x+(y-x)/2;
		if (sum[m]==v) return m;
		else if (sum[m]>v) y=m;
		else x=m+1;
	}
	return x;
}
main()
{
	int N;
	advance();
	scanf("%d",&N);
	while (N--)
	{
		int v;
		scanf("%d",&v);
		int result=bsearch(1,65536,v)-1;
		if (v==1) printf("1\n"); 
		else 
		printf("%c\n",max[v-sum[result]-1]);
	}	
	return 0;
}
