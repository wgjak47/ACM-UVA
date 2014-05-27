#include<cstdio>
#include<cstring>
#include<cstdlib>
int a[10010];
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int sum;
bool judge(int N)
{
	if (sum%2==1) return false;
	for (int i=0;i<N-1;i++)
	{
		qsort(a,N,sizeof(int),cmp);
		if (i+a[i]>=N)	return false; 
		for (int j=i+1;j<i+a[i]+1;j++)
		{
			a[j]--;
			if (a[j]<0)	return false; 
		}
	}
	if (a[N-1]!=0) return false;
	return true;
}
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		int flag=true;
		if (N==0) break;
		sum=0;
		for (int i=0;i<N;i++)	
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if (a[i]>N-1) flag=false;
		}
		if (sum==0 || flag && judge(N)) printf("Possible\n");
		else printf("Not possible\n");		
	}
	return 0;
}
