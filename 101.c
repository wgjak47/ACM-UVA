#include<stdio.h>
#include<string.h>
int a[30][30];
void search(int key,int n,int *x,int *y)
{
    int i,j;	
	for (i=0;i<n;i++)
	{
		j=0;
	    while (a[i][j++]!=-1)
		if (a[i][j-1]==key)
		{
			*x=i;
			*y=j-1;
			return ;
		}
	}
}
void monto(int xa,int ya,int xb,int yb)
{
     int i=yb+1,j=ya+1,k;
	 while (a[xa][j++]!=-1)
	 {
	 a[a[xa][j-1]][0]=a[xa][j-1];
	 a[a[xa][j-1]][1]=-1;
	 }
	 while (a[xb][i++]!=-1)
	 {
	 a[a[xb][i-1]][0]=a[xb][i-1];
	 a[a[xb][i-1]][1]=-1;
	 }
	 a[xb][yb+1]=a[xa][ya];
	 a[xb][yb+2]=-1;
	 a[xa][ya]=-1;
}
void mover(int xa,int ya,int xb,int yb)
{
	int j=ya+1,i=yb;
	while (a[xa][j++]!=-1)
	{
		a[a[xa][j-1]][0]=a[xa][j-1];
		a[a[xa][j-1]][1]=-1;
	}
	while (a[xb][i++]!=-1);
		a[xb][i-1]=a[xa][ya];
	    a[xb][i]=-1;
	    a[xa][ya]=-1;
}
void ponto(int xa,int ya,int xb,int yb)
{
	int i=yb+1,j=ya;
	while (a[xb][i++]!=-1)
	{
		a[a[xb][i-1]][0]=a[xb][i-1];
		a[a[xb][i-1]][1]=-1;
	}
	while (a[xa][j++]!=-1)
		a[xb][++yb]=a[xa][j-1];
	a[xb][yb+1]=-1;
	a[xa][ya]=-1;
}
void pover(int xa,int ya,int xb,int yb)
{
	int i=ya,j=yb;
	while (a[xb][j++]!=-1);
	while (a[xa][i++]!=-1)
		a[xb][j++-1]=a[xa][i-1];
	a[xa][ya]=-1;
	a[xb][j-1]=-1;
}   	
main()
{
	int i,j,k,l,m,n;
	scanf("%d",&n);
	getchar();
    memset(a,-1,sizeof(a));
	for (i=0;i<n;i++)
	a[i][0]=i;
	char s1[10],s2[10];
	int _a,b,xa,ya,xb,yb;
	while (scanf("%s%d%s%d",s1,&_a,s2,&b)>0)
	{
		search(_a,n,&xa,&ya);
		search(b,n,&xb,&yb);
		if (xa==xb) continue;
		if (s1[0]=='m' && s2[3]=='o')
			monto(xa,ya,xb,yb);
		else
		if (s1[0]=='m' && s2[3]=='r')
			mover(xa,ya,xb,yb);
		else
		if (s1[0]=='p' && s2[3]=='o')
			ponto(xa,ya,xb,yb);
		else
		if (s1[0]=='p' && s2[3]=='r')
			pover(xa,ya,xb,yb);
		else
		if (s1[0]=='q') break;
	}
	for (i=0;i<n;i++)
	{
		printf("%d:",i);
		j=0;
		while (a[i][j++]!=-1)
			printf(" %d",a[i][j-1]);
		putchar('\n');
	}
	return 0;
}


