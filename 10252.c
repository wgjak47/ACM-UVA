#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(char *)a-*(char *)b;
}
main()
{
	int i,j;
	int reg1[30];
	int reg2[30];
	char input[1200];
	char compare[1200];
	char out[1200];
	while (gets(input)!=NULL)
	{
		gets(compare);
		int li=strlen(input);
		int lc=strlen(compare);
		memset(reg1,0,sizeof(reg1));
		memset(reg2,0,sizeof(reg2));
		for (i=0;i<li;i++)
			reg1[input[i]-'a']++;
		for (i=0;i<lc;i++)
			reg2[compare[i]-'a']++;
		int k=0;
		for (i=0;i<26;i++)
			if (reg1[i] && reg2[i])
			while (reg2[i]-- && reg1[i]--)
			{
				out[k++]=i+'a';
			}
			out[k]='\0';
		qsort(out,k,sizeof(char),cmp);
		puts(out);
	}
	return 0;
}
