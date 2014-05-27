#include<cstdio>
#include<cstring>
#include<vector>
#define MAX 10000000
using namespace std;
bool notpr[MAX];
vector<int> primer;
void getprime()
{
	memset(notpr,0,sizeof(notpr));
	for (int i=2;i<MAX;i++)
	{
		if (!notpr[i]) primer.push_back(i);
		for (int j=0;j<primer.size() && primer[j]*i<MAX;j++)
		{
			notpr[primer[j]*i]=1;
			if (i%primer[j]==0)break;
		}
	}
	notpr[0]=0;
}
main()
{
	int N;
	getprime();
	while (scanf("%d",&N)==1)
	{
		if (N<8) printf("Impossible.\n");
		else if (N%2==0)
		{
			N-=4;
			int i=0;
			for (i=0;i<primer.size();i++)
				if (!notpr[N-primer[i]]) break;
			printf("%d %d 2 2\n",primer[i],N-primer[i]);
		}	
		else 
		{
			N-=5;
			int i=0;
			for (i=0;i<primer.size();i++)
				if (!notpr[N-primer[i]]) break;
			printf("%d %d 2 3\n",primer[i],N-primer[i]);
			
		}
	}
	return 0;
}
