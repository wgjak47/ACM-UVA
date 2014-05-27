#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct agency
{
	int A,B;
	char name[20];
	int total;
};
agency data[120];
void get_agency(int i)
{
	int k=0;
	char c;
	while (c=getchar(),c!=':') data[i].name[k++]=c;
	data[i].name[k]='\0';
	scanf("%d,%d",&data[i].A,&data[i].B);
	data[i].total=0;
	getchar();
}
int cmp(const agency &a,const agency &b)
{
	if (a.total!=b.total) return a.total<b.total;
	else if (strcmp(a.name,b.name)<0) return 1;
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	int reg=0;
	while (T--)
	{
		int N,M,L;
		scanf("%d%d%d",&M,&N,&L);
		getchar();
		for (int i=0;i<L;i++)
			get_agency(i);
		for (int i=0;i<L;i++)
		{
			int Z=M,last;
			while (1)
			{
				last=Z;
				Z=last/2;		
				if (Z>=N)
					if (data[i].B<=data[i].A*(last-Z))
						data[i].total+=data[i].B;	
					else data[i].total+=data[i].A*(last-Z);
				else data[i].total+=(last-N)*data[i].A,Z=N;
				if (Z==N) break;
			}
		}
		sort(data,data+L,cmp);
		printf("Case %d\n",++reg);
		for (int i=0;i<L;i++)
			printf("%s %d\n",data[i].name,data[i].total);
	}
	return 0;
}
