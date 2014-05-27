#include<stdio.h>
#include<string.h>
char M[1510][11];
char N[1510][11];
char S[2250100][21];
int head[125010],next[2251000];
int hash(char *a)
{
	int i,l=strlen(a);
	int sum=0;
	for (i=0;i<l;i++)
		sum=sum*4+(a[i]-'a')*i;
	return sum%125009;
}
int insert(int k)
{
	int i,j,h=hash(S[k]);
	for (i=head[h];i!=-1;i=next[i])
	if (!strcmp(S[i],S[k])) return 0;	
	next[k]=head[h];
	head[h]=k;
	return 1;
}
main()
{
	int i,j,k,l,m,n;
	int T;
	scanf("%d",&T);
	int reg=0;
	while (T--)
	{
		memset(head,-1,sizeof(head));
		scanf("%d%d",&m,&n);
		getchar();
		for (i=0;i<m;i++)
			gets(M[i]);
		for (i=0;i<n;i++)
			gets(N[i]);
		k=0;int sum=0;
		for (i=0;i<m;i++)
		for (j=0;j<n;j++)
		{
			strcpy(S[k],M[i]);
			strcat(S[k],N[j]);
			if (insert(k)) sum++;
			k++;
		}
		printf("Case %d: %d\n",++reg,sum);	
	}
	return 0;
}
