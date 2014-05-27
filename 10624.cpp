#include<cstdio>
#include<cstring>
int num[40];
int M,N;
bool find;
inline bool cal(int k,int n)
{
	int mod=0;
	num[k]=n;
	for (int i=1;i<=k;i++)
	{
		mod=mod*10+num[i];
		mod%=k;
	}
	if (mod==0) return true;
	return false;
}
void dfs(int k)
{
	if (k==N+1) 
	{
		for (int i=1;i<=N;i++)
			printf("%d",num[i]);
		printf("\\n\")");
		find=true;
	}
	for (int i=0;i<10;i++)
	if (!find && (k<M || cal(k,i)))
		dfs(k+1);
}
main()
{ 
	int T;
	int ans=0;
	scanf("%d",&T);
	while (T--)
	{
		find=false;
		scanf("%d%d",&M,&N);	
		printf("if (M==%d && N==%d) ",M,N);
		printf("printf(\"");
		for (int i=1;i<10;i++)
		{
			num[1]=i;
			dfs(2);
			if (find)
				break;
		}
		if (!find)
		printf("-1\\n\")");
		putchar('\n');
		printf("else ");
	}
	return 0;
}
