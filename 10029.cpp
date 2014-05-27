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
char s[25100][18];
int dp[25100];
int my_strcmp(char *a,char *b)
{
	int la=strlen(a);
	int lb=strlen(b);
	int aa=0,bb=0;
	while (aa<=la && bb<=lb)
	{
		if (a[aa]==' ') aa++;
		if (a[aa]!=b[bb])
			return a[aa]-b[bb];
		aa++,bb++;
	}
	return 0;
}
int z=0;
int mid_search(char *tmp,int l,int r)
{
	while (l<=r)
	{
		int mid=(l+r)/2;
		int value=my_strcmp(tmp,s[mid]);
		if (value==0) return mid;
		else if (value>0) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
void change(char *p,int d)
{
	char tmp[20];
	int  l=strlen(p);
	int k;
	pf(i,0,l)
	{
		//change
		strcpy(tmp,p);
		pf(j,0,26)
		{
			if (p[i]==j+'a') continue;
			tmp[i]=j+'a';
			if (strcmp(tmp,p)>0) break;
			k=mid_search(tmp,0,d-1);
			if (k!=-1) dp[d]=max(dp[d],dp[k]+1);
		}
		
		tmp[i]=' ';//delete
		k=mid_search(tmp,0,d-1);
		if (k!=-1) dp[d]=max(dp[d],dp[k]+1);
		tmp[i]=p[i];
		
		mf(j,l,i)//insert
		tmp[j]=tmp[j-1];
		tmp[l+1]='\0';
		pf(j,0,26)
		{
			tmp[i]=j+'a';
			if (strcmp(tmp,p)>0) break;
			k=mid_search(tmp,0,d-1);
			if (k!=-1) dp[d]=max(dp[d],dp[k]+1);
		}
	}
}
main()
{
	int k=0;
	int maxs=0;
	gets(s[k++]);
	while(gets(s[k])!=NULL) k++;
	pf(i,1,k) 
	{
		change(s[i],i);
		maxs=max(maxs,dp[i]);
	}
	printf("%d\n",maxs+1);
	return 0;
}
