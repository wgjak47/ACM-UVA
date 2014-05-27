#include<stdio.h>
#include<string.h>
#define MIN(a,b) a>b?b:a
#define swap(a,b) {t=a;a=b;b=t;}
int V[12][120];
int T[12][120];
int M,N;
int p[12][120];
main()
{
	int i,j,k,l,m,n;
	while (scanf("%d%d",&M,&N)==2)
 	{
		memset(p,0,sizeof(p));
		for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			scanf("%d",&V[i][j]);
		memset(T,0,sizeof(T));
		for (i=0;i<M;i++)
			T[i][N-1]=V[i][N-1];
		for (j=N-2;j>=0;j--)
		for (i=0;i<M;i++)
 		{
			int x = (T[(i+1)%M][j+1] < T[(i-1+M)%M][j+1]) ? ((i+1)%M) : ((i-1+M)%M);
			if (T[(i+1)%M][j+1] == T[(i-1+M)%M][j+1]) x = MIN((i+1)%M, (i-1+M)%M);
			if (T[x][j+1] > T[i][j+1] || (T[x][j+1] == T[i][j+1] && i < x)) x = i;
			T[i][j] = T[x][j+1] + V[i][j];
			p[i][j] = x;
		}
		int min=0;
		for (j=1;j<M;j++)
			if (T[min][0]>T[j][0])
				min=j;
		printf("%d",min+1);
			l=min;
		for (j=0;j<N-1;j++)
		{
			printf(" %d",p[l][j]+1);
			l=p[l][j];
		}	
		putchar('\n');
		printf("%d\n",T[min][0]);
	}
	return 0;
}
