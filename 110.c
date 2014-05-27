#include<stdio.h>
#include<string.h>
int  fx[10];
int k;
void space(int reg)
{
	int i;
	for (i=0;i<reg;i++)
		printf("  ");
}
void sort(int reg)
{
	int temp,i;
	int fx_bak[10];
	if (reg==k)
	{
		space(reg);
		printf("writeln(");
		for (i=0;i<reg;i++)
		{
			printf("%c",fx[i]+'a');
			if (i!=reg-1) printf(",");
		}
		printf(")\n");
		return ;
	}
	else 
	if (reg==0)
	{
		fx[0]=0;
		sort(reg+1);
	}
	else 
	{
		fx[reg]=reg;
		for (i=reg;i>=0;i--)
		{
			space(reg);
			if (i==reg)
			printf("if %c < %c then\n",fx[i-1]+'a',fx[i]+'a');
			else if (i!=0)printf("else if %c < %c then\n",fx[i-1]+'a',fx[i]+'a');
			else printf("else\n");
			memcpy(fx_bak,fx,sizeof(fx));
			sort(reg+1);
			memcpy(fx,fx_bak,sizeof(fx));
			if (i!=0)
			{
				temp=fx[i];
				fx[i]=fx[i-1];
				fx[i-1]=temp;
			}
		}
	}
}
main()
{
	char a[10];
	int n,j,i;
	scanf("%d",&n);
	while (n--)
	{
		printf("program sort(input,output);\nvar\n");
		scanf("%d",&k);
		for (i=0;i<k;i++)
		{
			a[i]='a'+i;
			putchar(a[i]);
			if (i!=k-1) putchar(',');
		}
		printf(" : integer;\n");
		printf("begin\n");
		printf("  readln(");
		for (i=0;i<k;i++)
		{
			a[i]='a'+i;
			putchar(a[i]);
			if (i!=k-1) putchar(',');
		}
		printf(");\n");
		sort(0);
		printf("end.\n");
		if (n) putchar('\n');
	}
	return 0;
}
