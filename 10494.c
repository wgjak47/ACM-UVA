#include<stdio.h>
#include<string.h>
char s[10000];
int sn[10000];
int cn[10000];
main()
{
	char a;
	long long i,k,j,l,m,n,mod;
	while(scanf("%s %c %lld",s,&a,&n)==3)
	{
		memset(cn,0,sizeof(cn));
		i=0;m=0;mod=0;
		while(s[i]=='0')
			i++;
		l=strlen(s);
		for(j=i;j<l;j++)
		sn[m++]=s[j]-'0';
		l=l-i;
		for (i=0;i<l;i++)
		{
          mod=mod*10+sn[i];
		  cn[i]=mod/n;
		  mod=mod%n;
		}
		switch(a)
		{
			case '%':printf("%lld\n",mod);break;
			case '/':
			i=0;
			while (cn[i]==0 && i<l) i++;
			if (i>=l) printf("0");
			for (j=i;j<l;j++)
				printf("%d",cn[j]);
			putchar('\n');break;
			default:;
		}
	}
	return 0;
}
    
