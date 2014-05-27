#include<stdio.h>
#include<string.h>
#define s name
#define p pockets
struct AP
{
  char name[3];
};
struct AP pockets[60][60];
int all,flag,a[60]={0};
void move(int i)
{
	int j,l;
	for (l=i;l<all;l++)
	{
	for (j=0;j<=a[l+1];j++)
		p[l][j]=p[l+1][j];
	a[l]=a[l+1];
	}
	all--;
}
main()
{
   int i=0,j,l,sum,t,flag,temp1,temp2; 
   while (scanf("%s",pockets[i++][0].name),pockets[i-1][0].name[0]!='#')
	   if (i==52)
	   {
		   memset(a,0,sizeof(a));
		   all=52;
		   while (1)
		   {
		   flag=0;
		   for (j=1;j<all;j++)
		   {
			   if (j>=3)
			   {
				  if (p[j][a[j]].name[0]==p[j-3][a[j-3]].name[0] || p[j][a[j]].name[1]==p[j-3][a[j-3]].name[1])
				  {
					  p[j-3][++a[j-3]]=p[j][a[j]--];
					  flag=1;
				  }
			   }
				  if (!flag)
				  if (p[j][a[j]].name[0]==p[j-1][a[j-1]].name[0]|| p[j][a[j]].name[1]==p[j-1][a[j-1]].name[1])
				  {
					  a[j-1]++;
					  p[j-1][a[j-1]]=p[j][a[j]];
					  a[j]--;
					  flag=1;
				  } 
				  if (a[j]==-1) {move (j); break;}
				  if (flag)  break;
		   }
		   if (!flag) break;
		   }
		   if (a[0]==51) printf("1 pile remaining: 52\n");
		   else 
		   {
			   printf("%d piles remaining:",all);
		       for (i=0;i<all;i++) 
				   printf(" %d",a[i]+1);
			   putchar('\n');
		   }
		   i=0;
	   }
       return 0;
}
