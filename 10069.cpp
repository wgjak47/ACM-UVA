#include<cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) a>b?a:b
struct big
{
    int l;
    int num[20];
};
bool c(bool x)
{
    if (x==true) return false;
    return true;
}
big dp[2][10010];
void bigprint(big &a)
{
        printf("%d",a.num[a.l-1]);
    for (int i=a.l-2;i>=0;i--)
        printf("%.8d",a.num[i]);
    printf("\n");
}
big bigadd(big &a1,big &a2)
{
    big result;
    memset(&result,0,sizeof(result));
    int max=max(a1.l,a2.l);
    for (int i=0;i<max;i++)
    {
        result.num[i]+=a1.num[i]+a2.num[i];
        if (result.num[i]>=100000000)
        { 
            result.num[i+1]+=1;
            result.num[i]-=100000000;
        }
    }
    if (result.num[max]!=0) result.l=max+1;
    else result.l=max;
    return result;
}
main()
{
    int T;
    big one;
    one.num[0]=1;
    one.l=1;
    char s1[10010],s2[110];
    scanf("%d",&T);
    getchar();
    int l1,l2;
    while (T--)
    {
        memset(&dp,0,sizeof(dp));
        gets(s1);
        gets(s2);
        l1=strlen(s1);
        l2=strlen(s2);
        bool x=false;
        if (s1[0]==s2[0])
        {
            dp[0][0].num[0]=1;
            dp[0][0].l=1;
        }
        for (int i=0;i<l2;i++)
        {
            if (i!=0)
            {
                dp[x][0].num[0]=0;
                dp[x][0].l=1;
            }
            for (int j=1;j<l1;j++)
            if (s1[j]==s2[i])
            {
                if (i>0)
                dp[x][j]=bigadd(dp[x][j-1],dp[c(x)][j-1]);
                else
                    dp[x][j]=bigadd(dp[x][j-1],one);
            }
            else
            {
                dp[x][j]=dp[x][j-1];
            }
            x=c(x);
        }
        bigprint(dp[c(x)][l1-1]);
    }
    return 0;
}
