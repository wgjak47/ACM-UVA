#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
char input[1010];
char output[2010];
int dp[1010][1010];
int next[1010][1010];
int ans[1010];
void dfs(int a,int b,int i)
{
	if (a==0 && b==0) return ;
	switch(next[a][b])
	{
		case 2:ans[i]=a-1;dfs(a-1,b-1,i+1);break;
		case 1:dfs(a-1,b,i);break;
		case -1:dfs(a,b-1,i);break;
	}
}
main()
{
	while (scanf("%s",input)==1)
	{	
		memset(next,0,sizeof(next));
		memset(dp,0,sizeof(dp));
		int l=strlen(input);
		for (int i=1;i<=l;i++)
		for (int j=1;j<=l;j++)
		if (input[i-1]==input[l-j])
		{
			if (dp[i][j]<dp[i-1][j-1]+1) 
			{
				dp[i][j]=dp[i-1][j-1]+1;
				next[i][j]=2;
			}
		}
		else if (dp[i-1][j]>dp[i][j-1])
		{
			dp[i][j]=dp[i-1][j];
			next[i][j]=1;
		}
		else
		{
			dp[i][j]=dp[i][j-1];
			next[i][j]=-1;
		}
		dfs(l,l,0);
		int p=dp[l][l];
		printf("%d ",l-p);
		if (p%2==0)
		{
			int k=0;
			for (int j=0;j<ans[p-1];j++)
				output[k++]=input[j];	
			for (int j=l-1;j>ans[0];j--)
				output[k++]=input[j];
			output[k++]=input[ans[0]];
			for (int i=p-1;i>p/2;i--)
			{
				for (int j=ans[i]+1;j<ans[i-1];j++)
					output[k++]=input[j];
				for (int j=ans[p-i-1]-1;j>ans[p-i];j--)
					output[k++]=input[j];
				output[k++]=input[ans[i-1]];
			}			
			for (int i=0;i<k;i++)
				putchar(output[i]);
			for (int i=k-1;i>=0;i--)
				putchar(output[i]);
			putchar('\n');
		}
		else 
		{
			int k=0;
			for (int j=0;j<ans[p-1];j++)
				output[k++]=input[j];	
			for (int j=l-1;j>ans[0];j--)
				output[k++]=input[j];	
			output[k++]=input[ans[p-1]];
			for (int i=p-1;i>p/2;i--)
			{
				for (int j=ans[i]+1;j<ans[i-1];j++)
					output[k++]=input[j];
				for (int j=ans[p-i-1]-1;j>ans[p-i];j--)
					output[k++]=input[j];
				output[k++]=input[ans[i-1]];
			}			
			for (int i=0;i<k;i++)
				putchar(output[i]);
			for (int i=k-2;i>=0;i--)
				putchar(output[i]);
			putchar('\n');
		}
	}
	return 0;
}
