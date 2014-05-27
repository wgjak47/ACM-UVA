#include<stdio.h>
#include<string.h>
main()
{
	char s[10100];
	int sum[10100]={0},i,j,k=0,l,m,n,maxline=0;
	memset(sum,0,sizeof(sum));
	while (gets(s)!=NULL)
	{	
		l=strlen(s);i=0;m=0;j=0;
                if (l==1 && s[0]=='0') break;
                for (i=0;i<l;i++)
               if (s[i]=='0') m++;
                 else break;
               if (m!=l)
                for (i=m;i<=l;i++)
                 s[j++]=s[i];
               else {s[0]='0';s[1]='\0';}
                l=strlen(s);
		for (i=0;i<l;i++)
		{	
			sum[i]+=s[l-1-i]-48+k;
			k=0;
			if (sum[i]>=10)
			{
				sum[i]-=10;
				k=1;
			}
		}
		if (k==1) 
                {
                  sum[l]++;l++;
		while (sum[l-1]>=10)
		{
			sum[l-1]=sum[l-1]-10;
			l++;
                        sum[l-1]++;
		}
                }
		k=0;
		if (l>=maxline) maxline=l;
	}
	for (i=maxline-1;i>=0;i--)
		printf("%d",sum[i]);
        putchar('\n');
	return 0;  
}
