#include<cstdio>
#include<cstring>
#include<cmath>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
double distance[110][110];
int x[110],y[110];
double cal(double x1,double y1,double x2,double y2)
{
	double temp=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	if (sqrt(temp)>10.0)
		return 100000000.0;
	return sqrt(temp);
}
main()
{
	int T,cases=0;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			distance[i][j]=100000000.0;
		for (int i=0;i<n;i++)	
			scanf("%d%d",&x[i],&y[i]);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			distance[i][j]=cal(x[i]*1.0,y[i]*1.0,x[j]*1.0,y[j]*1.0);
		for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			distance[i][j]=min(distance[i][k]+distance[k][j],distance[i][j]);
		double max=0;
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)
			max=max(distance[i][j],max);
		printf("Case #%d:\n",++cases);
		if (max<100000000.0)
			printf("%.4f\n",max);
		else 
			printf("Send Kurdy\n");
		putchar('\n');
	}
	return 0;
}
