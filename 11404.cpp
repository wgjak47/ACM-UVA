#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010][1010];
char s1[1010];
char s2[1010];
int p1[1010][30];
int p2[1010][30];
int out_len=0;
void reserve(char *s1,char *s2)
{
    int l=0,r=strlen(s1);
    s2[r--]='\0';
    while (l<=r)
    {
        s2[l]=s1[r];
        s2[r]=s1[l];
        r--;l++;
    }
}
void get_pos(char *s,int p[][30])
{
    memset(p,0,sizeof(p));
    int l=strlen(s);
    for (int i=1;i<=l;i++)
    for (int j=0;j<26;j++)
        if (s[i-1]=='a'+j)
            p[i][j]=i;
        else p[i][j]=p[i-1][j];
}
char out[1010];
void dfs(int a,int b,int c,int end)
{
    if (c==end) 
        return ;
    if (a<1 || b<1) return ;
    for (int i=0;i<26;i++)
    {
        int x=p1[a][i],y=p2[b][i];
        if (dp[x][y]==c)
        {
            out[out_len++]=i+'a';
            dfs(x-1,y-1,c-1,end);
            return ;
        }
    }
}
main()
{
    while (scanf("%s",s1)==1)
    {
        out_len=0;
        int l=strlen(s1);
        reserve(s1,s2);
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=l;i++)
        for (int j=1;j<=l;j++)
            if (s1[i-1]==s2[j-1])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        get_pos(s1,p1);get_pos(s2,p2);
        dfs(l,l,dp[l][l],dp[l][l]/2);
        if (dp[l][l]%2==0)
        {
            for (int i=0;i<out_len;i++)
                putchar(out[i]);
            for (int i=out_len-1;i>=0;i--)
                putchar(out[i]);
        }
        else 
        {
            for (int i=0;i<out_len;i++)
                putchar(out[i]);
            for (int i=out_len-2;i>=0;i--)
                putchar(out[i]);
        }
        putchar('\n');
    }
    return 0;
}
