#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
int in[5010];
queue <int> x;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int N;
	while (scanf("%d",&N),N!=0)
	{
		for (int i=0;i<N;i++)
		scanf("%d",&in[i]);
		qsort(in,N,sizeof(int),cmp);
		x.push(in[0]+in[1]);
		for (int i=2;i<N;i++)
		{
			
		}
	}
	return 0;
}
