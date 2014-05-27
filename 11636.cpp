#include<cstdio>
#include<cstring>
#include<cstdlib>
int a[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384}; 
int mid(int t)
{
	int l=0,r=14;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (t<a[mid]) r=mid;
		else if (t==a[mid]) return mid;
		else l=mid+1;	
	}
	return l;
}
main()
{
	int N;
	int t=0;
	while (scanf("%d",&N)==1)
	{ 
		if (N<0) return 0;
		t++;
		printf("Case %d: ",t);
		printf("%d\n",mid(N));
	}
	return 0;
}
