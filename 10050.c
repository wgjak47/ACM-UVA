#include<stdio.h>
#include<string.h>
main()
{
	int day[4000];
	int i,j,k,l,m,reg;
    int n,p,h[200],t;
	scanf("%d",&t);
	while (t--)
	{
		reg=0;
		memset(day,0,sizeof(day));
		scanf("%d",&n);
		scanf("%d",&p);
		for (i=0;i<p;i++)
			scanf("%d",&h[i]);
	    for (i=0;i<p;i++)
		for (j=1;j*h[i]<=n;j++)
			day[j*h[i]]=1;
        for (i=1;i<=n;i++)
		    if (day[i]==1 && i%7!=0&& i%7!=6)
				reg++;
		printf("%d\n",reg);
	}
	return 0;
}
