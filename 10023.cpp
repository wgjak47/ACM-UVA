#include<cstdio.h>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
char s[1200];
int num[1200];
void solve(char *s)
{
	int l=strlen(s);
	int k=0;
	int sum=0;
	for (i=l-1;i>=0;i--)
	{
		sum=sum*10+s[i]-'0';
		if (sum>10 || i==0)
		{
			num[k++]=sum;
			sum=0;
		}
	}	
	int v=(int)sqrt(num[0]);
	int w=num[0]-v*v;
	for (i=1;i<k;i++)
	{
		w*=100;
		w+=num[i];
		for ()
	}
}
main()
{
	while (scanf("%s",s)==1)
		solve(s);		
}
