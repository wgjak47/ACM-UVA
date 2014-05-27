#include<stdio.h>
#include<string.h>
#include<math.h>
int loc[20][2];
char out[10];
int n;
double square(int x1,int x2,int x3,int y1,int y2,int y3)
{
	return fabs(0.5*((y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1)));
}
int judge(int i,int j,int k,double S)
{
	int ans;
	double a,b,c;
	for (ans=0;ans<n;ans++)
	if (ans!=i && ans!=j && ans!=k)
	{
		a=square(loc[ans][0],loc[i][0],loc[j][0],loc[ans][1],loc[i][1],loc[j][1]);
		b=square(loc[ans][0],loc[j][0],loc[k][0],loc[ans][1],loc[j][1],loc[k][1]);
		c=square(loc[ans][0],loc[k][0],loc[i][0],loc[ans][1],loc[k][1],loc[i][1]);
		if (fabs(a+b+c-S)<1e-6)
			return 0;
	}
	return 1;
}
main()
{
	int i,j,k,l,m;
	double S,max;
/*	freopen("in.txt","r",stdin);*/
	while (scanf("%d",&n),n!=0)
	{
		getchar();
		for (i=0;i<n;i++)
		{
			getchar();
			scanf("%d%d",&loc[i][0],&loc[i][1]);
			getchar();
		}
		max=0;
		for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
		for (k=j+1;k<n;k++)
		{
			S=square(loc[i][0],loc[j][0],loc[k][0],loc[i][1],loc[j][1],loc[k][1]);
		/*	printf("%lf\n",S);*/
			if (judge(i,j,k,S))
				if (max<S) 
				{
					max=S;
					out[0]=i+'A';
					out[1]=j+'A';
					out[2]=k+'A';
					out[3]='\0';
				}
		}
/*		printf("\n");
		printf("%lf\n",max);*/
		puts(out);
	}
	return 0;
}
