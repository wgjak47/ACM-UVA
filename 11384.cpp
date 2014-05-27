#include<cstdio>
#include<cstring>
long long find(int N)
{
	if (N==1) return 1;
	else return find(N/2)+1;
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		printf("%lld\n",find(N));
	}
	return 0;
}
