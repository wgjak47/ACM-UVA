#include<cstdio>
#include<cstring>
int a[8];
int vis[10];
int flag;
int test1[10];
int test[10];
void express(int reg,int exp,int sum)
{
    if (flag) return ;
    int i;
    for (i=1;i<=5;i++)
    if (!vis[i])
    {
        vis[i]=1;
		int temp;
		if (exp==1) temp=sum+a[i];
		else 
		if (exp==2) temp=sum-a[i];
		else 
		if (exp==3) temp=sum*a[i];
		if (reg==5)
			if (temp==23)
			{
			//	putchar('\n');
/*			for (int j=0;j<=10;j++)
				printf("%d ",test[j]);
                putchar('\n');
			for (int j=1;j<=5;j++)
				printf("%d ",test1[j]);
				putchar('\n');*/
				flag=1;
				return ;
			}
        else
		{
		/*	for (int j=1;j<=5;j++)
				printf("%d ",test[j]);
			putchar('\n');*/
			vis[i]=0;
            return ;
		}
			express(reg+1,1,temp);
			if (flag) return ;
			express(reg+1,2,temp);
			if (flag) return ;
			express(reg+1,3,temp);
			vis[i]=0;
    }
}
main()
{
	int zero;
	while (1)
	{
	    zero=0;
	    flag=0;
	    memset(vis,0,sizeof(vis));
	    for (int i=1;i<=5;i++)
	    {
	      scanf("%d",&a[i]);
	      if (a[i]==0) zero++;
	    }
	    if (zero==5) break;
	    express(1,1,0); 
			if (flag)	printf("Possible\n");
	    else printf("Impossible\n");
	   /* printf("Yeah\n");*/
	}
	return 0;
}
