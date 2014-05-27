#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 100000
vector<int> primer;
bool notp[MAX+10];
void get_primer()
{
	memset(notp,0,sizeof(notp));
	for (int i=2;i<MAX;i++)
	{ 
		if (!notp[i]) primer.push_back(i);
		for (int j=0;j<primer.size() && i*primer[j]<MAX;j++)
	 	{
			notp[i*primer[j]]=true;
			if (i%primer[j]==0) break;
		}
	}	
	notp[0]=notp[1]=1;
}
int cal(int N)
{
	int ans=0;
	while (N)
	{
		ans+=N%10;
		N/=10;
	}
	return ans;
}
bool pr(int t)
{
	if (t<100000) return !notp[t];
	int m=sqrt(t)+1;
	for (int i=0;i<primer.size() && primer[i]<=m;i++)
		if (t%primer[i]==0) return false;
	return true;
}
main()
{
	int T,N;
	get_primer();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int  t=N+1;
		while (1)
		{
			if (pr(t)) {t++;continue;}
			int temp=t;
			int ans=0;
			for (int i=0;i<primer.size() && primer[i]<=temp;i++)
				while (temp%primer[i]==0)
				{
					ans+=cal(primer[i]);
					temp/=primer[i];
				}
			if (temp!=1)
			ans+=cal(temp);
			if (ans==cal(t)) break;
			t++;
		} 
		printf("%d\n",t);
	}
	return 0;	
}
