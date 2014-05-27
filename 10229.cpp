//find the repeatability
#include<cstdio>
#include<cstring>
#include<vector>
#define MOD (1<<i)
using namespace std;
main()
{
	int N,M;
	vector<int> v[24];
	int length[24];
	for (int i=1;i<20;i++)
	{
		v[i].push_back(0);
		v[i].push_back(1);
		int k=2,x;
		bool find=false;
		while (1)
		{
			x=(v[i][k-1]%MOD+v[i][k-2]%MOD)%MOD;	
			if (x==0 && find) {length[i]=k;break;}
			else find=false;
			if (x==1) find=true;
			v[i].push_back(x);
			k++;
		}
	}	
	while (scanf("%d%d",&N,&M)==2)
	{
		if (M==0) 
			printf("0\n");
		else 
		{
			printf("%d\n",v[M][N%length[M]]);	
		}
	}	
	return 0;
}
