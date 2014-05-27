#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct quad
{
    int black;
	struct quad *tree[4];
	int deep;
} ;
void clear(struct quad *a)
{ 
	a->tree[0]=NULL;
	a->tree[1]=NULL;
	a->tree[2]=NULL;
	a->tree[3]=NULL;
}
struct quad *creat(int de)
{   
	int l,i;
	char c;
	struct quad *a=(struct quad *)malloc(sizeof(struct quad));
		c=getchar();
		/*putchar(c);*/
    	switch (c)
    	{
    		case 'e' : a->black=0;a->deep=de; /*clear(a);*/ return a;
    		case 'f' : a->black=1;a->deep=de; /*clear(a);*/ return a;
    		case 'p' : a->black=2;a->deep=de; break;
    	}
		for (i=0;i<4;i++)
		a->tree[i]=creat(de+1);
	return a;
}    
struct quad *compare(struct quad *a,struct quad *b)
{
	 int i,n;
	 if (a->black==1)
	 {
		 return a;
	 }
	 if (b->black==1)
	 {
		 return b;
	 }
	 if (a->black==0)
	 {
		 return b;
	 }
	 if (b->black==0)
	 {
		 return a;
	 }
     for (i=0;i<4;i++)
		 a->tree[i]=compare(a->tree[i],b->tree[i]);
	 return a;
}
int calculate(struct quad *a)
{
	int i,j,k,l,m,n,sum=0;
	if (a->black==0) 
	{
	/*	putchar('e');*/
		return 0;
	}
	if (a->black==1)
	{
		/*putchar('f');*/
		return 1<<2*(6-a->deep);
	}
	if (a->black==2) /*putchar('p');*/
	for (i=0;i<4;i++)
		sum+=calculate(a->tree[i]);
	return sum;
}
main()
{ 
   struct quad *head,*next;
   int n,i,sum;
   int c;
  /* freopen("in.txt","r",stdin);*/
   scanf("%d",&n);
   getchar();
   for (i=0;i<n;i++)
    {
	  sum=0;
	  head=creat(1);
	/* putchar('\n');*/
	  getchar();
	  next=creat(1);
	  getchar();
	 /* putchar('\n');*/
	  
/*	   putchar('\n');*/
	   printf("There are %d black pixels.\n",calculate(compare(head,next)));
   }
   return 0;
}
