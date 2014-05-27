#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
#define swap(a,b,c,d) {int temp=e[a][b];e[a][b]=e[c][d],e[c][d]=temp;}
int a[5]={0,1,0,-1};
int b[5]={1,0,-1,0};
char s[5]={"URDL"};
char out[20];
unsigned long long f[20];
bool found;
set<unsigned long long> data;
unsigned long long cal(int z[][5])
{
	unsigned long long sum=0;
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++)
		sum+=f[(i-1)*4+j]*z[i][j];
	return sum;
}
void dfs(int z[][5],int x,int y,int k)
{
	int e[5][5];
	if (found) return ;
	if (k==15) return ;
	for (int i=0;i<4;i++)
		if (x+a[i]>=1 && x+a[i]<=n && y+b[i]>=1 && y+b[i]<=n)
		{
			if (found) return ;
			memcpy(e,z,sizeof(e));
			out[k]=s[i];
			swap(x,y,x+a[i],y+b[i]);
			unsigned long long hash=cal(e);
			if (data.find(hash)==)
			dfs(temp,x+a[i],y+b[i],k+1);
		}
}
main()
{
	
	int T;
	int z[5][5];
	scanf("%d",&T);
	f[0]=1;
	for (int i=1;i<16;i++)
		f[i]=f[1]*16;
	while (T--)
	{
		int x,y;
		found=0;
		for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
		{
			scanf("%d",&z[i][j]);	
			if (z[i][j]==0)
				x=i,y=j;
		}
		dfs(int *z,x,y,0);
	}
	return 0;
}
