#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define AC return 0
main()
{
	int a[10010]={0};
	int b[10010]={0};
	int n,m=0,i,j,k,l;
	char c;
	while (scanf("%d",&k)!=EOF)
	{
		   i=0;
		   while(scanf("%d%c",&a[i++],&c))
			   if (c=='\n') break;
           n=i;
	    for (i=0;i<n;i++)
		{
			b[i]=a[i];
			a[i+1]-=b[i]*(-k);
		}
		printf("q(x): ");
		for (i=0;i<n-2;i++)
			printf("%d ",b[i]);
		    printf("%d\n",b[i]);
		printf("r = %d\n",b[n-1]);
        putchar('\n');
		memset(a,0,sizeof(a));
	}
	AC;
}


