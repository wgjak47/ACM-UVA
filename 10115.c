#include<stdio.h>
#include<string.h>
char s[10000][500],sc[10000][500],find[100000];
void replace(char *find,char *s,char *sc)
{
    int i,j,flag=0;
	int len1,len2,len3;
    len1=strlen(find);
	len2=strlen(s);
	len3=strlen(sc);
	for (i=0;i<len1;i++)
	if (s[0]==find[i])
	{
		flag=0;
		for (j=1;j<len2;j++)
		if  (s[j]==find[i+j]);
	    else {flag=1;break;}
	if (!flag)
	{
	 if (len2<len3)
	 for (j=len1;j>=i+len2-1;j--)
		 find[j+len3-len2]=find[j];
	 else if (len2>len3)
	 if (len3!=0)
	 for (j=i+len2-1;j<=len1;j++)
		 find[j-(len2-len3)]=find[j];
	 else 
		 for (j=i;j<=len1-len2;j++)
		 find[j]=find[j+len2];
	 for (j=0;j<len3;j++)
		 find[i+j]=sc[j];
	 len1=strlen(find);
	 i=0;
	}
	}
}
main()
{ 
	int i,j,k,l,m,n;
	while (scanf("%d",&n),n)
 	{
		getchar();
		for (i=0;i<n;i++)
 		{
			gets(s[i]);
			gets(sc[i]);
		}
	gets(find);
	for (i=0;i<n;i++)
    replace(find,s[i],sc[i]);
	puts(find);
	memset(s,0,sizeof(s));
	memset(sc,0,sizeof(sc));
	memset(find,0,sizeof(find));
	}
	return 0;
}



