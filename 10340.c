#include<stdio.h>
#include<string.h>
char t[110000],s[110000];
int find()
{
	int i,j,k;
	int lt,ls;
	lt=strlen(t);
	ls=strlen(s);
	k=0;
	if (lt<ls) return 0;
	for (i=0;i<lt;i++)
	{
		if (s[k]==t[i]) k++;
		if (k==ls) return 1;
	}
	return 0;
}
main()
{
	while (scanf("%s%s",s,t)!=EOF)
	{
		if (find()) printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}
