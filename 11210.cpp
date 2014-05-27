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
const char* mahjong[]={"1T","2T","3T","4T","5T","6T","7T","8T","9T","1S","2S","3S","4S","5S","6S","7S","8S","9S","1W","2W","3W","4W","5W","6W","7W","8W","9W","DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
int convert(char *s)
{
	for (int i=0;i<34;i++) if (strcmp(mahjong[i],s)==0) return i;
	return -1;
}
int c[34];
bool search(int dep)
{
	for (int i=0;i<34;i++)
		if (c[i]>=3)
		{
			if (dep==3) return true;
			c[i]-=3;
			if (search(dep+1)) return true;
			c[i]+=3;
		}
	for (int i=0;i<=24;i++)
		if (i%9<=6 && c[i]>=1 && c[i+1]>=1 && c[i+2]>=1)
		{
			if (dep==3) return true;
			c[i]--;c[i+1]--;c[i+2]--;
			if (search(dep+1)) return true;
			c[i]++,c[i+1]++,c[i+2]++;
		}
	return false;
}
bool check()
{
	for (int i=0;i<34;i++)
		if (c[i]>=2)
		{
			c[i]-=2;
			if (search(0)) return true;
			c[i]+=2;
		}
	return false;
}
main()
{
	int caseno=0,i,j;
	bool ok;
	char s[100];
	int mj[15];
	while (scanf("%s",s)==1)
	{
		if (s[0]=='0') break;
		printf("Case %d:",++caseno);
		mj[0]=convert(s);
		pf(i,1,13)
		{
			scanf("%s",s);
			mj[i]=convert(s);
	 	}
		ok=false;
		pf(i,0,34)
		{
			memset(c,0,sizeof(c));
			pf(j,0,13)
				c[mj[j]]++;
			if (c[i]>=4) continue;
			c[i]++;
			if (check())
			{
				ok=true;
				printf(" %s",mahjong[i]);
	 		}
			c[i]--;
	 	}
		if (!ok) printf(" Not ready");
		printf("\n");
	} 
	return 0;
}
