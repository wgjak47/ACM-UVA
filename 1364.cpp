#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX (1<<17)+10
int name[MAX],length[MAX],r[MAX];
double frequence[MAX];
int cmp(const void *a,const void *b)
{
	int x=*(int *)a,y=*(int *)b;
	return frequence[x]*length[y]-frequence[y]*length[x]<0?1:-1;
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{ 
		for (int i=0;i<N;i++)
		{
			r[i]=i;
			scanf("%d%d%lf",&name[i],&length[i],&frequence[i]);
		}
		int lt;
		scanf("%d",&lt);
		qsort(r,N,sizeof(int),cmp);	
		printf("%d\n",name[r[lt-1]]);
	}
	return 0;
}
