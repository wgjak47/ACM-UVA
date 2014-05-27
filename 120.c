#include<stdio.h>
#include<string.h>
#include<ctype.h>
int max(int *a,int maxline)
{
	int i,l=0,max=0;
	for (i=0;i<=maxline;i++)
	if (a[i]>max) 
	{
		max=a[i];
		l=i;
	}
	return l;
}
void sort(int *a,int maxline)
{ 
	int i,j,l,k;
	int temp[10000];
	for (i=0;i<maxline;i++)
 	{
      printf("%d",a[i]);
	  if (i!=maxline-1) printf(" ");
	}
	printf("\n");
	for (i=maxline-1;i>=0;i--)
 	{
	   l=max(a,i);
	   if (i!=l)
	   {
	     if (l!=0)
	     {
			printf("%d ",maxline-l);
			k=0;
			for (j=l;j>=0;j--)
			temp[k++]=a[j];
			for (j=0;j<=l;j++) 
			a[j]=temp[j];
		 }
		 printf("%d ",maxline-i);
		 k=0;
		 for (j=0;j<=i;j++)
		 temp[j]=a[j];
		 for (j=i;j>=0;j--)
		 a[k++]=temp[j];
	   }
	}
	printf("0\n");
}
main()
 { 
	char c;
	int i=0,j,k,l,m,n;
	int a[10000];
	while ((c=getchar())!=EOF)
  	{ 
    if (isdigit(c)) 
 	{ 
		ungetc(c,stdin);
		scanf("%d",&a[i++]);
 	}
	if (c=='\n')
 	{
       sort(a,i);
	   i=0;
 	}
	}
	return 0;
}
