#include<stdio.h>
long long jc(long long m)
{
    if (m>1) return m=m*jc(m-1);
    else return 1;
}
main()
{
    long long s,k,sum=0;
    int i,j=0;
    scanf("%lld",&k);
    for (i=1;i<=k;i++)
    {
        sum+=jc(i);
        if (sum>=4294967295)
        {j=1; break;}
    }
    if (j==1)printf("overflow");
     else printf("%lld",sum);
}
