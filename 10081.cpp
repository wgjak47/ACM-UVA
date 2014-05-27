#include<cstdio>
#include<cstring>
double get_ans(int k,int n)
{
	double f[110][11];
	memset(f,0,sizeof(f));
	for (int i=0;i<=k;i++) f[1][i]=1;
	for (int i=2;i<=n;i++)
	for (int j=0;j<=k;j++)
		if (j==0) f[i][j]=f[i-1][j]+f[i-1][j+1];
		else if (j==k) f[i][j]=f[i-1][j-1]+f[i-1][j];
		else f[i][j]=f[i-1][j-1]+f[i-1][j+1]+f[i-1][j];
	double ans=0;
	for (int i=0;i<=k;i++)
		ans+=f[n][i];
	double sum=1;
	for (int i=1;i<=n;i++)
		sum*=(k+1);
	if (k==0) return 100.0;
	return ans/sum*100.0;
}
main()
{
	int n,k;
	while (scanf("%d%d",&k,&n)==2)
		printf("%.5f\n",get_ans(k,n));
	return 0;
}
