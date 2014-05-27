#include<stdio.h>
#include<string.h>
char s1[10000],s[10000],s2[10000];
int  dpart(char *s,char *s1,char * s2)
{
   long long l=0,l1,l2,i=0,j=0,len,length;
   while (s[i++]!='\0')
   if (s[i-1]=='+' || s[i-1]=='*')
	   break;
   len=i-1;
   for (i=0;i<len;i++)
	   if (s[i]>='0' && s[i]<='9')
       s1[j++]=s[i];
   s1[j]='\0';
   j=0;
   length=strlen(s);
   for (i=len+1;i<length;i++)
	   if (s[i]>='0' && s[i]<='9')
	   s2[j++]=s[i];
       s2[j]='\0';
	   i=0;j=0;l=0;
	   l1=strlen(s1);
	   l2=strlen(s2);
	   i=0;j=0;l=0;
   while (s1[i++]=='0');
   for (j=i-1;j<=l1;j++)
        s1[l++]=s1[j];
   i=0;j=0;l=0;
   while (s2[i++]=='0');
   for (j=i-1;j<=l2;j++)
        s2[l++]=s2[j];
   i=0;j=0;l=0;
if (strlen(s1)==0) {s1[0]='0';s1[1]='\0';};
if (strlen(s2)==0) {s2[0]='0';s2[1]='\0';}
	   return len;
}
int judge(char *s)
{
   int l,lc;
   char m[]={"2147483647"};
   l=strlen(s);
   lc=strlen(m);
if (l<lc) return 0;
if (l>lc) return 1;
if (strcmp(s,m)>0)
	return 1;
else return 0;
}
void plus(char *s,char *s1,char *s2)
{
	int a1[10000]={0},a2[10000]={0},sum[10000]={0};
	int i=0,j,k,l1,l2,l,maxline;
	l1=strlen(s1);l2=strlen(s2);
	for (i=0;i<l1;i++)
		a1[l1-1-i]=s1[i]-'0';
	for (i=0;i<l2;i++)
		a2[l2-1-i]=s2[i]-'0';
	l=l1>l2?l1:l2;
	for (i=0;i<l;i++)
	{
		sum[i]+=a1[i]+a2[i];
		if (sum[i]>=10)
		{
			sum[i]-=10;
			sum[i+1]+=1;
		}
	}
	if (sum[l]!=0) maxline=l;
    else maxline=l-1;
	for (i=maxline;i>=0;i--)
		s[maxline-i]=sum[i]+'0';
	s[i]='\0';
}
void multip(char *s,char *s1,char *s2)
{
	int a1[10000]={0},a2[10000]={0},sum[10000]={0};
	int i=0,j,k,l1,l2,l,maxline;
	l1=strlen(s1);l2=strlen(s2);
	for (i=0;i<l1;i++)
		a1[l1-1-i]=s1[i]-'0';
	for (i=0;i<l2;i++)
		a2[l2-1-i]=s2[i]-'0';
    for (i=0;i<=l1;i++)
	for (j=0;j<l2;j++)
	{
	sum[i+j]+=a1[i]*a2[j];
    if (sum[i+j]>=10)
	{
		sum[i+j+1]+=sum[i+j]/10;
		sum[i+j]%=10;
	}
	}
	if (sum[l1+l2-1]!=0) maxline=l1+l2-1;
	else maxline=l1+l2-2;
	for (i=maxline;i>=0;i--)
		s[maxline-i]=sum[i]+'0';
	s[maxline+1]='\0';
	if (s1[0]=='0' || s2[0]=='0')
	{s[0]='0';s[1]='\0';}
}
main()
{ 
   int i,j,k,l,m,n;
   while(gets(s)!=NULL)
   {
	  l=dpart(s,s1,s2);
	  puts(s);
	    if (judge(s1))
	  printf("first number too big\n");
  if (judge(s2))
	  printf("second number too big\n");
  if (s[l]=='*')
  if (s1[0]=='0' || s2[0]=='0') 
  {
	  continue;
  }
  if (judge(s1)==0 && judge (s2)==0 )
  {
      switch(s[l])
	  {	    case '+':memset(s,0,sizeof(s));
plus(s,s1,s2);break;
		case '*':memset(s,0,sizeof(s));
multip(s,s1,s2);break;
		default:;
	  }
	  if (judge(s)) printf("result too big\n");
  }
 else printf("result too big\n");
   }
  return  0;
}
