#include<cstdio>
#include<cstring>
int s1[100],s2[100],re[100];
int l,op;
int lg(long long N,int *a)
{
	int k=0;
	while (N)
	{
		a[k++]=N%10;
		N/=10;
	}
	return k;
}
void amb(int *a,int *b)
{
	int k=0;
	for (int i=l-1;i>=0;i--)
		b[k++]=a[i];
}
void add()
{
	memset(re,0,sizeof(re));
	for (int i=0;i<l;i++)
	{
		re[i]+=s1[i]+s2[i];
		if (re[i]>=10)
		{
			re[i]-=10;
			re[i+1]++;
			if (i+1==l) 
			{
				l++;
				break;
			}
		}
	}
/*	for (int i=l-1;i>=0;i--)
		printf("%d",re[i]);
		putchar('\n');	*/
}
bool judge(int *a)
{
	int i=0,j=l-1;
	while (i<j)
	{
		if (a[i]!=a[j]) return false;
		i++;
		j--;
	}
	return true;
}
void DG(int cur,int *s1,int *s2)
{
	add();
	if (judge(re))
	{
		op=cur;
		return ;
	}
	else 
	{
		memcpy(s1,re,sizeof(re));
		amb(s1,s2);
		DG(cur+1,s1,s2);
	}
}
main()
{
	int N;
	scanf("%d",&N);
	long long k;
	while (N--)
	{
		op=0;
		scanf("%lld",&k);	
		l=lg(k,s1);	
		amb(s1,s2);
		DG(0,s1,s2);
		printf("%d ",op+1);
		for (int i=l-1;i>=0;i--)
			printf("%d",re[i]);
		putchar('\n');
	}
	return 0;
}
