#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
int op[1100],value[1100];
bool check_queue(int N)
{
    queue<int> Q;
    for (int i=0;i<N;i++)
    {
        if (op[i]==1) Q.push(value[i]);
        else 
        {
            if (Q.empty()) return false;
            int x=Q.front();
            if (x!=value[i]) return false;
            Q.pop();
        }
    }
    return true;
}
bool check_stack(int N)
{
    stack<int> Q;
    for (int i=0;i<N;i++)
    {
        if (op[i]==1) Q.push(value[i]);
        else 
        {
            if (Q.empty()) return false;
            int x=Q.top();
            if (x!=value[i]) return false;
            Q.pop();
        }
    }
    return true;
}
bool check_priority(int N)
{
    priority_queue<int> Q;
    for (int i=0;i<N;i++)
    {
        if (op[i]==1) Q.push(value[i]);
        else 
        {
            if (Q.empty()) return false;
            int x=Q.top();
            if (x!=value[i]) return false;
            Q.pop();
        }
    }
    return true;
}
main()
{
    int N;
    while (scanf("%d",&N)==1)
    {
        for (int i=0;i<N;i++)
            scanf("%d%d",&op[i],&value[i]);
        bool QUEUE=check_queue(N);
        bool STACK=check_stack(N);
        bool PRIORITY_QUEUE=check_priority(N);
        int sum=QUEUE+STACK+PRIORITY_QUEUE;
        if (sum==1)
        {
            if (QUEUE) printf("queue\n");
            else if (STACK) printf("stack\n");
            else printf("priority queue\n");
        }
        else if (sum==0)
            printf("impossible\n");
        else printf("not sure\n");
    }
    return 0;
}
