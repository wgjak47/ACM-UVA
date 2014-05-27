#include<cstdio>
#include<cstring>
long long ten[30];
int wei[30];
long long start[30];
void seed(long long a,int p)
{
    char s[300];
    sprintf(s,"%lld",a);
    int l=strlen(s);
    printf("%s",s);
    for (int i=l-1-p;i>=0;i--)
        putchar(s[i]);
    putchar('\n');
}
main()
{
    int n;
    int t=1;
    for (int i=1;i<20;i+=2)
    {
        ten[i]=ten[i-1]+9*t;
        start[i]=t;
        wei[i]=0;
        ten[i+1]=ten[i]+9*t;
        wei[i+1]=1;
        start[i+1]=t;
        t*=10;
    }
    while (scanf("%d",&n)==1)
    {
        if (n==0) break;
        int i;
        for (i=0;i<20;i++)
            if (ten[i]>=n) break;
        long long st=start[i]+(n-ten[i-1]-1);
        if (wei[i+1])
            seed(st,1);
        else seed(st,0);
    }
    return 0;
}
