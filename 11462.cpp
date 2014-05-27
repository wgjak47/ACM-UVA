#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Z[2000010];
main()
{
	int N;
	int reg[111];
	while (scanf("%d",&N),N)
	{
		memset(reg,0,sizeof(reg));
		for (int i=0;i<N;i++)
		{
			scanf("%d",&Z[i]);	
			reg[Z[i]]++;
		}
		int r=0;
		for (int i=0;i<=100;i++)
			while (reg[i])
			{
				if (r++) putchar (' ');
				printf("%d",i);
				reg[i]--;
			}
		putchar('\n');
	}
	return 0;
}
