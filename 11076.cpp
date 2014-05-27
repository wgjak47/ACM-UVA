#include<cstdio>
#include<cstring>
#define ULL unsigned long long
int reg[20];
ULL jc[20];
main()
{
    int N;
    jc[0]=1;
    for (int i=1;i<=12;i++) jc[i]=jc[i-1]*i;
    while (scanf("%d",&N)==1)
    {
        if (N==0) break;
        int u;
        memset(reg,0,sizeof(reg));
        for (int i=0;i<N;i++)
        {
            scanf("%d",&u);
            reg[u]++;
        }
        double fa=jc[N-1];
        for (int i=0;i<=9;i++)
            if (reg[i]) fa/=jc[reg[i]];
        fa+=1e-6;
        ULL sum=0;
        for (int i=0;i<=9;i++)
        {
            sum+=(ULL)(fa*reg[i]*i);
        }
        ULL ans=0;
        for (int i=1;i<=N;i++)
            ans+=sum,sum*=10;
        printf("%llu\n",ans);
    }
    return 0;
}
