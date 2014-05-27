#include<stdio.h>
#include<string.h>
#include<math.h>
int factor[800];
int flag[900]={0};
int primer[800];
int fuck[900];
void find_primer()
{
	int i,j,k,l;
	for (i=2;i<=29;i++)
	for (j=2;i*j<=800;j++)
		flag[i*j]=1;
	k=0;
	for (i=2;i<=800;i++)
		if (!flag[i])
		primer[k++]=i;
}
long long find_factor(int m)
{ 
	int i,j,k=0;;
	for (i=0;primer[i]<=m;i++)
	{
		int flag=0;
		while (m%primer[i]==0)
		{
			flag=1;
			fuck[primer[i]]++;
			factor[k]=primer[i];
			m/=primer[i];
		}
		if (flag) k++;
	}
	return k;
}
main()
{ 
	long long  i,j,k,l,m,n,temp;
	long long  shit[900],f;
	double x;
	find_primer();
	while (scanf("%lld%lld",&n,&m)!=EOF)
 	{
		memset(fuck,0,sizeof(fuck));
		memset(shit,0,sizeof(shit));
		k=find_factor(m);
		for (i=n;i>1;i--)
		for (j=0;j<k;j++)
		{
			temp=i;
			while (temp%factor[j]==0)
			{
				temp/=factor[j];
				shit[factor[j]]++;
			}
		}
		int min=shit[factor[0]]/fuck[factor[0]];
		for (i=0;i<k;i++)
		{
			l=shit[factor[i]]/fuck[factor[i]];
			if (l<min) min=l;
		}
		x=0;
		for (i=2;i<=n;i++)
			x+=log((double)i);
		f=(long long)(x/log((double)m)+1e-4)+1;
		printf("%d %lld\n",min,f);
	}
	return 0;
}
