#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ant
{
	int lt,num;
	char c;
};
ant data[10010];
int order[10010];
int cmp(ant a,ant b)
{
	return a.lt<b.lt;	
}
main()
{
	int T;
	scanf("%d",&T);
	int ca=0;
	while (T--)
	{
		int L,t,n;
		scanf("%d%d%d",&L,&t,&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d %c",&data[i].lt,&data[i].c);
			data[i].num=i;
		}
		sort(data,data+n,cmp);
		//for (int i=0;i<n;i++) data[i].ltm=i;
		for (int i=0;i<n;i++)			
		if (data[i].c=='L')		
			data[i].lt-=t;
		else data[i].lt+=t;
		for (int i=0;i<n;i++)			
			order[data[i].num]=i;
		sort(data,data+n,cmp);
		for (int i=1;i<n;i++)
			if (data[i].lt==data[i-1].lt)
				data[i].c=data[i-1].c='T';
		printf("Case #%d:\n",++ca);
		for (int i=0;i<n;i++)
		{
			int j=order[i];
			if (data[j].lt<0 || data[j].lt>L)
			printf("Fell off\n");
			else if (data[j].c=='T') printf("%d Turning\n",data[j].lt);
			else printf("%d %c\n",data[j].lt,data[j].c);
		}
		putchar('\n');
	}
	return 0;
}
