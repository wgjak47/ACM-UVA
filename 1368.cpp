#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
main()
{
	int T;
	int fx[30];
	scanf("%d",&T);
	while (T--)
	{
		int m,n;
		vector<string> d;
		scanf("%d%d",&m,&n);
		getchar();
		string in;
		for (int i=0;i<m;i++)	
		{
			cin>>in;
			d.push_back(in);
		}
		string out;
		int ans=0;
		for (int j=0;j<n;j++)
		{
			memset(fx,0,sizeof(fx));
			int max=0;
			for (int i=0;i<m;i++)
			{
				char c=d[i][j];
				fx[c-'A']++;
				if (fx[c-'A']>fx[max]) 
					max=c-'A';
				else if (fx[c-'A']==fx[max] && c-'A'<max)
					max=c-'A';
				
			}
			ans+=m-fx[max];
			out.append(1,max+'A');
		}
		cout<<out<<endl;
		printf("%d\n",ans);
	}
	return 0;
}
