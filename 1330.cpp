#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
bool Matrix[1010][1010];
struct data
{
	int u,l,r;
};
stack<int> s;
data f[1010][1010];
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
		{
			char c=getchar();
			while (c!='F' && c!='R') c=getchar();
			if (c=='F') Matrix[i][j]=1;
			else Matrix[i][j]=0;
		}
		memset(&f,0,sizeof(f));
		int ans=0;
		for (int i=0;i<=n;i++) f[0][i].r=n+1;
		for (int i=1;i<=m;i++)
		{
			s.push(0);
			for (int j=1;j<=n;j++)
			{
				if (Matrix[i][j]) 
					f[i][j].u=f[i-1][j].u+1;
				else 
				{
					s.push(j);
					f[i][j].u=0;
				}
				if (f[i-1][j].u!=0)
				f[i][j].l=max(f[i-1][j].l,s.top());
				else f[i][j].l=s.top();
			}
			s.push(n+1);
			for (int j=n;j>=1;j--)
			{
				if (!Matrix[i][j]) s.pop();
				if (f[i-1][j].u!=0)
				f[i][j].r=min(f[i-1][j].r,s.top());
				else f[i][j].r=s.top();
					ans=max(ans,f[i][j].u*(f[i][j].r-f[i][j].l-1)*3);				
	//			printf("%d %d %d -- ",f[i][j].u,f[i][j].l,f[i][j].r);
			}
	//		putchar('\n');
			while (!s.empty()) s.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
