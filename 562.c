#include<stdio.h>
#include<string.h>
int d[50010];
main()
{
	  int i,j,k,l;
	  int V[120];
      int N;
	  int T;
	  scanf("%d",&T);
	  while (T--)
	  {
		  memset(d,0,sizeof(d));
		  scanf("%d",&N);
		  int sum=0;
		  for (i=1;i<=N;i++)
		  {
			  scanf("%d",&V[i]);
			  sum+=V[i];
		  }
		  int C=sum/2;
		  for (i=1;i<=N;i++)
		  for (j=C;j>=0;j--)
		  {
			  if (j>=V[i]) d[j]=d[j]>d[j-V[i]]+V[i]?d[j]:d[j-V[i]]+V[i];
		  }
		  printf("%d\n",abs(sum-d[C]*2));
	  }
	  return 0;
}
