#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
struct tools
{
	string type;
	string name;
	int value,quality;
};
vector<tools> input[1000];
string typenames[1000];
int search(string &a,int k)
{
	for (int i=0;i<k;i++)
		if (a==typenames[i]) return i;
	return k;
}
bool cal(int mid,int k,int b)
{
	int sum=0;
	for (int i=0;i<k;i++)
	{
		int min=-1;
		for (int j=0;j<input[i].size();j++)
			if (input[i][j].quality>=mid && (min==-1 || input[i][j].value<input[i][min].value))
				min=j;
		if (min!=-1)
		sum+=input[i][min].value;
		else 
			return false;
	}
	return sum<=b;
}
main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int	k=0;
		int n,b;
		scanf("%d%d",&n,&b);
		getchar();
		tools in;
		int l=1000000001,r=0;
		for (int i=0;i<n;i++)
		{
			cin>>in.type>>in.name>>in.value>>in.quality;
			if (in.quality<l) l=in.quality;
			if (in.quality>r) r=in.quality;
			int z=search(in.type,k);
			if (z==k)
			{
				input[k].clear();
				typenames[k]=in.type;
				input[k++].push_back(in);
			}
			else input[z].push_back(in);
		}
		while (l<r)
		{
			int mid=l+(r-l+1)/2;
			if (!cal(mid,k,b)) r=mid-1;
			else l=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
