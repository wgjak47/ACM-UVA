#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
const int build=true;
const int search=false;
const int output=3;
const int maxn=(1<<12)+10;
int Xor[30];
std::map<int,int> X_search;
int first,second;
std::vector<int> out;
int cal(int x,int start,int st)//解码二进制信息
{
	int t=x;
	int k=0;
	int xr=-1;
	int sum=0;
	while (t)
	{
		if (t%2==1) 
		switch(st)
		{
			case output:out.push_back(start+k);sum++;break;
			case build:if (xr==-1) xr=Xor[start+k];else xr^=Xor[start+k];break;
			case search:sum++;break;
		}
		k++;
		t/=2;
	}
	if (st==build) return xr==-1?0:xr;
	else return sum;
}
void bit_search(int start,int end,bool st)//二进制搜索
{
	int l=1<<(end-start);
	int sum;
	int max=0;
	pf(i,0,l)
	{
		int value;
		if (st==build)
		{
			value=cal(i,start,build);	
			if (!X_search.count(value) || cal(X_search[value],start,search)<cal(i,start,search))
				X_search[value]=i;
		}	
		else 
		{
			value=cal(i,start,build);
			if (!X_search.count(value)) continue;
			sum=cal(X_search[value],start,search)+cal(i,start,search);
			if (max<sum)
			{
				max=sum;
				first=X_search[value];
				second=i;
			}
		}
	//	printf("%d\n",value);
	}
//	printf("-----------\n");
}
main()
{
	int N;
	std::string S;
	while (scanf("%d",&N)==1)
	{
		X_search.clear();
		getchar();
		first=second=-1;
		out.clear();
		memset(Xor,0,sizeof(Xor));
		pf(i,0,N)
		{
			std::cin>>S;
			int l=S.size();
			int tmp[27];
			memset(tmp,0,sizeof(tmp));
			pf(j,0,l)
				tmp[S[j]-'A']++;
			pf(j,0,26)
			{	
				tmp[j]%=2;
				Xor[i]=(Xor[i]<<1)+tmp[j];
			}
		}
		bit_search(0,N/2,build);
		bit_search(N/2,N,search);
		if(first==second && first==-1) {printf("0\n");continue;}
		int total=cal(first,0,output)+cal(second,N/2,output);
		printf("%d\n",total);
		pf(i,0,out.size()-1)
			printf("%d ",out[i]+1);
		printf("%d\n",out[out.size()-1]+1);
	}
	return 0;
}
