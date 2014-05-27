#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	double temp=0;
	long long m,n,a,b;
	long long i,j,k,l,h,g,sum;
	while(scanf("%lld%lld",&m,&n)!=0)
	{
		if (m==0 && n==0) break;
		a=sqrt(m);
		if (n==1)
		{
		sum=(1-2*m)/(1-2);
   	    printf("%.0lf ",log2(m));
		printf("%lld\n",sum);
		}
        else 
		for (i=2;i<=a+1;i++)
		{
			if (m%i==0)
			{
				temp=log(m)/log(i);
				k=(long long)floor(temp+0.5);
				if (temp-k<0.00000000001)
				{
						temp=log(n)/log(i-1);
						k=(long long)floor(temp+0.5);
						if (fabs(temp-k)<0.00000000001)
						{
				        sum=(1-i*n+n)/(2-i);
                        printf("%lld ",sum-n);
						sum=0;l=0;
						while (m>0)
						{
							sum+=m*(long long)floor(pow(i-1,l)+0.5);
							l++;m/=i;
						} 
						printf("%lld\n",sum);
				}
			}
			}
		}
	}	
	return 0;
}

