#include<stdio.h>
#include<string.h>
#define swap(A,B); {atemp=(A);(A)=(B);(B)=(atemp);}
int a[10];
int copy[10];
int total;
int N;
int reg;
int judge(int *temp,int *copy)
{
	int i;
	for (i=0;i<N;i++)
		if (temp[i]!=copy[i]) return 0;
	return 1;
}
void sort(int ans)
{
	int temp[1000];
	int i,j,k,l,atemp;
	if (ans==reg)
	{
		if (judge(copy,a))
			total++;
			return ;
	}
	else 
	{
		for (i=0;i<N-1;i++)
		{
			memcpy(temp,copy,sizeof(copy));
			swap(copy[i],copy[i+1]);
			sort(ans+1);
			memcpy(copy,temp,sizeof(copy));
		}
	}
}
main()
{ 
	int i,j,l,k,atemp;
	int fuck=0;
	while (scanf("%d",&N)==1)
	{
		total=0;
		if (N==0) break;
		reg=0;
		for (i=0;i<N;i++)
			scanf("%d",&a[i]);
		memcpy(copy,a,sizeof(copy));
		for (i=0;i<N;i++)
		for (j=0;j<N-i-1;j++)
			if (a[j]>a[j+1])
 			{
				reg++;
				swap(a[j],a[j+1]);
 			}
		if (reg) sort(0);
		else total=0;
/*		for (i=0;i<N;i++)
			printf("%d ",a[i]);
		putchar('\n');*/
		printf("There are %d swap maps for input data set %d.\n",total,++fuck);
  	}
	return 0;
} 
