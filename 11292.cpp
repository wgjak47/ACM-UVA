#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dragon[20001],hero[20001];
bool cmpD(int a,int b)
{
	return a<b;
}
main()
{
	int N,M;
	while (scanf("%d%d",&N,&M)==2)
	{
		if (N==0 && M==0) break;
		for (int i=0;i<N;i++)
			scanf("%d",&dragon[i]);
		for (int j=0;j<M;j++)
			scanf("%d",&hero[j]);
		bool doom=false;
		int money=0;
		sort(dragon,dragon+N,cmpD);
		sort(hero,hero+M,cmpD);
		int j=0;
		for (int i=0;i<N;i++)
		{
			doom=true;
			for (;j<M;j++)
				if (hero[j]>=dragon[i])
				{
					money+=hero[j];
					doom=false;
					j++;
					break;
				}
			if (doom) break;
		}
		if (doom) printf("Loowater is doomed!\n");
		else printf("%d\n",money);
	}
	return  0;	
}
