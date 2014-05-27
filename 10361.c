#include<stdio.h>
#include<string.h>
main()
{
	char s1[1010],s2[1010];
	int i,j,k,l,m,n,len1,len2,x[2],y[2];
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;i++)
	{
       gets(s1);k=0;
	   gets(s2);m=0;
	   len1=strlen(s1);
	   len2=strlen(s2);
	   for (l=0;l<len1;l++)
	    {
			if (s1[l]=='<')
				x[m++]=l;
			if (s1[l]=='>')
				y[k++]=l;
		}
	   s2[len2-3]='\0';
	   for (l=0;l<len1;l++)
		if (s1[l]!='<' && s1[l]!='>')
			putchar(s1[l]);
	   putchar('\n');
	   printf("%s",s2);
	   for (l=x[1]+1;l<=y[1]-1;l++)
		   putchar(s1[l]);
	   for (l=y[0]+1;l<=x[1]-1;l++)
		   putchar(s1[l]);
	   for (l=x[0]+1;l<=y[0]-1;l++)
		   putchar(s1[l]);
	   for (l=y[1]+1;l<len1;l++)
		   putchar(s1[l]);
		   putchar('\n');
	}
	return 0;
}
