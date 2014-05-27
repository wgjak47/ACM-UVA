#include<iostream>
#include<cstring>
#include<cstdio>
#include<cctype>
char AC[12100];
char PE[12100];
char MY[12100];
char MYPE[12100];
void input(char *S,int L)
{
	int i=0;
	int reg=0;
	while ((S[i++]=getchar())!=EOF)
	{
		if (S[i-1]=='\n')
			reg++;
		if (reg==L) {S[i]='\0';return ;}
	}
	return ;
}
void copy(char *a,char *b)
{
	int l=strlen(a);
	int k=0;
	for (int i=0;i<l;i++)
		if (isdigit(a[i]))
		{
			b[k++]=a[i];
		}
	b[k]='\0';
}
main()
{
	int run=0;
	int N;
	int S;
	while (scanf("%d",&N) && N!=0)
	{
		getchar();
		input(AC,N);
		scanf("%d",&S);
		getchar();
		input(MY,S);
		if (!strcmp(AC,MY)) {printf("Run #%d: Accepted\n",++run);}
		else
		{	
			copy(AC,PE);
			copy(MY,MYPE);
			if (!strcmp(PE,MYPE)) 
				printf("Run #%d: Presentation Error\n",++run);
			else printf("Run #%d: Wrong Answer\n",++run);
		}
	}
	return 0;
}
