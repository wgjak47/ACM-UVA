#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int a[11]={0,1,4,9,16,25,36,49,64,81};
set<int> vis;
int flag;
int fuck(int n)
{
	int i,j,k;
	int  sum=0;
	while (n>0)
	{
		int temp=n%10;
		sum+=a[temp];
		n/=10;	
	}
	if (vis.count(sum))
	{
		flag=0;
		return 0;
	}
	else vis.insert(sum);
	if (sum!=1)
	fuck(sum);
	else 
	return 0;
}
main()
{
	int N,reg=1;
	int total;
	scanf("%d",&total);
	while (total--)
	{
		scanf("%d",&N);
		flag=1;
		fuck(N);
		if (flag) printf("Case #%d: %d is a Happy number.\n",reg++,N);
		else printf("Case #%d: %d is an Unhappy number.\n",reg++,N);
		vis.clear();
	}
	return 0;	
}
