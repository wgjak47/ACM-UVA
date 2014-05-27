#include<stdio.h>
main()
{
	int n,i,a,b;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
        if (a==b) 
		{
			if (a%2!=0) printf("Case %d: %d\n",i,a);
		    else printf("Case %d: 0\n",i);
		}
		else 
		{
        if (a%2==0) a++;
		if (b%2==0) b--;
		printf("Case %d: %d\n",i,((b-a)/2+1)*(a+b)/2);
		}
	}
	return 0;
}

