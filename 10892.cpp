/*************************************************************************
	> File Name: 10892.cpp
	> Author: WGJAK47
	> Mail: ak47m61@gmail.com 
	> Created Time: 2013年10月20日 星期日 08时51分30秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
long long top[1000000];
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
main()
{
    long long N;
    while (cin>>N && N)
    {
       int m=(int)sqrt(N+0.5);
       int total=0;
       for (int i=1;i<=m;i++)
       if (N%i==0) 
       {
           top[total++]=i;
           top[total++]=N/i;
       }
       int ans=0;
       if (top[total-1]==top[total-2]) total--;
       for (int i=0;i<total;i++)
       for (int j=i;j<total;j++)
        {
            if (lcm(top[i],top[j])==N) ans++;
        } 
        cout<<N<<" "<<ans<<endl;
    }
    return 0;
}
