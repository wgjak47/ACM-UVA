#include<cstdio>
#include<cstring>
#include<vector>
#define pb push_back
using namespace std;
bool np[11000];
vector<int> prime;
void getprime(int n)
{
   for (int i=2;i<n;i++)
   {
       if (!np[i]) prime.pb(i);
       for (int j=0;j<prime.size() && i*prime[j]<n;j++)
       {
           np[i*prime[j]]=1;
           if (i%prime[j]==0) break;
       }
   } 
}
int LSHn[10000];
int LSHm[10000];
main()
{
    int T;
    int kcase=1;
    getprime(10000);
    scanf("%d",&T);
    while (T--)
    {
        memset(LSHn,0,sizeof(LSHn));
        memset(LSHm,0,sizeof(LSHm));
        int m,n;
        scanf("%d%d",&m,&n);
        for (int i=0;i<prime.size() && prime[i]<=n;i++)
        {
            int z=n;
            while (z)
            {
                LSHn[i]+=z/prime[i];
                z/=prime[i];
            }
        }
        for (int i=0;i<prime.size() && prime[i]<=m;i++)
        {
            int z=0;
            while (m%prime[i]==0) m/=prime[i],z++;
            LSHm[i]=z;
        }
        int ans=1e9;
        for (int i=0;i<prime.size();i++)
        {
            if (LSHn[i]==0 && LSHm[i]==0) continue;
            if (LSHn[i]==0 && LSHm[i]!=0)
            {
                ans=-1;
                break;
            }
            if (LSHn[i]!=0 && LSHm[i]==0) continue;
            ans=min(ans,LSHn[i]/LSHm[i]);
        }
        printf("Case %d:\n",kcase++);
        if (ans!=-1)
        printf("%d\n",ans);
        else printf("Impossible to divide\n");
    }
    return 0;
}
