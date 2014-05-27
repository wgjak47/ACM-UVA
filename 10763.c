#include<stdio.h>
#include<string.h>
int G[1000][1000];
main()
{
	int N,i,j,k;
	int a1[500002],a2[500002];
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		int yes=1;
		for (i=0;i<N;i++)
		{
			scanf("%d%d",&a1[i],&a2[i]);
			G[a1[i]][a2[i]]++;
		}
		for (i=0;i<N;i++)
			if (G[a1[i]][a2[i]]!=G[a2[i]][a1[i]])
			{
				yes=0;
				G[a1[i]][a2[i]]=G[a2[i]][a1[i]]=0;
			}
		if (yes)
		printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
