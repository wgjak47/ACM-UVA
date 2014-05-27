#include<stdio.h>
#include<string.h>
char s[10000][30];
char sp[10000][30];
int cmp1(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int cmp2(const void *a,const void *b)
{
	return (*(char *)a-*(char *)b);
}
int my_strcmp(char sa[],char sb[])
{ 
	int i,j,k,l,m,n;
	int len1=strlen(sa);int len2=strlen(sb);
	char s1[30],s2[30];
	strcpy(s1,sa);strcpy(s2,sb);
	for (i=0;i<len1;i++)
    if (s1[i]>='A' && s1[i]<='Z')
		s1[i]-='A'-'a';
	for (i=0;i<len2;i++)
    if (s2[i]>='A' && s2[i]<='Z')
		s2[i]-='A'-'a';
	qsort(s1,len1,sizeof(char),cmp2);
	qsort(s2,len2,sizeof(char),cmp2);
	return strcmp(s1,s2);
}
main()
{  
    int i=0;
	int j,k,l,maxline=0;
	while  (scanf("%s",s[i++]),s[i-1][0]!='#');
	maxline=i-1;
	k=0;
    for (i=0;i<maxline;i++)
	{
	for (j=0;j<maxline;j++)
    if (i!=j)
	if (!my_strcmp(s[i],s[j])) break; 
    if (j==maxline)
	   strcpy(sp[k++],s[i]);
	}
	qsort(sp,k,sizeof(sp[0]),cmp1);
	for (i=0;i<k;i++)
		puts(sp[i]);
	return 0;
}
