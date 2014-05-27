#include<stdio.h>
#include<string.h>
#define MAX if (sum<temp) sum=temp	
#define int long long
int a[20],zero[20],falses[20],n;
he (int x,int mid,int y)
{
	int i,temp1=1,temp2=1;
	for (i=x;i<mid;i++)
		temp1*=a[i];
	for (i=mid+1;i<=y;i++)
		temp2*=a[i];
	return temp1>temp2?temp1:temp2;
}
judge(int x,int y)
{
	int i,flag2=0;
    int sum=1,temp;
	if (x>y) return 0;
	if (y-x==0) if (a[x]<0) return 0;
	            else return a[x];
	for (i=x;i<=y;i++)
		if (a[i]<0) falses[flag2++]=i;
	if (flag2%2==0) 
		{
			for (i=x;i<=y;i++)
				sum*=a[i];
		}
		else 
		{
			for (i=0;i<flag2;i++)
			{
			    temp=he(x,falses[i],y);
				MAX;
			}
        }
	return sum;
}	
main()
{
	int j,i,k=0,l,m,temp1,temp2,temp;
	int flag1,sum;
	while (scanf("%lld",&n)==1)
	{
		sum=0;
		flag1=0;
		memset(zero,0,sizeof(0));
	    for (i=0;i<n;i++)
		{
		  scanf("%lld",&a[i]);
		  if (a[i]==0) 
			  zero[flag1++]=i;
		}
		if (n!=1)
		{
		if (flag1>0)
		{
			if (flag1>1)
			{
			for (i=0;i<flag1-1;i++)
			if (sum<(temp=judge(zero[i]+1,zero[i+1]-1)))
				sum=temp;
			}
			if (a[0]!=0)
			{
				temp=judge(0,zero[0]-1);
				MAX;
			}
			if (a[n-1]!=0)
			{
				temp=judge(zero[flag1-1]+1,n-1);
				MAX;
			}
		}
		else sum=judge(0,n-1);
		}
		else sum=a[0]>0?a[0]:0;
		printf("Case #%lld: The maximum product is %lld.\n\n",++k,sum);
	}
	return 0;
}
