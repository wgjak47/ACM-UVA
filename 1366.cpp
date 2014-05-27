#include<cstdio>
#include<cstring>
#define Nor 0
#define Wes 1
int dp[2][510][510];
int mine[2][510][510];
inline int max(int a,int b)
{
    if (a>b) return a;
    return b;
}
main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2 && m+n)
    {
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&mine[Wes][i][j]),mine[Wes][i][j]+=mine[Wes][i][j-1];
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&mine[Nor][i][j]),mine[Nor][i][j]+=mine[Nor][i-1][j];
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            dp[Wes][i][j]=mine[Wes][i][j]+max(dp[Nor][i-1][j],dp[Wes][i-1][j]);
            dp[Nor][i][j]=mine[Nor][i][j]+max(dp[Nor][i][j-1],dp[Wes][i][j-1]);
        }
        int ans=max(dp[Wes][n][m],dp[Nor][n][m]);
        printf("%d\n",ans);
    }
    return 0;
}
