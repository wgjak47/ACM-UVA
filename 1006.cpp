#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
const int maxn=60;
const int maxk=12;
int mem[maxn],s[maxn][maxk],t[maxn][maxk];
int k[maxn];
int W[maxn][maxn][maxk];
int n,m;
int Left[maxn][maxk];
int Lx[maxn],Ly[maxn][maxk];
bool S[maxn],T[maxn][maxk];
bool match(int i)
{
    S[i]=true;
    for (int j=0;j<n;j++) 
    for (int z=0;z<m;z++)
    if (Lx[i]+Ly[j][z]==W[i][j][z] && !T[j][z])
    {
        T[j][z]=true;
        if (!Left[j][z] || match(Left[j][z]))
        {
            Left[j][z]=i;
            return true;
        }
    }
    return false;
}
void update()
{
    int a=1<<30;
    pf(i,0,n) if(S[i])
    pf(j,0,n) 
    pf(l,0,k[j])if (T[j][l])
    a=min(a,Lx[i]+Ly[j][l]-W[i][j][l]);
    for (int i=0;i<n;i++)
    if (S[i]) Lx[i]-=a;
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
        Ly[i][j]+=a;
}
void KM()
{
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
        Left[i][j]=Lx[i]=Ly[i][j]=0;
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    for (int l=0;l<m;l++)
        Lx[i]=max(Lx[i],W[i][j][l]);
    for (int i=0;i<n;i++)
    {
        while (true)
        {
            for (int j=0;j<n;j++) 
            {
                S[j]=0;
                for (int l=0;l<m;l++)
                T[j][l]=0;
            }
            if (match(i)) break;
            else update();
        }
    }
}
int find(int value,int p)
{
    int v=k[p]-1;
    for (int i=0;i<k[p];i++)
    if (value<s[p][i]){
        v=i-1;
        break;
    }
    if (v==-1) return -1e7;
    else return t[p][v];  
}
void output(int n,int m)
{
    double sum=0;
    for (int i=0;i<n;i++) 
    for (int j=0;j<m;j++)
        sum-=W[Left[i][j]][i][j];
    printf("Average turnaround time = %.2f\n",sum);   
    int region[maxn],stime[maxn],end[maxn];
    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    {
        int problem=Left[i][j];
        region[problem]=j;
        stime[problem]=-W[Left[i+1][j]][i+1][j];
        end[problem]=-W[Left[i][j]][i][j];
    }
    for (int i=0;i<n;i++)
        printf("problem %d runs in region %d from %d to %d\n",i+1,region[i],stime[i],end[i]);
}
main()
{
    int ce=1;
    while (scanf("%d%d",&m,&n)==2 && n+m)
    {
        memset(W,0,sizeof(W));
        pf(i,0,m)
        scanf("%d",&mem[i]); 
        pf(i,0,n)
        {
            scanf("%d",&k[i]);
            pf(j,0,k[i])
                scanf("%d%d",&s[i][j],&t[i][j]);
        }
        for (int X=0;X<n;X++)
        for (int j=0;j<m;j++)
        for (int p=0;p<n;p++)
        {
            int value=find(mem[j],p);
            W[X][j][p]=-p*value;
        }
        KM();
        printf("Case %d\n",ce++);
        output(n,m);
    }
	return 0;
}
