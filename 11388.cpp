#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int G,L;
		scanf("%d%d",&G,&L);
		if (L%G==0)
			printf("%d %d\n",G,L);
		else printf("-1\n");
	}
	return 0;
}
