#include<stdio.h>
#include<math.h>
main()
{
      long long fuck;
      long long i;
	  long long nod;
      while (scanf("%lld",&fuck)!=EOF)
      {
		if (fuck<0) break;
		nod=(int) sqrt(fuck)+1;
		for (i=2;i<=nod;i++)
		{
			while (fuck%i==0)
			{
				printf("    %lld\n",i);
				fuck/=i;
			}
		}
		if (fuck!=1) printf("    %lld\n",fuck);
			putchar('\n');
      }
      return 0;
}
