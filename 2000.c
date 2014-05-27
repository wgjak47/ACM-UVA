#include<stdio.h>
main()
{
unsigned long long num,n,j;
scanf("%llu",&num);
for (j=1;j<=num;j++)
{
scanf("%llu",&n);
printf("%llu\n",(n)*(n+1)+3*n);
}
return 0;
}
