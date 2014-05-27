#include<stdio.h>
main()
{
    long long A,limit,a,l,number,i=0;
    while(scanf("%lld%lld",&a,&l)>0)
    {
        i++;A=a;
        if (a==l && l==-1) break;
        number=1;
        while (a!=1)
        {
           if (a<=l)
           if (a%2==0)
            {
                number++;
                a/=2;
            }
            else 
            {
                number++;
                a=a*3+1;
            }
           else { number--; break; }
        }
     printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",i,A,l,number);
    }
    return 0;
}

