#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define pf(i,s,t) for (int (i)=s;(i)<(t);(i)++)
#define mf(i,s,t) for (int (i)=s;(i)>(t);(i)--)
#define mt(a,d) memset((a),(d),sizeof(a))
using namespace std;
char s[1100];
main()
{
	int T;
	scanf("%d",&T);
	getchar();
	int k=0;
	while (T--)
	{	
		scanf("%s",s);
		int l=strlen(s);
		int sum=0,third=0;
		pf(i,0,l)
		{
			sum+=s[i]-'0';
			if (s[i]%3==0) third++;
		}
		if (sum%3==0)
			printf("Case %d: %s\n",++k,third%2==0?"T":"S");
		else
		{
			bool found=false;
			for (int i=0;i<l;i++)
				if ((sum-s[i]+'0')%3==0)
				{
					found=true;
					printf("Case %d: %s\n",++k,third%2==0?"S":"T");
					break;
				}
			if (!found)
				printf("Case %d: T\n",++k);
		}
	}
	return 0;
}
