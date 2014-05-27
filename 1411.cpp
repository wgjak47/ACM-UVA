#include<cstdio>
#include<cstring>
#include<cmath>
#define M 110
int bx[110],by[110];
int wx[110],wy[110];
int N,nx,ny;
int link[M];
double lx[M],ly[M],slack[M];    //lx,ly为顶标，nx,ny分别为x点集y点集的个数
int visx[M],visy[M];
double w[M][M];
double inf=1e9*2;
int DFS(int x)
{
    visx[x] = 1;
    for (int y = 1;y <= ny;y ++)
    {
        if (visy[y])
            continue;
        double t = lx[x] + ly[y] - w[x][y];
        if (t == 0)       //
        {
            visy[y] = 1;
            if (link[y] == -1||DFS(link[y]))
            {
                link[y] = x;
                return 1;
            }
        }
        else if (slack[y] > t)  //不在相等子图中slack 取最小的
            slack[y] = t;
    }
    return 0;
}
double KM()
{
    int i,j;
    memset (link,-1,sizeof(link));
    memset (ly,0,sizeof(ly));
    for (i = 1;i <= nx;i ++)            //lx初始化为与它关联边中最大的
        for (j = 1,lx[i] = -inf;j <= ny;j ++)
            if (w[i][j] > lx[i])
                lx[i] = w[i][j];

    for (int x = 1;x <= nx;x ++)
    {
        for (i = 1;i <= ny;i ++)
            slack[i] = inf;
        while (1)
        {
            memset (visx,0,sizeof(visx));
            memset (visy,0,sizeof(visy));
            if (DFS(x))     //若成功（找到了增广轨），则该点增广完成，进入下一个点的增广
                break;  //若失败（没有找到增广轨），则需要改变一些点的标号，使得图中可行边的数量增加。
                        //方法为：将所有在增广轨中（就是在增广过程中遍历到）的X方点的标号全部减去一个常数d，
                        //所有在增广轨中的Y方点的标号全部加上一个常数d
            double d = inf;
            for (i = 1;i <= ny;i ++)
                if (!visy[i]&&d > slack[i])
                    d = slack[i];
            for (i = 1;i <= nx;i ++)
                if (visx[i])
                    lx[i] -= d;
            for (i = 1;i <= ny;i ++)  //修改顶标后，要把所有不在交错树中的Y顶点的slack值都减去d
                if (visy[i])
                    ly[i] += d;
        }
    }
    double res = 0;
    for (i = 1;i <= ny;i ++)
        if (link[i] > -1)
            res += w[link[i]][i];
    return res;
}
double cal(double a,double b)
{
    return sqrt(a*a+b*b);
}
main()
{
    int t=0;
    while (scanf("%d",&N)==1)
    {
        ny=nx=N;
        if (t++) putchar('\n');
        for (int i=1;i<=N;i++)
            scanf("%d%d",&wx[i],&wy[i]);
        for (int i=1;i<=N;i++)
            scanf("%d%d",&bx[i],&by[i]);
        for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            w[i][j]=-cal(wx[i]-bx[j],wy[i]-by[j]);
        KM();
        for (int i=1;i<=N;i++)
            printf("%d\n",link[i]+1);
    }
    return 0;
}
