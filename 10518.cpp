//矩阵二分快速幂
//		 |0 1|n	
//f[0,1]*|1 1|  =f[n,n+1];
//ans=2*(fn)-1;
//f0=1,f1=1
#include<cstdio>
#include<cstring>
struct mat
{
	long long dat[2][2];
};
mat plus(mat s1,mat s2,long long n)
{
	mat temp;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
	{
		long long sum=0;
		for (int k=0;k<2;k++)
		{
			sum+=s1.dat[i][k]*s2.dat[k][j];
		}
		temp.dat[i][j]=sum%n;
	}
	return temp;
}
mat cal(long long m,long long n,mat s)
{
	if (m==1) return s;
	mat tmp=cal(m/2,n,s);
	if (m%2==0)
		return plus(tmp,tmp,n);
	else 
		return plus(plus(tmp,tmp,n),s,n);
}
main()
{
	long long m,n;
	int T=0;
	while (scanf("%lld%lld",&m,&n)==2)
	{
		if (m==0 && n==0) break;
		long long mx[2][2]={{0,1},{1,1}};
		mat s;
		memcpy(s.dat,mx,sizeof(mx));
		long long out;
		if (m!=0)
		{
			mat ans=cal(m,n,s);
			out=ans.dat[0][1]+ans.dat[0][0];
			out=out*2-1;
		}
		else out=1;
		printf("Case %d: %lld %lld ",++T,m,n);
		printf("%lld\n",out%n);
	}
	return 0;
}
