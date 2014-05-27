//容斥原理：AUBUC=A+B+C-AB-AC+ABC
//或者欧拉函数：n*(1-1/p1)*(1-1/p2)*(1-1/p3);
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)<(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
const bool add=true;
const bool _minus=false;
bool notp[50001];
vector<int> prime;
void get_primer()
{
	pf (i,2,50000)
	{
		if (!notp[i]) prime.push_back(i);
		for (int j=0;j<prime.size() && prime[j]*i<=50000;j++)
		{
			notp[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
int dfs(vector<int> &f,int N,int now,int t,bool state)
{
	int sum=0;
	int l=f.size();
	if (state==add)
	pf(i,now,l)
		sum+=N/(f[i]*t)+dfs(f,N,i+1,f[i]*t,_minus);
	else 
	pf(i,now,l)
		sum+=-N/(f[i]*t)+dfs(f,N,i+1,f[i]*t,add);
	return sum;
}
int cal(int N)
{
	int sum=0;
	vector<int> factor;
	int k=0;
	int tN=N;
	while (N!=1) 
	{
		if (N%prime[k]==0) 
			N/=prime[k],factor.push_back(prime[k]);
		k++;
		if (prime[k]>N) break;
	}
	return (tN-dfs(factor,tN,0,1,add))*2;
}
main()
{
	int N;
	int dp[50010];
	get_primer();
	dp[1]=1;
	pf (i,2,50001)
		dp[i]=dp[i-1]+cal(i);
	while (scanf("%d",&N)==1 && N!=0)
		printf("%d\n",dp[N]);
	return 0;
}
