//对于a' = b, b' = a % b 而言，我们求得 x, y使得 a'x + b'y = Gcd(a', b')
//由于b' = a % b = a - a / b * b (注：这里的/是程序设计语言中的除法)
//那么可以得到:
//a'x + b'y = Gcd(a', b') ===>
//bx + (a - a / b * b)y = Gcd(a', b') = Gcd(a, b) ===>
//ay +b(x - a / b*y) = Gcd(a, b)
//因此对于a和b而言，他们的相对应的p，q分别是 y和(x-a/b*y)	
#include<cstdio>
#include<cstring>
typedef long long LLD;
LLD gcd(LLD a,LLD b,LLD &X,LLD &Y)
{
	if (b==0)
	{
		X=1,Y=0;
		return a;
	}
	int r=gcd(b,a%b,X,Y);
	int t=X;
	X=Y;
	Y=t-a/b*Y;
	return r;
}
main()
{
	LLD A,B,X,Y,D;	
	while (scanf("%lld%lld",&A,&B)==2)
	{
		D=gcd(A,B,X,Y);	
		printf("%lld %lld %lld\n",X,Y,D);
	}
	return 0;
}
