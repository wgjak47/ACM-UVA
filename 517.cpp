#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
char f[9];
bool vis[(1<<17)+10];
bool fuck[(1<<17)+10];
int dx[18];
int newx[18];
void output(int a,int n)
{
    stack<char> stk;
    int reg=0;
    int mins=a;
    memset(fuck,0,sizeof(fuck));
    while (!fuck[a])
    {
        fuck[a]=true;
        int b=a%2;
        a>>=1;
        if (b==1)
        a=a|(1<<(n-1));
        mins=min(a,mins);
    }
    a=mins;
    while (a)
    {
        reg++;
        char tmp=a%2?'b':'a';
        stk.push(tmp);
        a/=2;
    }
    while (reg++<n) stk.push('a');
    while (!stk.empty()) 
    {
        putchar(stk.top());
        stk.pop();
    }
    putchar('\n');
}
main()
{
    int n;
    string in;
    while (cin>>n)
    {
        memset(vis,0,sizeof(vis));
        memset(fuck,0,sizeof(fuck));
        cin>>in;
        for (int i=0;i<8;i++)
        {
            int sum=0;
            char c;
            for (int j=0;j<3;j++)
            {
                cin>>c;
                sum=sum*2+c-'a';
            }
            cin>>c;
            f[sum]=c-'a';
        }
        for (int i=0;i<in.length();i++)
            if (in[i]=='a') 
                dx[i]=0;
            else
                dx[i]=1;
        int reg=0;
        vector<int> z;
        int start;
        while (1)
        {
            int sum=0;
            for (int i=0;i<n;i++)
                sum=sum*2+dx[i];
            if (vis[sum])
            {
                start=sum;
                break;
            }
            vis[sum]=1;
            z.push_back(sum);
            for (int i=0;i<n;i++)
            {
      //          putchar(dx[i]?'b':'a');
                int a=dx[(i-2+n)%n];
                int b=dx[i];
                int c=dx[(i+1)%n];
                newx[i]=f[a*4+b*2+c*1];
            }
    //        putchar('\n');
            for (int i=0;i<n;i++)
                dx[i]=newx[i];
        }
        int left;
        for (int i=0;i<z.size();i++)
        if (z[i]==start) 
        {
            left=i;
            break;
        }
        int s;
        cin>>s;
        if (s<left) output(z[s],n);
        else
        {
            s-=left;
            s%=(z.size()-left);
            output(z[s+left],n);
        }
  //      putchar('\n');
    }
	return 0;
}
