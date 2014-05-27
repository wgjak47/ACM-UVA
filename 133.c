#include<stdio.h>
#include<stdlib.h>
main()
{
	int a[30];
    int i,j,k,l,m,n,reg,reg1,reg2;
	int start,end,flag;
	while (scanf("%d%d%d",&n,&k,&m)==3)
	{
	if (m==0 && n==0 && k==0) break;
	start=1;end=n;reg=0,flag=0;;
	for (i=1;i<=n;i++)
		a[i]=i;
	while (1)
	{
		for (i=1;i<=n;i++)
		if (a[i]!=-1) {flag=1;break;}
	   	if (!flag) break;
		if (reg++!=0) putchar(',');
		reg1=0;reg2=0;
		for (i=start;i<=n;i++)
		{
			if (a[i]!=-1)
				reg1++;
			if (reg1==k)
				break;
			else if (i==n) i=0;
		}
		for (j=end;j>=1;j--)
		{
			if (a[j]!=-1)
				reg2++;
			if (reg2==m)
				break;
			else if (j==1) j=n+1;
		}
		if (i==j)
		{
			printf("%3d",a[j]);
			start=i;
			end=j;
			a[j]=-1;
		}
		else 
		{
			printf("%3d%3d",a[i],a[j]);
			start=i;
			end=j;
			a[i]=-1;
			a[j]=-1;
		}
		flag=0;
	}
	putchar('\n');
	}
	return 0;
}



