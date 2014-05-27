#include<stdio.h>
main()
{
	int i,j,k=0,l,m,n;
	int a[100],aver,reg;
	while (scanf("%d",&n)>0)
	{
	  if (n==0) break;
	  aver=0;reg=0;
	  for (i=0;i<n;i++)
	  {
	  scanf("%d",&a[i]);
      aver+=a[i];
	  }
	  aver=aver/n;
	  for (i=0;i<n;i++)
	  if (a[i]>aver)
		  reg+=a[i]-aver;
	  printf("Set #%d\n",++k);
	  printf("The minimum number of moves is %d.\n\n",reg);
	}
	return 0;
}
