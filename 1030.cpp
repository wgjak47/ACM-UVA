#include<cstdio>
#include<cstring>
int n;
void find(int i,int j,int k,int p,int &x,int &y, int &z)
{
	if (i==1) {x=k;y=j;z=p;};
	if (i==2) {x=p;y=j;z=n-k+1;}
	if (i==3) {x=n-k+1;y=j;z=n-p+1;}
	if (i==4) {x=n-p+1;y=j;z=k;}
	if (i==5) {x=k;y=p;z=n-j+1;}
	if (i==6) {x=k;y=n-p+1;z=j;}
}
main()
{
	char vis[12][12][12];
	char G[7][12][12];
	while (scanf("%d",&n)==1)
	{
		if (n==0) break;
		getchar();
		memset(G,0,sizeof(G));
		memset(vis,'#',sizeof(vis));
		for (int i=1;i<=n;i++)
		for (int j=1;j<=6;j++)
		scanf("%s",G[j][i]);	
		for (int i=1;i<=6;i++)
		for (int j=1;j<=n;j++)
		for (int k=1;k<=n;k++)
		if (G[i][j][k-1]=='.')
		for (int p=1;p<=n;p++)
		{
			int x,y,z;
			find(i,j,k,p,x,y,z);
				vis[x][y][z]='.';
//			printf("%d  %d  %d\n",x,y,z);
		}
		int ans=0;
		while (1)
		{
			bool done=true;
			for (int i=1;i<=6;i++)
			for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
			if (G[i][j][k-1]!='.')
			{
				for (int p=1;p<=n;p++)
				{
					int x,y,z;
					find(i,j,k,p,x,y,z);
					if (vis[x][y][z]=='.') continue;
					if (vis[x][y][z]=='#') 
					{
						vis[x][y][z]=G[i][j][k-1];
						break;
					}
					if (vis[x][y][z]==G[i][j][k-1]) break;
					vis[x][y][z]='.';
					done=false;
				}
			}
			if (done) break;
		} 
		ans=0;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		for (int k=1;k<=n;k++)
			if (vis[i][j][k]!='.')
				ans++;
		printf("Maximum weight: %d gram(s)\n",ans);
	}
	return 0;
}
