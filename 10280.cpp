#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> S;
bool vis[4510];
int minv[110],maxv[110];
bool dp[450010];
main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int V,M;
        scanf("%d%d",&V,&M);
        V*=1000;
        int max_V=0;
        for (int i=0;i<M;i++)
        {
            scanf("%d%d",&minv[i],&maxv[i]);
            max_V=max(max_V,minv[i]*minv[i]/(maxv[i]-minv[i]));
        }
        int ans;
        if (V>=max_V)
            ans=0;
        else 
        {
            memset(dp,0,sizeof(dp));
            memset(vis,0,sizeof(vis));
            S.clear();
            dp[0]=1;
            for (int i=0;i<M;i++)
            for (int j=minv[i];j<=maxv[i];j++)
                if (!vis[j])
                {
                    S.push_back(j);
                    vis[j]=true;
                }
            for (int i=0;i<S.size();i++)
            for (int j=S[i];j<=V;j++)
                if (dp[j-S[i]]) dp[j]=true;
            for (int i=V;i>=0;i--)
            if (dp[i])
            {
                ans=V-i;
                break;
            }
        }
        printf("%d\n",ans);
        if (T) putchar('\n');
    }
    return 0;
}
