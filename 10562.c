#include<stdio.h>
#include<string.h>
char s[210][210];
int m;
void tree (int deep,int head)
{
	if (deep>=m) return ;
	putchar(s[deep][head]);
	putchar('(');
	if (s[deep+1][head]=='|')
	{
		int right,left;
		int i,j;
		i=head;
		while (s[deep+2][i++]=='-');
		right=i-1;
		j=head;
		while (s[deep+2][j--]=='-' && j>=0);
		left=j+1;
		for (i=left;i<=right;i++)
		{
			if (s[deep+3][i]=='\0') break;
			if (s[deep+3][i]!=' ' && s[deep+3][i]!='|' && s[deep+3][i]!='-' && s[deep+3][i]!='#')
							tree(deep+3,i);
		}
	}
	putchar(')');
}
main()
{
	int n,i;
/*	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	scanf("%d",&n);
	getchar();
	while (n--)
	{
		m=0;
		while (gets(s[m++])!=NULL)
			if (s[m-1][0]=='#') break;
		m--;
		int l=strlen(s[0]);
		for (i=0;i<l;i++)
			if (s[0][i]!='-' && s[0][i]!=' '&& s[0][i]!='|')
				break;
		putchar('(');
		tree(0,i);
		putchar(')');
		putchar('\n');
 	}
	return 0;
}
