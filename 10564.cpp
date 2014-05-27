#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long dp[60][60][510];
char  ans_s[40];
int a[60][60];
bool dfs(int k,int l,int S,int i,int n)
{
    if (k==1) {ans_s[i]='\0';return true;}
    if (k>n)
    {
        if (dp[k][l][S]==dp[k-1][l-1][S-a[k][l]])
        {ans_s[i]='L';dfs(k-1,l-1,S-a[k][l],i+1,n);}
        else if (dp[k][l][S]==dp[k-1][l][S-a[k][l]])
        {ans_s[i]='R';dfs(k-1,l,S-a[k][l],i+1,n);}
        else {ans_s[i]='L',dfs(k-1,l-1,S-a[k][l],i+1,n);}
    }
    else
    {
        if (dp[k][l][S]==dp[k-1][l][S-a[k][l]])
        {ans_s[i]='L';dfs(k-1,l,S-a[k][l],i+1,n);}
        else if (dp[k][l][S]==dp[k-1][l+1][S-a[k][l]])
        {ans_s[i]='R';dfs(k-1,l+1,S-a[k][l],i+1,n);}
        else {ans_s[i]='L',dfs(k-1,l,S-a[k][l],i+1,n);}
    }
}
void deal(int *c,int *b,int k)
{
    for (int i=1;i<=k;i++)
        swap(c[i],b[i]);
}
main()
{
    int n,S;
    while (scanf("%d%d",&n,&S)==2 && n+S)
    {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
            scanf("%d",&a[i][j]);
        for (int i=n+1;i<2*n;i++)
        for (int j=1;j<=i-n+1;j++)
            scanf("%d",&a[i][j]);
        int l=1,r=2*n-1,k=n;
        while (l<r) {deal(a[l],a[r],k); l++,r--,k--;}
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i+1;j++)
        {
            if (i==1) dp[i][j][a[i][j]]=1;
            else  
            for (int k=0;k<=S;k++)
            if (k-a[i][j]>=0)
            {
                dp[i][j][k]+=dp[i-1][j][k-a[i][j]];
                dp[i][j][k]+=dp[i-1][j+1][k-a[i][j]];
            }
        }
        for (int i=n+1;i<2*n;i++)
        for (int j=1;j<=i-n+1;j++)
        {
            for (int k=0;k<=S;k++)
            if (k-a[i][j]>=0)
            {
                dp[i][j][k]+=dp[i-1][j-1][k-a[i][j]];
                dp[i][j][k]+=dp[i-1][j][k-a[i][j]];
            }
        }
        long long ans=0;
        for (int i=1;i<=n;i++)
            ans+=dp[2*n-1][i][S];
        printf("%lld\n",ans);
        if (ans)
        {
            int i;
            for (i=1;i<=n;i++)
                if (dp[2*n-1][i][S]!=0 && dfs(2*n-1,i,S,0,n)) break;
            printf("%d ",i-1);
            puts(ans_s);
        }
        else puts("");
    }
    return 0;
}
