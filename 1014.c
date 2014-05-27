#include<stdio.h>
#include<math.h>
main()
{
    int i;
  double x;
  double m;
  scanf("%lf",&x);
  m=frexp(x,&i);
  printf("%d",i-1);
  return 0;
}
