#include<cstdio>
#include<cstring>
long long s1[100],s2[100],re[100];
int length(long long a,long long *s)
{
	int k=0;
	while (a)
	{
		s[k++]=a%10;
		a/=10;
	}
	return k;
}
main()
{	
	long long a,b,c,d;
	while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		int reg=0;
		if (a==0 && b==0) break;
		memset(re,0,sizeof(re));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		int l1=length(a,s1);
		int l2=length(b,s2);
		int l=l1>l2?l1:l2;
		for (int i=0;i<=l;i++)
		{
			re[i]+=s1[i]+s2[i];
			if (re[i]>=10)
			{
				reg++;
				re[i]=re[i]-10;
				re[i+1]+=1;
			}
		}
		if (reg==0)
		printf("No carry operation.\n");
		else 
		if (reg==1)
		printf("1 carry operation.\n");
		else printf("%d carry operations.\n",reg);
	}
	return 0;
}
