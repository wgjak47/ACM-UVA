#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int A[760][760];
struct  ITEM
{
    int s,b;
    ITEM(int s,int b) :s(s),b(b){}
    bool operator<(const ITEM &rhs) const
    {
        return s>rhs.s;
    }
};
void Merge(int *A,int *B,int *C,int n)
{
    priority_queue<ITEM> Q;
    for (int i=0;i<n;i++) Q.push(ITEM(A[i]+B[0],0));
    for (int i=0;i<n;i++)
    {
        ITEM x=Q.top();
        Q.pop();
        C[i]=x.s;
        int b=x.b;
        if (b+1<n) Q.push(ITEM(x.s-B[b]+B[b+1],b+1));
    }
}
main()
{
    int k;
    while (scanf("%d",&k)==1)
    {
        memset(A[0],0,sizeof(A[0]));
        for (int i=0;i<k;i++)
        {
            for (int j=0;j<k;j++)
            scanf("%d",&A[i][j]);
            sort(A[i],A[i]+k);
        }
        for (int i=1;i<k;i++)
            Merge(A[0],A[i],A[0],k);
        for (int i=0;i<k;i++)
        {
            if (i) putchar(' ');
            printf("%d",A[0][i]);
        }
        putchar('\n');
    }
    return 0;
}
