#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct acm
{
	int p,r,num[110];
};
acm team[80];
bool cmp(acm a,acm b)
{
	return a.p>b.p;
}
bool cmpn(acm a,acm b)
{
	return a.r<b.r;
}
main()
{
	int M,N;
	int chair[60];
	while (scanf("%d%d",&M,&N)==2)
	{
		if (M==0 && N==0) break;
		for (int i=0;i<M;i++)
			scanf("%d",&team[i].p),team[i].r=i;
		for (int j=0;j<N;j++)
			scanf("%d",&chair[j]);
		sort(team,team+M,cmp);
		bool success=true;
		for (int i=0;i<M;i++)
		{
			success=true;
			int k=0;
			for (int j=0;j<N;j++)
			if (chair[j]>0)
			{
				chair[j]--;
				team[i].num[k++]=j+1;
				if (k>=team[i].p) break;
			}
			if (k!=team[i].p) {success=false;break;}
		}
		if (success==false)
			printf("0\n");
		else 
		{
			sort(team,team+M,cmpn);
			printf("1\n");
			for (int i=0;i<M;i++)
			{
				for (int j=0;j<team[i].p;j++)
				{
					if (j) putchar(' ');
					printf("%d",team[i].num[j]);
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
