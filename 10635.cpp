#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
const int MAXN=250*250+10;
int fx[MAXN],b[MAXN],g[MAXN];
int mid_find(int *d,int l,int r,int key)
{
	int mid=0;
	while (l<r)
 	{
		mid=(l+r)/2;
		if (d[mid]==key) return mid;
		else if(d[mid]>key) r=mid;
		else l=mid+1;
	}
	return l;
}
main()
{
	int T;
	int n,p,q;
	scanf("%d",&T);
	int reg=0;
	while (T--)
 	{
		memset(fx,-1,sizeof(fx));
		memset(g,-1,sizeof(g));
		scanf("%d%d%d",&n,&p,&q);
		for (int temp,i=0;i<=p;i++)
		{
			scanf("%d",&temp);
			fx[temp]=i;
		}
		for (int i=0;i<=q;i++)
		{
			scanf("%d",&b[i]);
			b[i]=fx[b[i]];
			//printf("%d ",b[i]);
		}
		int k=0,result=0;
		for (int i=0;i<=q;i++)
		if (b[i]!=-1)
		{
			if (k==0)
				g[k++]=b[i];
			else
			{
				k=mid_find(g,0,result,b[i]);
				g[k++]=b[i];
			}
			result=max(result,k);
		}
		printf("Case %d: %d\n",++reg,result);
			
	}
	return 0;
}
