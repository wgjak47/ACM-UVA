#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int mu[12]={1,1,2,6,24,120,720,5040,40320};
struct data
{
    int a[4][4];
    int k;
};
data start;
bool vis[400000];
int fa[400000];
char fac[400000];
char s[5]={'U','D','L','R'};
int z[5][2]={{-1,0},{1,0},{0,-1},{0,1}};
int hash(const data & z)
{
    int ans=0;
    for (int i=1;i<9;i++)
    {
        int count=0;
        for (int k=0;k<i;k++)
            if (z.a[k/3][k%3]>z.a[i/3][i%3])
                ++count;
        ans+=count*mu[i];
    }
    return ans;
}
data out;
int road;
int bfs()
{
    memset(vis,0,sizeof(vis));
    memset(fa,-1,sizeof(fa));
    queue<data> Q;
    Q.push(start);
    vis[hash(start)]=true;
    data tmp;
    int ans=0;
    while (!Q.empty())
    {
        data x=Q.front();
        Q.pop();
        ans=x.k;
        out=x;
        road=hash(x);
        for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
        if (x.a[i][j]==0)
        {
            for (int k=0;k<4;k++)
            if (i+z[k][0]<3 && i+z[k][0]>=0 && j+z[k][1]<3 && j+z[k][1]>=0)
            {
                tmp=x;
                tmp.a[i][j]=tmp.a[i+z[k][0]][j+z[k][1]];
                tmp.a[i+z[k][0]][j+z[k][1]]=0;
                int z=hash(tmp);
                if (!vis[z])
                {
                    tmp.k++;
                    fa[z]=hash(x);
                    fac[z]=s[k];
                    vis[z]=true;
                    Q.push(tmp);
                }
            }
            break;
        }
    }
    return ans;
}
void print_road(int x)
{
    if (fa[x]!=-1)
    print_road(fa[x]);
    else 
        return ;
    putchar(fac[x]);
}
main()
{
    int T;
    scanf("%d",&T);
    int K=0;
    while (T--)
    {
       for (int i=0;i<3;i++)
       for (int j=0;j<3;j++)
           scanf("%d",&start.a[i][j]);
       start.k=0;
       int p=bfs();
    //   printf("%d\n",p);
       printf("Puzzle #%d\n",++K);
       for (int i=0;i<3;i++)
       {
            for (int j=0;j<3;j++)
            {
                if (j) putchar(' ');
                printf("%d",out.a[i][j]);
            }
            putchar('\n');
       }
       print_road(road);
       putchar('\n');
       putchar('\n');
    }
    return 0;
}
