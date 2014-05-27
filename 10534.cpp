#include<cstdio>
#include<cstring>
#define min(a,b) a<b?a:b
int c[10010];
int mid(int left,int right,int k)
{
	if (left==right) return right;
	int m=(left+right)/2;
	if (c[m]<k) return mid(m+1,right,k);
	else return mid(left,m,k);
}
main()
{
	int N;
	int a[10010];
	int df[10010],db[10010];
	while (scanf("%d",&N)==1)
	{
		memset(df,0,sizeof(df));
		memset(db,0,sizeof(db));
		for (int i=0;i<N;i++)
			scanf("%d",&a[i]);
		int j,len=0;
		memset(c,0,sizeof(c));
		for (int i=0;i<N;i++)
		{
			if (a[i]>c[len]) j=++len;
			else j=mid(1,len,a[i]);
			c[j]=a[i];
			df[i]=j-1;
		}
		len=0;
		c[len]=0;
		memset(c,0,sizeof(c));
		for (int i=N-1;i>=0;i--)
		{
			if (a[i]>c[len]) j=++len;
			else j=mid(1,len,a[i]);
			c[j]=a[i];
			db[i]=j-1;
		}
		int max=0;
		for (int i=0;i<N;i++)
		{
			int min=min(db[i],df[i]);
			if (max<min*2 && db[i]!=0 && df[i]!=0) max=min*2;
		}
		printf("%d\n",max+1);
	}	
}
