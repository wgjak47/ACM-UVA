#include<stdio.h>
#include<string.h>
int G[110][110];
int n,ans[110],res;
void dfs(int cur,int *A)
{
    int i,j,num,color[110];
    if(cur==n)
    {
        num=0;
        for(i=0;i<n;i++)
            if(A[i])
                num++;
        if(num>res)
        {
            memcpy(ans,A,sizeof(ans));
            res=num;
        }
        return;
    }
    for(i=0;i<n;i++)
        if(A[i]<0)
        {
            memcpy(color,A,sizeof(color));
            color[i]=1;
            num=1;
            for(j=0;j<n;j++)
                if(G[i][j]&&color[j]<0)
                {
                    color[j]=0;
                    num++;
                }
            dfs(cur+num,color);
        }
}
int main()
{
    int i,j,k,t,m,a,b,A[110];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(G,0,sizeof(G));
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            a--;
            b--;
            G[a][b]=G[b][a]=1;
        }
        res=0;
        memset(A,-1,sizeof(A));
        dfs(0,A);
        printf("%d\n",res);
        k=0;
        for(i=0;i<n;i++)
            if(ans[i])
            {
                if(k++)
                    printf(" ");
                printf("%d",i+1);
            }
        printf("\n");
    }
    return 0;    
}
