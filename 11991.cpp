#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
map< int,vector<int> > Q;
main()
{
    int N,M;
    while (scanf("%d%d",&N,&M)==2)
    {
        Q.clear();
        for (int i=0;i<N;i++)
        {
            int u;
            scanf("%d",&u);
            if (!Q.count(u)) Q[u]=vector<int>();
            Q[u].push_back(i+1);
        } 
        for (int i=0;i<M;i++)
        {
            int u,k;
            scanf("%d%d",&k,&u);
            if (!Q.count(u) || Q[u].size()<k) printf("0\n");
            else printf("%d\n",Q[u][k-1]);
        }
    }
    return 0;
}
