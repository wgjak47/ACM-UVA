#include<stdio.h>
#include<string.h>
long long terms (long long x)
{
	long long i,j,sum=0;
	while  (x!=1)
	{
		if (x%2==0)
		{
			x/=2;
			sum++;
		}
		else 
		{
			x=x*3+1;
			sum++;
		}
	}
	return sum;
}
main()
{
    long long temp,i,a,b,s[1000002],max,reg=0;
   	memset(s,-1,sizeof(s));
     while (scanf("%lld%lld",&a,&b)>0)
	 {
		 printf("%lld %lld ",a,b);
		 if (a>b) 
		 {
			 temp=a;
			 a=b;
			 b=temp;
		 }
		 max=0;
		 for (i=a;i<=b;i++)
		 {
			 if (s[i]==-1) s[i]=terms(i);
			 if (s[i]>max) max=s[i];
		 }
		 printf("%lld\n",max+1);
      }
      return 0;
}
