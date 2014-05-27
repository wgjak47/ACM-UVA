#include<stdio.h>
#include<string.h>
int m[14][7]={{1,2,3,4,5,6},{1,3,5,2,4,6},{1,4,2,5,3,6},{1,5,4,3,2,6}, {2,1,4,3,6,5},{2,3,1,6,4,5},{2,4,6,1,3,5},{2,6,3,4,1,5},{3,1,2,5,6,4},{3,2,6,1,5,4},{3,5,1,6,2,4},{3,6,5,2,1,4}};
main()
{ 
	int judge(char *a , char *b);
	int i,j;
	char s[20];
	char a[10];
	char b[10];
	while(scanf("%s",s)>0)
 	{
	   for (i=0;i<6;i++)
	   a[i]=s[i];
	   for (i=6;i<12;i++)
	   b[i-6]=s[i];
	   a[6]='\0';b[6]='\0';
	  if (judge(a,b)) printf("TRUE\n");
	  else printf("FALSE\n");
	}
	return 0;
}
int judge(char *a,char *b)
{
	int i,j,l,k;
	for(i=0;i<12;i++)
	{
	  for (j=0;j<6;j++)
	  if (a[j]!=b[m[i][j]-1])
		  break;
      if (j==6) return 1;
          l=m[i][2];
		  m[i][2]=m[i][3];
		  m[i][3]=l;
		  k=0;
	   for (j=5;j>=0;j--)
		if (a[k++]!=b[m[i][j]-1])
			break;
          l=m[i][2];
		  m[i][2]=m[i][3];
		  m[i][3]=l;
	   if (j<0) return 1;
	}
	  return 0;
}
	

