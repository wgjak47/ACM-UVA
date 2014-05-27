#include<cstdio>
#include<cstring>
int value[510][510];
int eve[10][110];
int T[10];
int l[10];
int floor[10][110];
int Djstl(int start,int goal,int n,int k)
{
	bool vis[510];
	int cost[510];
	memset(vis,0,sizeof(vis));
	vis[start]=true;
	for (int i=0;i<k;i++) cost[i]=value[i][start];
	cost[start]=0;
	int pre=start;
	for (int i=0;i<k;i++)
	{
		int min=1000000000;
		for (int j=0;j<k;j++)	
			if (!vis[j] && cost[pre]+value[pre][j]<cost[j])
				cost[j]=cost[pre]+value[pre][j];
		for (int j=0;j<k;j++)
			if (!vis[j] && cost[j]<min)
			{
				min=cost[j];pre=j;
			}
		vis[pre]=1;
	}
		int ans=1000000000;
		for (int i=0;i<n;i++)
			ans=ans<cost[i*100+goal]?ans:cost[i*100+goal];
		return ans;
}
main()
{
	int n,k;
	while (scanf("%d%d",&n,&k)==2)
	{
		memset(l,0,sizeof(l));
		memset(value,0x2f,sizeof(value));
		memset(floor,0,sizeof(floor));
		for (int i=0;i<n;i++) scanf("%d",&T[i]);
		for (int i=0;i<n;i++)
		{
			while (1)
			{
				int u;
				scanf("%d",&u);
				floor[i][u]=true;
				eve[i][l[i]++]=u;
				char c=getchar();
				if (c=='\n') break;	
			}
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<l[i];j++)
			for (int k=j+1;k<l[i];k++)
				value[i*100+eve[i][j]][i*100+eve[i][k]]=value[i*100+eve[i][k]][i*100+eve[i][j]]=(eve[i][k]-eve[i][j])*T[i];
		}
		for (int j=0;j<100;j++)
		for (int o=0;o<n;o++)
		for (int z=0;z<n;z++)
			if (z!=o && floor[o][j] && floor[z][j]) 
			value[o*100+j][z*100+j]=60;
		int ans=1000000000;
		for (int i=0;i<n;i++)
		{
			int temp=Djstl(i*100,k,n,(n-1)*100+99);
			ans=ans<temp?ans:temp;
		}
		if (ans<10000000)
			printf("%d\n",ans);
		else printf("IMPOSSIBLE\n");
	}
	return  0;	
}
