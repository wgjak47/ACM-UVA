#include<cstdio>
#include<cstring>
int f[10011];
main()
{
	int n,k,m;
	while (scanf("%d%d%d",&n,&k,&m)==3)
	{
		if (n==0 && k==0 && m==0) break;
		f[1]=0;
		for (int i=2;i<=n;i++)
			f[i]=(f[i-1]+k)%i;
		int ans=(m-k+1+f[n])%n;
		if (ans<=0) ans+=n;
		printf("%d\n",ans);
	}
	return 0;
	
}
