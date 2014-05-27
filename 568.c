#include<stdio.h>
#include<math.h>
int a[10000]={0};
main()
{
  unsigned long long x,y,z,sum=1;
  int i,j,k=0;
  for (i=1;i<10000;i++)
  {
   j=i;
   while (j%10==0) j/=10;
   sum=sum * j % 1000000;
   while (sum%10==0) sum/=10;
   a[i]=sum;
  }
  while (scanf("%d",&k)==1)
  {
	  if (k==0) printf("%d -> 1\n",k);
	  else
	  printf("%5d -> %d\n",k,a[k]%10);
  }
  return 0;
}
