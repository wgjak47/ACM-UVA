#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10010],b[10010];
main()
{
	int n,d,r;
	while (scanf("%d%d%d",&n,&d,&r)==3)
	{
		if (n==0 && d==0 && r==0) break;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int j=0;j<n;j++)
			scanf("%d",&b[j]);
		sort(a,a+n);sort(b,b+n);
		int j=n-1;
		long long sum=0;
		for (int i=0;i<n;i++)
		{
			if (a[i]+b[j]>d)
				sum+=-(d-a[i]-b[j])*r;
			j--;
		}	
		printf("%lld\n",sum);
			
	}
	return 0;
}
