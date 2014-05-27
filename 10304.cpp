#include<cstdio>
#include<cstring>
#define INF 100000000
int w[255][255];
int e[255][255];
main()
{
	int N;
	int f[251];	
	while (scanf("%d",&N)==1)
	{
		int sum=0;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&f[i]);
			sum+=f[i];
		}
		memset(e,0,sizeof(e));
		for (int l=1;l<=N;l++)
			for (int i=1;i<=N-l+1;i++)
			{
				int j=i+l-1;
				e[i][j]=INF;
				w[i][j]=w[i][j-1]+f[j];
				for (int r=i;r<=j;r++)
				{
					int temp=e[i][r-1]+e[r+1][j]+w[i][j];
					if (temp<e[i][j]) e[i][j]=temp;
				}
			}
		printf("%d\n",e[1][N]-sum);
	}
	return 0;
}
