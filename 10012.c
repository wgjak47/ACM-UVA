#include<stdio.h>
#include<string.h>
#include<math.h>
double number[10];
int vis[10];
int l;
double min;
double stack[200];
int num[200];
double sum(double r1,double r2)
{
	if (r1<=1e-6) return r2;
	else if (r2<=1e-6) return r1;
	return sqrt((r1+r2)*(r1+r2)-(r1-r2)*(r1-r2));
}
void find_min(int reg)
{
	int i,j;
	if (reg==l+1)
	{
		double fuck=0,shit=stack[reg-1];
		for (i=1;i<reg;i++) 
		{
		/*	printf("%d ",num[i]);*/
			if (stack[i]-number[num[i]]<0) 
				if (fuck>stack[i]-number[num[i]]) fuck=stack[i]-number[num[i]];
			if (stack[i]+number[num[i]]>stack[reg])
				if (shit<stack[i]+number[num[i]]) shit=stack[i]+number[num[i]];
		}
/*		printf("%.3lf ",stack[i]);
		putchar('\n');
		printf("%.3lf %.3lf %.3lf\n",shit,fuck,shit-fuck);*/
		if (shit-fuck<min) min=shit-fuck;
	}
	for (i=1;i<=l;i++)
		if (!vis[i])
		{
			vis[i]=1;
			num[reg]=i;
			double max=0,temp;
			for (j=1;j<reg;j++)
			{
				temp=stack[j]+sum(number[i],number[num[j]]);
				if (temp>max) max=temp;
			}
			stack[reg]=max;
			find_min(reg+1);
			vis[i]=0;
		}
}
main()
{
	int i,j,k;
	scanf("%d",&k);
	while (k--)
	{
		memset(stack,0,sizeof(stack));
		min=100000000;
		scanf("%d",&l);
		for (i=1;i<=l;i++)
			scanf("%lf",&number[i]);
		find_min(1);
		printf("%.3lf\n",min);
	}
	return 0;
} 
