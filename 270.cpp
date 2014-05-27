#include<cstdio>
#include<cstring>
#include<cctype>
#include<stdlib.h>
int maxs;
int x[8000],y[8000];
int head[2000],next[300000];
int reg[8000];
struct fuct
{
	int a,b;
};
fuct data[800];
int gcd(int a,int b)
{
	if (a==0) return b;
	if (b==0) return a;
	if (a>b) gcd(b,a%b);
	else gcd(a,b%a);
}
int hash(fuct temp)
{
	int sum=temp.a*100+temp.b*10;
	return (abs(sum))%1987;
}
bool insert(int k,int i,int j)
{
	fuct temp;
	temp.a=y[i]-y[j];
	temp.b=x[j]-x[i];
	int l=gcd(abs(temp.a),abs(temp.b));
	temp.a/=l;
	temp.b/=l;
	int p,temps;
	int h=hash(temp);
	for (p=head[h];p!=-1;p=next[p])
		if (temp.a==data[p].a && temp.b==data[p].b) 
		{
			reg[p]++;
			if (maxs<reg[p]) maxs=reg[p];
			return false;
	 	}
		else if (temp.a==-data[p].a && temp.b==-data[p].b)
		{
			reg[p]++;
			if (maxs<reg[p]) maxs=reg[p];
			return false;
	 	}
	data[k]=temp;
	next[k]=head[h];
	head[h]=k;
	return true;
}
main()
{
	int N;
	scanf("%d",&N);
	getchar();
	getchar();
	while (N--)
	{
		int c,n=0;
		maxs=0;
		while ((c=getchar())!=EOF)
		{
			if (isdigit(c)) 
			{
				ungetc(c,stdin);
				scanf("%d%d",&x[n],&y[n]);
				n++;
				getchar();
			}
			else break;
		}
		int k;
		for (int i=0;i<n;i++)
		{
			k=0;
			memset(head,-1,sizeof(head));
			memset(reg,0,sizeof(reg));
			for (int j=0;j<n;j++)
			if	(j!=i)
			if  (insert(k,i,j)) k++;
		}
		printf("%d\n",maxs);
		if (N) putchar('\n');
	}		
	return 0;
}
