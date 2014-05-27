#include<cstdio>
#include<cstring>
#define B 1
#define W 0
long long ans;
long long ans1,ans2;
bool occpy[40];
int solve(int n,int k,bool color)//calulate
{
	int r=n,l=1;
	int rr=n-1,ll=2;
	int plus[40];//this is ... uhu... row??
	if (color==B)
		plus[1]=1,plus[n]=1;
	else plus[1]=2,plus[n]=2;
		while (ll<=rr)
		{
			plus[ll]=plus[ll-1]+2;
			plus[rr]=plus[rr+1]+2;
			rr--,ll++;
		}
	int sum=1;
	int has=0;
	while (l<=r)
	{
		if (occpy[l])
			sum*=(plus[l]-has),has++;
		if (occpy[r] && r!=l)
			sum*=(plus[r]-has),has++;
		l++,r--;
	}
	return sum;
}
void dfs(int n,int k,int start,int i,bool color)//show all the chooses of colunm
{
	if (i==k+1)
	{
	/*	for (int j=1;j<=n;j++)
			printf("%d ",occpy[j]);
		putchar('\n');*/
		if (color==B)
		ans1+=solve(n,k,color);
		else ans2+=solve(n,k,color);
		return ;
	}
	else 
	{
		for (int j=start+1;j<=n;j++)
		{
			occpy[j]=true;
			dfs(n,k,j,i+1,color);
			occpy[j]=false;
		}
	}
}
main()
{
	int n,k;
	while (scanf("%d%d",&n,&k)==2)
	{
		if (n==0 && k==0) break;
		ans=0;
		for (int i=0;i<=k;i++)
			if (i<=n && k-i<=n-1)		
			{
				ans1=ans2=0;
				dfs(n,i,0,1,B),dfs(n-1,k-i,0,1,W);
				ans+=ans1*ans2;
			}
		printf("%lld\n",ans);
	}	
	return  0;
}
