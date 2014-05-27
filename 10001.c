//hash + dfs
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int data[10000][50];
int first[1000],next[100000];
int turn[10];
int eden;
int total;
int hash(char *s,int l)
{
	int i,sum=0;
	for (int i=0;i<l;i++)
		sum=sum*2+s[i],sum%=997;
	return sum;
}
int find(char *s,int l)
{
	int h=hash(s,l);
	int i;
	for (i=first[h];i!=-1;i=next[i])
		if (strcmp(s,data[i])==0)
			return i;
	next[total]=first[h];
	first[h]=total;
	return -1;
}
int get_code(int a,int b,int c)
{
	return a*4+b*2+c;
}
void dfs();
main()
{
	int machine,lenght;
	int str[50];
	while (scanf("%d",&machine)==1)
	{
		eden=0;
		total=0;
		memset(first,0,sizeof(first));
		scnaf("%d",&lenght);
		getchar();
		scanf("%s",str);
		dfs();
	}
	return 0;
}
