#include<stdio.h>
#include<string.h>
#include<ctype.h>
char dict[100100][2][12];
char temp[20];
int head[100100],next[100100];
int hash(char *s)
{
	int i,sum=0;
	for (i=0;s[i]!='\0';i++)
	sum+=(s[i]-'0')*i;
	return sum%11231;
}
void insert(int k)
{
	int i,h=hash(dict[k][1]);
	next[k]=head[h];
	head[h]=k;	
}
int find(char *s)
{
	int i,h=hash(s);
	for (i=head[h];i!=-1;i=next[i])
	{
		if (!strcmp(s,dict[i][1]))
		   return i;	
	}
	return -1;
}
main()
{
	int i,j,k=0;
	char c;
	memset(head,-1,sizeof(head));
	while ((c=getchar())!=EOF)
	{
		if (c=='\n') break;
		else ungetc(c,stdin);
		scanf("%s%s",dict[k][0],dict[k][1]);
		getchar();
		insert(k);
		k++;
	}
	char input[20];
	while (scanf("%s",input)==1)
	{
		int lt=find(input);
		if (lt==-1)
			puts("eh");
		else 
		puts(dict[lt][0]);	
	}
	return 0;
}
