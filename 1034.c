#include<stdio.h>
#include<string.h>
main()
{
	long long n,m,i,j,k,l,cur[1010],per[1010],pm,cm,maxline=0;
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	{
		memset(cur,0,sizeof(cur));
		scanf("%lld",&m);
		for (j=1;j<=m;j++)
			scanf("%lld",&cur[j]);
		    cm=m;
	    if (cm>=pm) maxline=cm;
		else maxline=pm;
		if (i!=1)
		{
			for (j=1;j<maxline;j++)
            printf("%lld ",per[j]+cur[j]);
		    if (maxline>=1) printf("%lld",per[maxline]+cur[maxline]);
			putchar('\n');
			maxline=0;
		}
		memcpy(per,cur,sizeof(cur));
		pm=cm;
	}
	for (i=1;i<m;i++)
      printf("%lld ",cur[i]);
	if (m>=1) printf("%lld",cur[m]);
	putchar('\n');
	return 0;
}



