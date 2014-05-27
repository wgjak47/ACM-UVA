#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct ITEM
{
    int period,time,Q_num;
    bool  operator<(const ITEM &a) const
    {
        return (time>a.time || (time==a.time && Q_num>a.Q_num));
    }
};
ITEM data;
main()
{
    char s[20];
    priority_queue<ITEM> Q;
    while (scanf("%s",s) && s[0]!='#')
    {
        scanf("%d%d",&data.Q_num,&data.period);
        getchar();
        data.time=data.period;
        Q.push(data);
    }
    int K;
    scanf("%d",&K);
    while (K--)
    {
        ITEM b=Q.top();
        Q.pop();
        printf("%d\n",b.Q_num);
        b.time+=b.period;
        Q.push(b);
    }
    return 0;
}
