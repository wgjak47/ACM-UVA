#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int a[10000];
	int b[10000];
	int i,k,j,l,m,n,reg=0;;
	while (scanf("%d%d",&n,&m),m!=0 && n!=0)
	{
      printf("CASE# %d:\n",++reg);
	  for (i=0;i<n;i++)
		  scanf("%d",&a[i]);
	  qsort(a,n,sizeof(int),cmp);
	  for (i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
			for (j=0;j<n;j++)
			if (a[j]==b[i])
			{
	        printf("%d found at %d\n",b[i],j+1);
			break;
			}
			if (j==n) printf("%d not found\n",b[i]);
		}
	}
	return 0;
}

