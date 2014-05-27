#include<cstdio>
#include<cstring>
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		int m=1;
		int reg=0;
		while (m%N)
		{
			m=m%N*10%N+1;
			reg++;
		}
		printf("%d\n",reg+1);
	}
	return 0;
}
