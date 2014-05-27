//无敌爆搜大法，从大开始。。
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
main()
{
	int N;
	int array[100];
	cin>>N;
	while (N--)
	{
		int m;
		int ans=0;
		for (int i=0;i<100;i++)
			array[i]=1;
		cin>>m;
		if (m>=10)
			for (int i=9;i>1;i--)
			{
				int flag=0;
				while  (m%i==0)
				{
					flag=1;
					if (array[ans]*i<10)
						array[ans]*=i;
					else 
					{
						array[++ans]=i;
					}
					m/=i;
				}
				if (flag)
				ans++;
			}
		else 
			{
				cout<<m<<endl;
				continue;
			}
		if  (m<10)
		{
			qsort(array,ans,sizeof(int),cmp);
			for (int i=0;i<ans;i++)
			cout<<array[i];
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}
