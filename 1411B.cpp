#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int bx[110],by[110],wx[110],wy[110];
double w[110][110],lx[110],ly[110];
int left[110];
bool S[110],T[110];
int n,nx,ny;
bool eq(double x,double y) {return fabs(x-y)<1e-6;}
/*bool match( int i )  
{  
    S[i] = true;  
    for ( int j = 1; j <= n; ++j ) if ( eq( lx[i] + ly[j], w[i][j] ) && !T[j] ) {  
        T[j] = true;  
        if ( !left[j] || match(left[j]) ) {  
            left[j] = i;  
            //r[i] = j;  
            return true;  
        }  
    }  
    return false;  
} */ 
bool match(int i)
{
    S[i] = true;
    for ( int j = 1; j <= n; j++ ) if ( eq(lx[i] + ly[j], w[i][j] ) && !T[j]) {
        T[j]=true;
        if (!left[j] || match(left[j]))
        {
            left[j]=i;
            return true;
        }
    }
    return false;
}
void update()
{
    double a=1e9;
    for (int i=1;i<=n;i++) if (S[i])
    for (int j=1;j<=n;j++) if (!T[j])
        a=min(a,lx[i]+ly[j]-w[i][j]);
    for (int i=1;i<=n;i++)
    {
        if (S[i]) lx[i]-=a;
        if (T[i]) ly[i]+=a;
    }
}
void KM()
{
    for (int i=1;i<=n;i++)
    {
        left[i]=lx[i]=ly[i]=0;
        for (int j=1;j<=n;j++)
            lx[i]=max(lx[i],w[i][j]);
    }
    for (int i=1;i<=n;i++)
    {
        while (1)
        {
            for (int j=1;j<=n;j++) S[j]=T[j]=0;
            if (match(i)) break;
            else update();
        }
    }
}
double cal(double a,double b)
{
    return sqrt(a*a+b*b);
}
main()
{
    int t=0;
    while (scanf("%d",&n)==1)
    {
        ny=nx=n;
        if (t++) putchar('\n');
        for (int i=1;i<=n;i++)
            scanf("%d%d",&wx[i],&wy[i]);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&bx[i],&by[i]);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            w[j][i]=-cal((double)wx[i]-bx[j],(double)wy[i]-by[j]);
        KM();
        for (int i=1;i<=n;i++)
            printf("%d\n",left[i]);
    }
    return 0;
}
