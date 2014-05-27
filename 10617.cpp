#include<cstdio>
#include<cstring>
long long dps[100][100];
long long dp(char *s,int i,int j)
{
	if (i==j) return dps[i][j]=1;
	else if (i>j) return 0;
	if (dps[i][j]!=-1) return dps[i][j];
	if (s[i]!=s[j])
	{
		dps[i][j]=dp(s,i+1,j)+dp(s,i,j-1)-dp(s,i+1,j-1);
		return dps[i][j];
	}
	else 
	{
		dps[i][j]=dp(s,i+1,j)+dp(s,i,j-1)+1;	
		return dps[i][j];
	}
}
main()
{
	int T;
	char st[70];
	scanf("%d",&T);
	getchar();
	while (T--)
	{
		gets(st);	
		int l=strlen(st);
		memset(dps,-1,sizeof(dps));
		printf("%lld\n",dp(st,0,l-1));
	}	
	return 0;
}
