#include<stdio.h>
#include<string.h>
int  s[120][20];
int a[20];
int m,n,total,sum;
int  judge()
{
	int i,j,k,l,fuck=0;
	for (i=0;i<n-1;i++)
	for (j=i+1;j<n;j++)
	{
		int cao=0;
		for (k=0;k<m;k++)
		if (a[k]&&s[i][k]!=s[j][k])
		{
			cao=1;
			break;
		}
		if (!cao) return 0;
	}
	for (i=0;i<m;i++)
		if (a[i]) fuck++;
	if (sum>fuck) sum=fuck;
}
void allziji(int reg)
{
	if (reg==m)
		judge();
	else
	{
		a[reg]=0;
		allziji(reg+1);
		a[reg]=1;
		allziji(reg+1);
	}
}

main()
{  
	int i,j,k,l,q;
/*	freopen("in.txt","r",stdin);*/
	scanf("%d",&total);
	while (total--)
 	{
		memset(a,0,sizeof(a));
		scanf("%d%d",&m,&n);
		for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			scanf("%d",&s[i][j]);
		sum=m;
		allziji(0);
		printf("%d\n",sum);
	}
	return 0;
}
