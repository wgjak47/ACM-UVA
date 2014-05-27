#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define LLD long long
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
LLD ten[100];
LLD dp[300];
main()
{
	int N;
	scanf("%d",&N);
	getchar();
	char s[300];
	ten[0]=1;
	for (int i=1;i<=12;i++) ten[i]=ten[i-1]*10;
	while (N--)
	{
		s[0]='0';
		gets(s+1);
		memset(dp,0,sizeof(dp));
		int l=strlen(s);
		pf(i,1,l)
		{
			LLD sum=0;
			pf(j,0,i)
			{
				sum+=(s[i-j]-'0')*ten[j];
				if (sum>(1LL<<31)-1) break;
				dp[i]=max(dp[i-j-1]+sum,dp[i]);
	//			printf("%lld\n",sum);
			}
		}
		printf("%lld\n",dp[l-1]);
	}
	return 0;
}
