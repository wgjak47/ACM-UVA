//for any a*a+b*b=c*c
//exist m & n belong to 1,2....
//that a=m*m-n*n,b=2*m*n,c=m*m+n*n
#include<cstdio>
#include<cstring>
#include<cmath>
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
bool find[1000100];
main()
{
	int N;
	while (scanf("%d",&N)==1)
	{
		memset(find,0,sizeof(find));
		int reg=0,total=0;
		int M=(int)sqrt(N);
		for (int i=1;i<=M;i++)
		for (int j=i+1;j<=M;j++)
		{
			int a=j*j-i*i;
			int b=2*i*j;
			int c=i*i+j*j;
			if (c>N) break;
			if (gcd(gcd(a,b),c)==1)
			{
				reg++;
				int k=1;
				while (c*k<=N)
					find[a*k]=find[b*k]=find[c*k]=true,k++;
			}
		}
		for (int i=1;i<=N;i++)
			if (!find[i]) total++;
		printf("%d %d\n",reg,total);
	}
	return 0;
}
