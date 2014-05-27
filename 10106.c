#include<stdio.h>
#include<string.h>
int  convert_number(char *s , int * m)
{
	int i,j=0,l=0,length=strlen(s);
	for (i=0;i<length;i++)
	if (s[i]!='0') break;
	for (j=i;j<=length;j++)
	s[l++]=s[j];
	length=strlen(s);
	for (i=0;i<length;i++)
	 m[length-1-i]=s[i]-'0';
	return length;
}
char s[300],sn[300];
int sum[1000]={0},st[300],stn[300];
main()
{
   int i,j,k,l,m,n,len1,len2,maxline;
   while (gets(s),gets(sn)!=NULL)
   {
	   maxline=0;
	   len1=convert_number(s,st);
	   len2=convert_number(sn,stn);
     if (len1==0 || len2==0)
     {
	     printf("0\n");
	     continue;
     }
     for (i=0;i<=len2;i++)
     
     for (j=0;j<len1;j++)
     {
	sum[j+i]+=stn[i]*st[j];
        if (sum[j+i]>=10)
	{
           sum[j+i+1]+=sum[j+i]/10;
           sum[j+i]%=10;
	}
     }
     if (sum[j+i-2]!=0) maxline=j+i-2;
     else maxline=j+i-3;
     for (n=maxline;n>=0;n--)
	     printf("%d",sum[n]);
     putchar ('\n');
     
     memset(sum,0,sizeof(sum));
     memset(st,0,sizeof(st));
     memset(stn,0,sizeof(stn));
   }
   return 0;
}


       
      
