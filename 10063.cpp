#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int A,B,C,D;
const int maxn=1000;
const int INF=1e9;
struct Edge
{
    int from,to,dist;
};
struct HeapNode
{
    int d,u;
    bool operator<(const HeapNode & rhs) const
    {
        return d<rhs.d;
    }
};
struct Dijkstra
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];
    void init(int n)
    {
        this->n=n;
        for (int i=0; i<n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist)
    {
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for (int i=0; i<n; i++) d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode)
        {
            0,s
        });
        while (!Q.empty())
        {
            HeapNode x=Q.top();
            Q.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=0; i<G[u].size(); i++)
            {
                Edge e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                }
            }
        }
    }
};
struct three
{
    int x,y,z;
    bool operator==(const three & rhs) const
    {
        return (x==rhs.x && y==rhs.y && z==rhs.z);
    }
    bool operator<(const three & rhs) const
    {
        return x*y*z<rhs.x*rhs.y*rhs.z;
    }
};
three data[1010];
int total;
int find(int a,int b,int c)
{
    for (int i=0; i<total; i++)
        if (data[i]==(three){a,b,c})
    return i;
    return -1;
}
Dijkstra solver;
int insert(three a)
{
    data[total++]=a;
    return total-1;
}
bool found;
void dfs(int a,int b,int c)
{
    int w=0,to;
    int from=find(a,b,c);
    if (a==D || b==D || c==D)
        return ;
    if (a!=0 && b<B)//a->b
    {
        w=min(A-a,B-b);
        to=find(a-w,b+w,c);
        if (to==-1)
        {
            to=insert((three)
            {
                a-w,b+w,c
            });
            solver.AddEdge(from,to,w);
            dfs(a-w,b+w,c);
        }
        solver.AddEdge(from,to,w);
    }
    if (b!=0 && c<C)//b->c
    {
        w=min(B-b,C-c);
        dfs(a,b-w,c+w);
        to=find(a,b-w,c+w);
        if (to==-1)
        {
            to=insert((three)
            {
                a,b-w,c+w
            });
            solver.AddEdge(from,to,w);
            dfs(a,b-w,c+w);
        }
        solver.AddEdge(from,to,w);
    }
    if (a!=0 && c<C)//a->c
    {
        w=min(A-a,C-c);
        dfs(a-w,b,c+w);
        to=find(a-w,b,c+w);
        if (to==-1)
        {
            to=insert((three)
            {
                a-w,b,c+w
            });
            solver.AddEdge(from,to,w);
            dfs(a-w,b,c+w);
        }
        solver.AddEdge(from,to,w);
    }
    if (a<A && b!=0)//b->a
    {
        w=min(A-a,B-b);
        dfs(a+w,b-w,c);
        to=find(a+w,b-w,c);
        if (to==-1)
        {
            to=insert((three)
            {
                a+w,b-w,c
            });
            solver.AddEdge(from,to,w);
            dfs(a+w,b-w,c);
        }
        solver.AddEdge(from,to,w);
    }
    if (b<B && c!=0)//c->b
    {
        w=min(B-b,C-c);
        dfs(a,b+w,c-w);
        to=find(a,b+w,c-w);
        if (to==-1)
        {
            to=insert((three)
            {
                a,b+w,c-w
            });
            solver.AddEdge(from,to,w);
            dfs(a,b+w,c-w);
        }
        solver.AddEdge(from,to,w);
    }
    if (a<A && c!=0)//c->a
    {
        w=min(A-a,C-c);
        dfs(a+w,b,c-w);
        to=find(a+w,b,c-w);
        if (to==-1)
        {
            to=insert((three)
            {
                a+w,b,c-w)
            };
               solver.AddEdge(from,to,w);
               dfs(a+w,b,c+w);
           }
           solver.AddEdge(from,to,w);
    }
}
main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&A,&B,&C,&D);
        total=0;
        insert(0,0,C);
        dfs(0,0,C);
        solver.init(total);
        solver.dijkstra(0);
        int d;
        int ans=1e9;
        int mind=1e9;
        for (int i=0; i<total; i++)
        {
            int md=1e9;
            md=min(md,abs(data[i].x-D));
            md=min(md,abs(data[i].y-D));
            md=min(md,abs(data[i].z-D));
            if (md<=mind)
            {
                if (md=abs(data[i].x-D)) d=data[i].x;
                if (md=abs(data[i].y-D)) d=data[i].y;
                if (md=abs(data[i].z-D)) d=data[i].z;
                ans=min(ans,solver.d[i]);
            }
        }
        printf("%d %d\n",d,ans);
    }
    return 0;
}
