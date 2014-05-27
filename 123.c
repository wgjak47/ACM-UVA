#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char except[60][110];	
char s[300][10001];
char a[10001];
int judge (char *temp,int maxline)
{
	int i;
	for (i=0;i<=maxline;i++) 
	if (strcmp(temp,except[i])==0) return 0;
	return 1;
}
void strdown(char *s)
{
   int i;
   int l=strlen(s);
   for (i=0;i<l;i++)
    if (s[i]>= 'A' && s[i]<='Z') s[i]-='A'-'a';
}
int cmp(const void *a,const void *b)
{
	char temp1[10001],temp2[10001];
	int i,j,k,l,m,n;
	char *sa=(char *)a,*sb=(char *)b;
	int la=strlen(sa),lb=strlen(sb);
	k=0;
	for (i=0;i<la;i++) 
	if (sa[i]>='A' && sa[i]<='Z') temp1[k++]=sa[i];
	temp1[k]='\0';
	k=0;
	for (i=0;i<lb;i++)
	if (sb[i]>='A' && sb[i]<='Z') temp2[k++]=sb[i];
    temp2[k]='\0';
	return strcmp(temp1,temp2);
}
main()
{ 
	int maxline,i=0,j,k,l,m,n=0;
	char temp[10001];int cp,rp;
/*	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	while (scanf("%s",except[i++])>0)
		if (except[i-1][0]==':') break;
	maxline=i-1;i=0;
	while (gets(a)!=NULL)
 	{
		l=strlen(a);
		strdown(a);
		rp=0;
		for (i=0;i<=l;i++)
		if (a[i]==' ' || a[i]=='\0')
 		{
            cp=i;k=0;
			if (rp==0) rp--;
			for (j=rp+1;j<cp;j++)
			if (a[j]!=' ')
				temp[k++]=a[j];
			    temp[k]='\0';
			if (k!=0)
 			{
			if (judge(temp,maxline))
 			{
				for (j=0;j<=rp;j++)
					s[n][j]=a[j];
				for (j=rp+1;j<cp;j++)
					s[n][j]=a[j]+'A'-'a';
				for (j=cp;j<=l;j++)
					s[n][j]=a[j];
				n++;
			}
			}
			rp=cp;
		}
	}
	qsort(s,n,sizeof(s[0]),cmp);
	for (i=0;i<n;i++)
		puts(s[i]);
	return 0;
}
