#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=1e9;
const int maxn=110;
struct MDST 
{
    int n;
    int w[maxn][maxn];
    int vis[maxn];
    int ans;
    int removed[maxn];
    int cid[maxn];
    int pre[maxn];
    int iw[maxn];
    int max_cid;
    void init(int n)
    {
        this->n=n;
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            w[i][j]=INF;
    }
    void AddEdge(int u,int v,int cost)
    {
        w[u][v]=min(w[u][v],cost);
    }
    int dfs(int s)
    {
        vis[s]=1;
        int ans=1;
        for (int i=0;i<n;i++)
            if (!vis[i] && w[s][i]<INF) ans+=dfs(i);
        return ans;
    }
    bool cycle(int u)
    {
        max_cid++;
        int v=u;
        while (cid[v]!=max_cid)
        {
            cid[v]=max_cid;
            v=pre[v];
        }
        return v==u;
    }
    void update(int u)
    {
        iw[u]=INF;
        for (int i=0;i<n;i++)
            if (!removed[i] && w[i][u]<iw[u])
            {
                iw[u]=w[i][u];
                pre[u]=i;
            }
    }
    bool solve(int s)
    {
        memset(vis,0,sizeof(vis));
        if (dfs(s)!=n) return false;
        memset(removed,0,sizeof(removed));
        memset(cid,0,sizeof(cid));
        for (int u=0;u<n;u++) update(u);
        pre[s]=s;iw[s]=0;
        ans=max_cid=0;
        for (;;)
        {
            bool have_cycle=false;
            for (int u=0;u<n;u++)
                if (u!=s && !removed[u] && cycle(u))
                {
                    have_cycle=true;
                    int v=u;
                    do 
                    {
                        if (v!=u) removed[v]=1;
                        ans+=iw[v];
                        for (int i=0;i<n;i++)
                        if (cid[i]!=cid[u] && !removed[i])
                        {
                            if (w[i][v]<INF) w[i][u]=min(w[i][u],w[i][v]-iw[v]);
                            w[u][i]=min(w[u][i],w[v][i]);
                            if (pre[i]==v) pre[i]=u;
                        }
                        v=pre[v];
                    } while (v!=u);
                    update(u);
                    break;
                }
            if (!have_cycle) break;
        }
        for (int i=0;i<n;i++)
            if (!removed[i]) ans+=iw[i];
        return true;
    }
};
int N,M,C;
MDST solver;
/*struct Edge
{
    int u,v,b,c;
    bool operator<(const Edge &rhs) const
    {
        return b>rhs.b;
    }
};*/
struct Edge {
  int u, v, b, c;
  bool operator < (const Edge& rhs) const {
    return b > rhs.b;
  }
};
const int maxm = 10000 + 10;
Edge edges[maxm];
bool check(int m)
{
    solver.init(N);
    for (int i=0;i<m;i++)
        solver.AddEdge(edges[i].u,edges[i].v,edges[i].c);
    if (!solver.solve(0)) return false;
    return solver.ans<=C;
}
main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for (int i=0;i<M;i++)
            scanf("%d%d%d%d",&edges[i].u,&edges[i].v,&edges[i].b,&edges[i].c);
        sort(edges,edges+M);
        int L=1,R=M,ans=-1;
        while (L<=R)
        {
            int m=L+(R-L)/2;
            if (check(m)) {R=m-1;ans=edges[m-1].b;}
            else L=m+1;
        }
        if (ans>=0)
            printf("%d kbps\n",ans);
        else printf("streaming not possible.\n");
    }
    return 0;
}
