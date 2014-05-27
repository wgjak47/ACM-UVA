#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=560;
struct Edge 
{
    int from,to,dist;
};
struct BellmanFord
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    int d[maxn];
    int p[maxn];
    int cnt[maxn];
    void init(int n)
    {
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist)
    {
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }
    bool negativeCycle()
    {
        queue<int> Q;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++)
        {
            d[i]=0;
            inq[0]=true;
            Q.push(i);
        }
        while (!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            inq[u]=false;
            for (int i=0;i<G[u].size();i++)
            {
                Edge & e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    if (!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to]=true;
                        if (++cnt[e.to]>n) return false;
                    }
                }
            }
        }
        return true;
    }
};
BellmanFord solver;
bool test(int m)
{
    for (int i=0;i<solver.m;i++)
        solver.edges[i].dist-=m;
    bool ret=solver.negativeCycle();
    for (int i=0;i<solver.m;i++)
        solver.edges[i].dist+=m;
    return ret;
}
main()
{
    int V,E;
    while (scanf("%d%d",&V,&E)==2)
    {
        int u,v,w;
        int max_w=0;
        solver.init(V);
        for (int i=0;i<E;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            u--,v--;
            solver.AddEdge(u,v,w);
            max_w=max(w,max_w);
        }
        if (test(max_w+1))
        {
            printf("Infinite\n");
            continue;
        }
        else if (!test(1))
        {
            printf("No Solution\n");
            continue;
        }
        int L=0,R=max_w;
        while (L<=R)
        {
            int mid=(L+R)/2;
            if (!test(mid)) R=mid-1;
            else L=mid+1;
        }
        if (!test(L)) L--;
        printf("%d\n",L);
    }
    return 0;
}
