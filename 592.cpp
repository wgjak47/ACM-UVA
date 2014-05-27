#include<cstdio>
#include<cstring>
char fact[50];
int man[10];
int lie[10];
main()
{
	int N;
	int i,j,k;
	bool no;
	int ans;
	while (scanf("%d",&N)==1)
	{
		getchar();
		for (i=0;i<N;i++)
		{
			gets(fact);
			switch(fact[3])
			{
				case 'I':
				if (fact[7]=='n')
				{
					no=true;		
				}
				else no=false;
				if (no) ans=9;
				else ans=13;
				if (!strcmp(fact+ans,"divine"))
				{
					if (no)
					man[fact[0]-'A']=1;
					else man[fact[0]-'A']=-1;
				}
				else if (!strcmp(fact+ans,"evil"))
				{
					if (no)
					man[fact[0]-'A']=2;
					else man[fact[0]-'A']=-2;
				}
				else if (!strcmp(fact+ans,"human"))
				{
					if (no)
					man[fact[0]-'A']=3;
					else man[fact[0]-'A']=-3;
				}
				else if (!strcmp(fact+ans,"lying"))
				{
					flag=1;
				}
				case 
			




	
