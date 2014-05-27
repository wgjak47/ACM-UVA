#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ne[500001],pe[500001];
int tot;
void solve(int nl,int pl)
{
	int i=0,j=0,cur=0;
	tot=1;
	bool np;
	if (pe[i]>ne[j])
	{
		np=false;
		cur=ne[j];
		j++;
	}
	else 
	{
		np=true;
		cur=pe[i];
		i++;
	}
	while (i<pl && j<nl)
	{
		if (np) 
		{ 
			while (cur>=ne[j]) 
			{
				j++;
				if (j>=nl) 
				return ;
			}
			cur=ne[j];
			np=false;
		//	printf("%d\n",cur);
			tot++;
		}
		else 
		{
			while (cur>=pe[i]) 
			{
				i++;
				if (i>=pl) 
					return ;
			}
			cur=pe[i];
			np=true;
		//	printf("%d\n",cur);
			tot++;
		}
	}
}
main()
{	
	int N;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		int nl=0,pl=0;
		int temp=0;
		for (int i=0;i<N;i++)
		{
			scanf("%d",&temp);
			if (temp<0) ne[nl++]=-temp;
			else pe[pl++]=temp;
		}
		sort(ne,ne+nl);
		sort(pe,pe+pl);
		solve (nl,pl);
		printf("%d\n",tot);
	}	
	return 0;
}
