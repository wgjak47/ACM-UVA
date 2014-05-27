#include<cstdio>
#include<cstring>
const char s[][5]={"XXL","XL","L","M","S","XS"};
bool G[100][100];
int result[100];
int vis[100];
bool find(int a,int n)
{
	for (int i=0;i<n;i++)
	if (!vis[i]&&G[a][i]==1)
	{	
		vis[i]=true;
		if (result[i]==-1 || find(result[i],n))
		{
			result[i]=a;
			return true;
		}
	}	
	return false;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int M,N;
		memset(G,0,sizeof(G));
		memset(result,-1,sizeof(result));
		char s1[4],s2[4];
		scanf("%d%d",&M,&N);	
		int t=M/6;
		getchar();
		for (int i=M;i<N+M;i++)
		{
			scanf("%s%s",s1,s2);
			int a1,a2;
			for (int j=0;j<6;j++)
				if (strcmp(s1,s[j])==0) a1=j;
			for (int j=0;j<6;j++)
				if (strcmp(s2,s[j])==0) a2=j;
			for (int j=0;j<t;j++)
			{
				G[a1*t+j][i]=G[i][a1*t+j]=1;
				G[a2*t+j][i]=G[i][a2*t+j]=1;
			}
		}
		int ans=0;
		for (int i=M;i<M+N;i++)
		{
			memset(vis,0,sizeof(vis));
			if (find(i,M)) ans++;
		}
		if (ans==N)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
