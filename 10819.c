#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define PN putchar('\n')
char s[120][120];
int x[8]={1,1,0,-1,-1,0,-1,1};
int y[8]={1,0,1,-1,0,-1,1,-1};
void outputs(int m,int n)
{
	int i,j,k,reg;
	for (i=1;i<=m;i++)
	{
	for (j=1;j<=n;j++)
	{
		reg=0;
		if (s[i][j]!='*')
		{
			for (k=0;k<8;k++)
			if (s[i+x[k]][j+y[k]]=='*')
				reg++;
			printf("%d",reg);
		}
		else putchar('*');
	}
	PN;
	}
}
main()
{ 
	int m,n;
	int i,j,k=0,l;
	while (scanf("%d%d",&m,&n)==2)
 	{
	    memset(s,'.',sizeof(s));
		if (m==n && n==0) break;
		getchar();
		for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
		{
        s[i][j]=getchar();
		if (s[i][j]=='\n')
		{
			ungetc(s[i][j],stdin);
			getchar();
			s[i][j]=getchar();
		}
		}
		if (k!=0) PN;
		printf("Field #%d:\n",++k);
        outputs(m,n);
	}
	return 0;
}

