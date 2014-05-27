#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int A,C;
		scanf("%d%d",&A,&C);
		if (C%A!=0)
			printf("NO SOLUTION\n");
		else 
		{
			int t=C/A;	
			int sum=A/2;
			int i;
			for (i=1;i*t<=C;i++)
				if (A%i==0&&__gcd(A,t*i)==i)
				{
					printf("%d\n",t*i);
					break;
				}
			if (i>C) printf("NO SOLUTION\n");
		}
	}
	return 0;
}
