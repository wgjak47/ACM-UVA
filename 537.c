#include<stdio.h>
#include<string.h>
#include<ctype.h>
double judge(char s,double x)
{
	switch(s)
	{
      case 'm':return x/1000;
	  case 'k':return x*1000;
	  case 'M':return x*1000000;
	  default :return x;
	}
}
main()
{
	char s[1000];
	int j,k,l,n,m;
	int fU,fI,fP;
	double u,i,p;
	scanf("%d",&n);
	getchar();
	for (l=0;l<n;l++)
	{
	j=0;fU=0;fI=0;fP=0;
    while (s[j++]=getchar(),s[j-1]!='\n')
	{
	if (s[j-1]==' ') j--;
	if (s[j-1]>='0' && s[j-1]<='9' && s[j-2]=='=')
	switch(s[j-3])
    {
		case 'I':ungetc(s[j-1],stdin);if (scanf("%lf",&i)<=0) break;while(s[j++]=getchar(),s[j-1]==' ');i=judge(s[j-1],i);fI=1;break;
		case 'U':ungetc(s[j-1],stdin);if (scanf("%lf",&u)<=0) break;while(s[j++]=getchar(),s[j-1]==' ');	 u=judge(s[j-1],u);fU=1;break;
		case 'P':ungetc(s[j-1],stdin);if (scanf("%lf",&p)<=0) break;while(s[j++]=getchar(),s[j-1]==' ');	p=judge(s[j-1],p);fP=1;break;
		default:;		
	}
	}	
	if (fI==0) printf("Problem #%d\nI=%.2lfA\n",l+1,p/u);
	if (fU==0) printf("Problem #%d\nU=%.2lfV\n",l+1,p/i);
	if (fP==0) printf("Problem #%d\nP=%.2lfW\n",l+1,u*i);
	 putchar('\n');
	}
	return 0;
}
