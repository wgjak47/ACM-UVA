#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int x[200],y[200];
int n,sum;
int G[100][100]={0};
void find(int *a,int *b)
{
	int i,j,k;
	int zheng=0,fu=0,flag=0;
	for (i=-100;i<=100;i++)
	for (j=-100;j<=100;j++)
	if (!G[abs(i)][abs(j)])
	{ 
	 zheng=0;fu=0;flag=0;
		for (k=0;k<2*n;k++)			
	 	{
			sum=i*x[k]+j*y[k];
			if (sum==0)  { flag=1;break;}
			if (sum>0) zheng++;
			if (sum<0) fu++;
		}
		if (zheng==fu && !flag) { *a=i;*b=j;return ;}
	}
}
int gy(int i,int j)
{
	return j==0?i:gy(j,i%j);
}
main()
{
	int i,a,b,j;
	int reg=0;
	for (i=1;i<=100;i++)
	for (j=i+1;j<=100;j++)
		if (gy(i,j)==1)
		{
			G[i][j]=1;
			G[j][i]=1;
		}
	while (scanf("%d",&n)==1)
	{
		if (n==0) break;
		for (i=0;i<2*n;i++)
			scanf("%d %d",&x[i],&y[i]);
		find(&a,&b);
		printf("%d %d\n",a,b);
	}
	return 0;
}	
