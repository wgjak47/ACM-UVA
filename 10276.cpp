#include<cstdio>
#include<cstring>
main()
{
	int T;
	scanf("%d",&T);
	int f[54];
	f[1]=1;
	f[2]=3;
	for (int i=3;i<=50;i++)
		f[i]=f[i-1]+((i-1)/2+1)*2;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",f[n]);		
	}
	return 0;
}
