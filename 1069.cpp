#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
int K=0;
LL pow(LL a,LL e,LL mod)
{
	if (e==0) return 1;
	if (e==1) return a;
	LL tmp=pow(a,e/2,mod);
	if (e%2) return tmp*tmp%mod*a%mod;
	else return tmp*tmp%mod;
}
int C[110],E[110];
LL test(LL a,int n,LL mod)
{
	LL sum=0;
	for (int i=0;i<n;i++)
	{
		sum=(sum+C[i]*pow(a,E[i],mod)%mod+mod)%mod;
		sum%=mod;
	}
	return sum;
}
bool inputz(int &z,int &m)
{
	char c;
	int cc,ee;
	int stat;
	z=0,K=0;
	memset(C,0,sizeof(C));
	memset(E,0,sizeof(E));
	while (c=getchar())
	{
		if (c=='\n') return true;
		if (c=='(')
		{
			c=getchar();
			if (c=='-') 
			{
				ungetc(c,stdin);
				continue;
			}
			ungetc(c,stdin);
			stat=scanf("%d",&cc);
			if (stat==1) C[z++]=cc;
			else C[z++]=1;
		}
		else
		if (c>='0' && c<='9' || c=='-' || c=='+')
		{
			ungetc(c,stdin);
			stat=scanf("%d",&cc);
			if (stat==1) C[z++]=cc;
			else if (c=='-') C[z++]=-1;
			else C[z++]=1;
		}
		else if (c=='n')
		{
			c=getchar();
			if (c=='-' || c=='+') 
			{
				E[z-1]=1;
				continue;
			}
			if (c!='^') ungetc(c,stdin);
			stat=scanf("%d",&ee);
			if (stat==1)
			E[z-1]=ee;
			else E[z-1]=1;
			K=max(E[z-1],K);
		}
		else if (c=='/')
			scanf("%d",&m);
		else if (c=='.') return false;
	}
}
int main()
{
	string input;
	int k=0;
	int mod=0;
	int z=0;
	while (inputz(z,mod))
	{
		int c=0,e=1;
		bool szero=false;
		bool isc=true;
		bool ans=true;
		for (int i=1;i<=K+1;i++)
			if (test(i,z,mod)!=0)
				ans=false;
	/*	cout<<K<<endl;
		for (int i=0;i<z;i++)
		cout<<C[i]<<' '<<E[i]<<endl;
		cout<<mod<<endl;*/
		printf("Case %d: %s\n",++k,ans?"Always an integer":"Not always an integer");
	}
	return 0;
}

