#include<stdlib.h>
#include<stdio.h>
long long m[2000];
long long min(long long a,long long b,long long c)
{
	if (a<b && a<c) return 1;
	if (b<c && b<a) return 2;
	if (c<b && c<a) return 3;
	if (a==b && a<c) return 4;
	if (a==c && a<b) return 5;
	if (b==c && c<a) return 6;
	if (b==c && a==c) return 7;
}
main()
{
	int reg=0;
	long long a=1,b=1,c=1,i,j;
	m[1]=1;
	for (i=2;i<=1500;i++)
	{ 
	    reg=min(m[a]*2,m[b]*3,m[c]*5);
		switch(reg)
	 	{
			case 1:m[i]=m[a]*2;a++; break;
			case 2:m[i]=m[b]*3;b++; break;
			case 3:m[i]=m[c]*5;c++; break;
			case 4:m[i]=m[a]*2;a++;b++; break;
			case 5:m[i]=m[a]*2;a++;c++; break;
			case 6:m[i]=m[b]*3;b++;c++; break;
			case 7:m[i]=m[a]*2;a++;b++;c++; break;
		}
   	}
	printf("The 1500'th ugly number is %lld.\n",m[1500]);
	return 0;
}
