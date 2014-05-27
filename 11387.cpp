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
struct edge
{
	int x,y;
	bool operator<(const edge &z) const
	{
		return y>z.y;
	}
};
vector<edge> output;
edge m[110];
bool solve(int N)
{
	pf(i,0,N)
	{
		sort(m+i,m+N);
		pf(j,1,m[i].y+1)
		{
			if (i+j>=N) return false;
			m[i+j].y-=1;
			if (m[i+j].y<0)
				return false;
			output.push_back((edge){m[i].x,m[i+j].x});
		}
		m[i].y=0;
	}
	return true;
}
main()
{
	int N;
	while (scanf("%d",&N) && N!=0)
	{
		output.clear();
		pf(i,0,N) m[i].y=3,m[i].x=i+1;
		if (solve(N))
		{
			printf("%d\n",(int)output.size());
			for (int i=0;i<output.size();i++)
				printf("%d %d\n",output[i].x,output[i].y);
		}
		else printf("Impossible\n");
	}
	return 0;
}
