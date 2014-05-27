#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const long long MAX=1<<16;
bool notp[MAX+10];
struct factor
{
	int fa,num;
};
vector<factor> fac;
vector<int> primer;
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
main()
{
	int M,N;
	get_primer();
	while (scanf("%d%d",&M,&N)==2)
	{
		fac.clear();
		int No=N;
		for (int i=0;i<primer.size() && primer[i]<=N;i++)
		{
			if (N==1) break;
			if (N%primer[i]==0)
			{
				factor temp;
				temp.fa=primer[i];
				temp.num=0;
				while (N%primer[i]==0)
				{
					N/=primer[i];
					temp.num++;
				}
				fac.push_back(temp);
			}
		}
		if (N!=1) 
		{
			factor temp;
			temp.fa=N;
			temp.num=1;
			fac.push_back(temp);
		}
		bool divide=true;
		for (int i=0;i<fac.size();i++)	
		{
			int a=M,ans=0;
			while (a)
			{
				ans+=a/fac[i].fa;
				a/=fac[i].fa;
			}
			if (fac[i].num>ans)
			{
				divide=false;
				break;
			}
		}
		if (divide)
			printf("%d divides %d!\n",No,M);
		else printf("%d does not divide %d!\n",No,M);
	}
	return 0;
}
