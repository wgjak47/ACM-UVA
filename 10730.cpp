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
int z[10010];
bool temp[10010];
bool init(int &N)
{
	scanf("%d",&N);
	if (N==0) return false;
	getchar();
	pf(i,0,N) scanf("%d",&z[i]);
	return true;
}
bool search(int N)
{
	mt(temp,0);
	pf(i,0,N)
	{
		temp[z[i]]=true;
		pf(j,0,i)
		{
			int d=z[i]-z[j];
			if (z[i]+d>=0 && z[i]+d<N && temp[z[i]+d]==false)	
				return true;
		}
	}
	return false;
}
main()
{
	int N;
	while(init(N)==1)
	{
		bool no=search(N);
		if (!no)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
