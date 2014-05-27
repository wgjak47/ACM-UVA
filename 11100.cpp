#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct trip
{
	int value,reg;
};
int cmp(int a,int b)
{
	return a<b;
}
trip data[10010];
int temp[10010];
main()
{
	int N;
	int kk=0;
	while (scanf("%d",&N)==1,N)
	{
		if (kk++) putchar('\n'); 
		for (int i=0;i<N;i++)
			scanf("%d",&temp[i]);
		sort(temp,temp+N,cmp);
		int l=0;
		data[0].value=temp[0];
		data[0].reg=1;
		for (int i=1;i<N;i++)
			if (data[l].value!=temp[i])
			{
				data[++l].value=temp[i];
				data[l].reg=1;	
			}
			else data[l].reg++;
		int max=0;
		for (int i=0;i<=l;i++)
			if (data[i].reg>max) max=data[i].reg;
		printf("%d\n",max);
/*		while (max--)
		{
			int cc=0;
			for (int i=0;i<=l;i++)
			{
				if (data[i].reg)
				{
					if (cc++) putchar(' ');
					printf("%d",data[i].value);
					data[i].reg--;
				}
			}
			putchar('\n');
		}*/
		for (int k=0;k<max;k++)
		{
			for (int i=k;i<N;i+=max)
			{
				if (i!=k) putchar(' ');
				printf("%d",temp[i]);
			}
				putchar('\n');
		}
	}	
	return 0;
}
