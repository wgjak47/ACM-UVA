#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
bool vis[11000];
vector<int> primes;
int num[5100];
void get_primes()
{
	memset(vis,0,sizeof(vis));
	for (int i=2;i<=10000;i++)
	{
		if (!vis[i]) primes.push_back(i);
		for (int j=0;j<primes.size() && primes[j]*i<=10000;j++)
		{
			vis[primes[j]*i]=1;
			if (i%primes[j]==0) break;
		}
	}
	return ;
}
void plus(int p,int q)
{
	for (int i=p;i>=q;i--)
	{
		int k=0;
		int z=i;
		while (z!=1)
		{
			if (z%primes[k]==0)
				z/=primes[k],num[k]++;
			else k++;
		}
	}
}
void minus(int a,int b)
{ 
	for (int i=a;i<=b;i++)
 	{
		int k=0;
		int z=i;
		while (z!=1)
		{
			if (z%primes[k]==0)
				z/=primes[k],num[k]--;
			else k++;
 		}
	}
}
double calculate()
{
	double sum=1;
	for (int i=0;i<primes.size();i++)
		if (num[i]>0)
			sum*=pow(primes[i]*1.0,num[i]*1.0);
		else if (num[i]<0) 
			sum/=pow(primes[i]*1.0,abs(num[i])*1.0);
	printf("%.5f\n",sum);
}
main()
{
	int p,q,r,s;
	get_primes();
	while (scanf("%d%d%d%d",&p,&q,&r,&s)==4)
	{
		memset(num,0,sizeof(num));
		plus(p,p-q+1);
		minus(r-s+1,r);
		minus(2,q);
		plus(s,2);
		calculate();
	}
	return 0;
}
