#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> data;
long long left[100010],right[100010];
bool judge(long long z,int N)
{
	long long x=data[1],y=z-x;
	left[1]=x;right[1]=0;
	for (int i=2;i<=N;i++)
	if (i%2==0)
	{
		left[i]=min(x-left[i-1],data[i]);
		right[i]=data[i]-left[i];
	}	
	else 
	{
		right[i]=min(y-right[i-1],data[i]);
		left[i]=data[i]-right[i];
	}
	return left[N]==0;
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		long long a,L=0,R;
		data.clear();
		data.push_back(0);	
		for (int i=1;i<=N;i++)
		{
			scanf("%lld",&a);	
			data.push_back(a);
		}
		if (N==1)
		{
			printf("%lld\n",data[N]);
			continue;
		}
		data[0]=data[N];
		data.push_back(data[1]);
		for (int i=1;i<=N+1;i++)
			L=max(data[i]+data[i-1],L);
		R=3*L;
		if (data.size()%2==0)
			printf("%lld\n",L);
		else 
		{
			while (L<R)
			{
				long long mid=(L+R)/2;
				if (judge(mid,N)) R=mid;
				else L=mid+1;
			}	
			printf("%lld\n",L);
		}
	}
	return 0;
}
