//V-E+F=2
//V=n+n/4*sum(1,n-3,i*(N-2-i))
//E=n+n/2*sum(1,n-3,i*(N-2-i)+1)
#include<cstdio>
#include<cstring>
main()
{
	int n;
	int E,F,V;
	int S;
	scanf("%d",&S);
	while (S--)
	{
		scanf("%d",&n);
		F=0;
		for (int i=1;i<=n-3;i++)
			F+=i*(n-2-i);
		F=(F+2*n-2)*n/4+1;
		printf("%d\n",F);
	}
	return 0;
}
