#include<cstdio>
#include<cstring>
#include<cctype>
#include<stdlib.h>
int in[1100000];
typedef struct st
{
	int value,sum;	
} stack;
stack fuck[1100000];
int input()
{
	int  k=0;
	char c;
	while ((c=getchar())!=EOF)
	{
		if (c=='\n') return k;
		else ungetc(c,stdin),scanf("%d",&in[k++]);
	}
	return -1;
}
main()
{
	int total;
	int k;
	int max;
	int ok;
	while ((total=input())!=-1)
	{
		k=0;
		ok=1;
		if (total&1) ok=0;
		else 
		{
			memset(fuck,0,sizeof(fuck));
			for (int i=0;i<total;i++)
			if (in[i]<0) fuck[++k].value=-in[i];
			else if ((fuck[k].value-in[i])==0) 
			{
				fuck[k-1].sum+=in[i];
				if (fuck[k].value<=fuck[k].sum) {ok=0;break;}
				fuck[k].sum=0;
				k--;
			}
			else {ok=0;break;}
		}
		if (ok) printf(":-) Matrioshka!\n");
		else printf(":-( Try again.\n");
	}	
	return 0;
}
