#include<stdio.h>
#include<string.h>
void judge(int *lh,int *ll,int m,int n,char s[60][60],char sc[100])
{
  int length,i,j,k,l;
  int x,y,flag;
  length=strlen(sc)-1;
  for (i=0;i<=length;i++)
  if (sc[i]>='A' && sc[i]<='Z') sc[i]=sc[i]-'A'+'a';
    for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	if (sc[0]==s[i][j])
	{
      x=i;y=j;flag=0;
	if (x>=length)/*up*/
	{
	for (l=1;l<=length;l++)
	if (s[x-l][y]!=sc[l])
	{ flag++;break;}
	}
    else flag++;	
	if (m-x>=length)/*down*/
	{
	for (l=1;l<=length;l++)
	if (s[x+l][y]!=sc[l])
	{ flag++;break;}
	}
    else flag++;	
	if (n-y>=length)/*right*/
	{
	for (l=1;l<=length;l++)
	if (s[x][y+l]!=sc[l])
	{ flag++;break;}
	}
	else flag++;	
	if (y>=length)/*left*/
	{
	for (l=1;l<=length;l++)
	if (s[x][y-l]!=sc[l])
	{ flag++;break;}	
	}
	else flag++;
	if (x>=length && y>=length)/*up && left*/
	{
	for (l=1;l<=length;l++)
	if (s[x-l][y-l]!=sc[l])
	{ flag++;break;}	
	}
	else flag++;
	if (x>=length && n-y>=length)/*up && right*/ 
	{
	for (l=1;l<=length;l++)
	if (s[x-l][y+l]!=sc[l])
	{ flag++;break;}
	}	
	else flag++;
    if (m-x>=length && n-y>=length)/*down && right*/
	{
	for (l=1;l<=length;l++)
	if (s[x+l][y+l]!=sc[l])
	{ flag++;break;}	
	}
	else flag++;
	if (m-x>=length && y>=length)/*down && left*/
	{
	for (l=1;l<=length;l++)
	if (s[x+l][y-l]!=sc[l])
	{ flag++;break;}	
	}
	else flag++;
    if (flag<8) 
	{
		*lh=x;
		*ll=y;
        return ;	
	}
	}
}   
main()
{
	char s[60][60],sc[100];
	int ca,i,j,l,k,m,n,ans;
	int lh,ll,length;
	scanf("%d",&ca);
	for (ans=0;ans<ca;ans++)
{
    scanf("%d%d",&m,&n);
	getchar();
	for (i=0;i<m;i++)
		gets(s[i]);
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	if (s[i][j]>='A' && s[i][j]<='Z')
		s[i][j]-='A'-'a';
	scanf("%d",&k);
	getchar();
	for (l=0;l<k;l++)
	{
    gets(sc);
    judge(&lh,&ll,m,n,s,sc);
    printf("%d %d",lh+1,ll+1);	
	 putchar('\n');
	}
if (ans!=ca-1)	putchar('\n');
}
return 0;
}
