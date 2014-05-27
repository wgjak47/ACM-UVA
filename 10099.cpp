#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[101][101];
int M,R;
main()
{
	int reg=0;
	while (scanf("%d%d",&M,&R),M && R)
	{
		memset(d,-1,sizeof(d));
		for (int i=0;i<R;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			scanf("%d",&d[u][v]);
			d[v][u]=d[u][v];
		}
		for (int i=1;i<=M;i++) d[i][i]=0;
		for (int i=1;i<=M;i++)
		for (int j=1;j<=M;j++)
		for (int k=1;k<=M;k++)
		{
			int temp;
			if (d[k][i]!=-1 && d[i][j]!=-1)
			temp=d[k][i]<d[i][j]?d[k][i]:d[i][j];
			else if (d[k][i]>=0) temp=d[k][i];
			else temp=d[i][j];
			d[k][j]=d[k][j]>temp?d[k][j]:temp;	
		}
		int S,D,T;
		scanf("%d%d%d",&S,&D,&T);	
		for (int i=1;i<=M;i++) d[i][i]=0;
		d[S][D]--;
		int result;
		if (d[S][D])
		{
			result=T/d[S][D];
			if (result*d[S][D]<T) result++;
		}
		else result=1;
		printf("Scenario #%d\n",++reg);
		printf("Minimum Number of Trips = %d\n\n",result);
	}
	return 0;
}
