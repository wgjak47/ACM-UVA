#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
char s[30];
long long f[25][25];
int put[30];
int change(char c)
{
	if (c>='0' && c<='9')
		return c-'0'-1;
	switch(c)
	{
		case 'A':return 9;
		case 'B':return 10;
		case 'C':return 11;
		case 'D':return 12;
		case 'E':return 13;
		case 'F':return 14;
	}
}
main()
{
	while (gets(s)!=NULL)
	{
		int l=strlen(s);
		if (l==0) continue;
		//puts(s);
		memset(f,0,sizeof(f));
		for (int i=0;i<l;i++)
			if (s[i]!='?') put[i]=change(s[i]);
			else put[i]=-1;
		if (put[0]==-1) for (int i=0;i<l;i++) f[0][i]=1;
		else f[0][put[0]]=1;
		for (int i=1;i<l;i++)
		{
			if (put[i]==-1)
			{
				for (int j=0;j<l;j++)
					for (int k=0;k<l;k++)
						if (k-1!=j && k!=j && k+1!=j)
						f[i][j]+=f[i-1][k];
			}
			else 
			{
				int j=put[i];
				for (int k=0;k<l;k++)
						if (k-1!=j && k!=j && k+1!=j)
						f[i][j]+=f[i-1][k];
			}
		}
		long long ans=0;
		for (int i=0;i<l;i++)
			ans+=f[l-1][i];
		printf("%lld\n",ans);
	}
	return 0;
}
