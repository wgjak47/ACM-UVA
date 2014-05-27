#include<stdio.h>
#include<string.h>
int my_strstr(char *s,char *m)
{
	int i,j,l1,l2,reg=0;
	l1=strlen(s);
	l2=strlen(m);
	for (i=0;i<l1;i++)
	{
		if (s[i]==m[0])	
		for (j=1;j<l2;j++)
		if (m[j]!=s[i+j])
	    break;
        else if (j==l2-1) if (!(s[i+l2]>'a' && s[i+l2]<='z'))
		   if (i-1>0) {	if (!(s[i-1]>='a'&&s[i-1]<='z')) reg++;}
		else reg++;
	}
	return reg;
}
char *strdown(char *s,char *m)
{
	int i=0;
	while(s[i++]!='\0')
	if (s[i-1]>='A' && s[i-1]<='Z')
	m[i-1]=s[i-1]-'A'+'a';
	else m[i-1]=s[i-1];
	m[i-1]='\0';
	return m;	
}
main()
{
	char s[100][1000];
	char key[100][1000];
	char temp[1000];
	int i,j,k=0,l,m,n,max,a[100]={0};
	while (scanf("%d%d",&m,&n)>0)
	{
		memset(a,0,sizeof(a));
		max=-1;
		k++;
		getchar();
		for (i=0;i<m;i++)
			gets(key[i]);
        for (j=0;j<n;j++)
		{
		gets(s[j]);
		for (i=0;i<m;i++)
		a[j]+=my_strstr(strdown(s[j],temp),key[i]);
		if (a[j]>max) max=a[j];
		}
		printf("Excuse Set #%d\n",k);
        for (j=0;j<n;j++)
			if (a[j]==max)
				puts(s[j]);
         putchar('\n');
	}
	return 0;
}

	


