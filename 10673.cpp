#include<cstdio>
#include<cstring>
main()
{
	int x,k;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&x,&k);
		if (x<=k) 
			printf("0 %d\n",x);
		else if (x/k*k==x)
		{
			printf("0 %d\n",k);	
		}
		else 
		{
			int z=x/k;
			int p,q;
			for (p=0;p<=k+1;p++)
			{
				int sum=x-p*(z+1);
				q=sum/z;
				if (q*z!=sum) continue;
				else break;
			}
			printf("%d %d\n",q,p);
		}
	}
	return 0;
}
