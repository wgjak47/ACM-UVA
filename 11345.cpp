#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxm=100010;
const int maxn=50010;
int x[maxm],y[maxm],d[maxm],r[maxm];
vector<int> G[maxn],value[maxn];
int fa[maxn],p[maxn],L[maxn],anc[maxn][70],maxcost[maxn][70],cost[maxn];
int find(int x) {return x==p[x]?x:p[x]=find(p[x]);}
bool cmp(const int a,const int b)
{
    return d[a]<d[b];
}
void kruskal(int N,int M)
{
    sort(r,r+M,cmp);
    for (int i=0;i<N;i++)
    {
        p[i]=i;
        G[i].clear();
        value[i].clear();
    }
    for (int i=0;i<M;i++)
    {
        int k=r[i];
        int a=find(x[k]),b=find(y[k]);
        if (a!=b)
        {
            G[x[k]].push_back(y[k]);
            G[y[k]].push_back(x[k]);
            value[y[k]].push_back(d[k]);
            value[x[k]].push_back(d[k]);
            p[a]=b;
        }
    }
}
void dfs(int u,int father,int deep)
{
    L[u]=deep;
    for (int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if (v==father) continue;
        fa[v]=u;
        cost[v]=value[u][i];
        dfs(v,u,deep+1);
    }
}
void preprocess(int n)
{
    for (int i=0;i<n;i++)
    {
        anc[i][0]=fa[i];maxcost[i][0]=cost[i];
        for (int j=1;(1<<j)<n;j++) anc[i][j]=-1;
    }
    for (int j=1;(1<<j)<n;j++)
    for (int i=0;i<n;i++)
    if (anc[i][j-1]!=-1)
    {
       int a=anc[i][j-1];
       anc[i][j]=anc[a][j-1];
       maxcost[i][j]=max(maxcost[i][j-1],maxcost[a][j-1]);
    }
 /*   for (int i=0;i<n;i++)
    for (int j=0;(1<<j)<n;j++)
        printf("%d %d: %d %d\n",i+1,j+1,anc[i][j]+1,maxcost[i][j]);*/
}
int query(int p,int q)
{
    int tmp,log,i;
    if (L[p]<L[q]) swap(p,q);
    for (log=1;(1<<log)<=L[p];log++);log--;
    int ans=-1e9;
    for (int i=log;i>=0;i--)
        if (L[p]-(1<<i)>=L[q]) {ans=max(ans,maxcost[p][i]);p=anc[p][i];}
    if (p==q) return ans;
    for (int i=log;i>=0;i--)
    {
        if (anc[p][i]!=-1 && anc[p][i]!=anc[q][i])
        {
     //       printf("%d %d %d\n",i,anc[p][i]+1,anc[q][i]+1);
            ans=max(ans,maxcost[p][i]);p=anc[p][i];
            ans=max(ans,maxcost[q][i]);q=anc[q][i];
        }
    }
    ans=max(ans,cost[p]);
    ans=max(ans,cost[q]);
    return ans;
}
main()
{
    int N,M,Q;
    int t=0;
    while (scanf("%d%d",&N,&M)==2)
    {
        if (t++) putchar('\n');
        for (int i=0;i<M;i++)
        {
           scanf("%d%d%d",&x[i],&y[i],&d[i]);
           x[i]--,y[i]--;
           r[i]=i;
        }
        kruskal(N,M);
        fa[0]=-1;
        dfs(0,-1,0);
        preprocess(N);
        scanf("%d",&Q);
        for (int i=0;i<Q;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            s--;t--;
            printf("%d\n",query(s,t));
        }
    }
    return 0;
}
