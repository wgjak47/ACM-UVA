#include<stdio.h>
#include<string.h>
char s[1000000];
main()
{
	long long i,j,k,m,l,sum;
while(fgets(s,sizeof(s),stdin)!=NULL)
{
	if (s[0]=='0') break;
	sum=0;k=1;
	l=strlen(s);
	for (i=l-2;i>=0;i--)
	{
	k*=2;
	sum+=(s[i]-'0')*(k-1);
	}
	printf("%lld\n",sum);
}
return 0;
}
	

