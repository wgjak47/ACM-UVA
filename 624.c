#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f[20000];
int an[30][20000];
int times[30];
main()
{
	int N,M;
	int i,j,k,l;
	while (scanf("%d",&N)==1)
	{
		memset(an,0,sizeof(an));
		memset(f,0,sizeof(f));
		scanf("%d",&M);
		for (i=0;i<M;i++)
			scanf("%d",&times[i]);
		for (i=M-1;i>=0;i--)		
		for (j=N;j>=0;j--)
			if (j>=times[i] && f[j]<f[j-times[i]]+times[i])
			{
				f[j]=f[j-times[i]]+times[i];
				an[i][j]=1;
			}
		j=N;			
		for (i=0;i<M;i++)
		if (an[i][j])
		{
			printf("%d ",times[i]);
			j-=times[i];
		}
		printf("sum:%d\n",f[N]);
	}
	return 0;
}
