#include<string.h>
#include<stdio.h>
#include<stdlib.h>
char alph[11][3]={{'\0','\0','\0'},{'A','J','S'},{'B','K','T'},{'C','L','U'},{'D','M','V'},{'E','N','W'},{'F','O','X'},{'G','P','Y'},{'H','Q','Z'},{'I','R','\0'}};
int vowel[30];
int consonant[30];
char odd[300];
char even[300];
char strings[300];
judge_vowel(char c)
{
	if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
		return  1;
	return 0;
}
int cmp(const void *a,const void *b)
{
	return (*(char *)a)-(*(char *)b);
}
main()
{ 
	int i,j,k;
	int N,n;
	int flag;
	int reg=0;
/*	freopen("/home/wgj/in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	scanf("%d",&N);
	while (N--)
	{
		scanf("%d",&n);
		memset(vowel,0,sizeof(vowel));
		memset(consonant,0,sizeof(consonant));
		int ans=0,anx=0;
		for (j=0;j<n;j++)
		for (i=1;i<=9;i++)
		{
			flag=0;
			if (j%2==0)
			{
				for (k=0;k<3;k++)
					if (judge_vowel(alph[i][k]) && vowel[alph[i][k]-'A']<21 && alph[i][k]!='\0')
					{
						even[anx++]=alph[i][k];
						vowel[alph[i][k]-'A']++;
					    flag=1;	
						break;
					}
			}
			else 
			{
				for (k=0;k<3;k++)
					if (!judge_vowel(alph[i][k]) && consonant[alph[i][k]-'A']<5 && alph[i][k]!='\0')
					{
						odd[ans++]=alph[i][k];
						consonant[alph[i][k]-'A']++;
						flag=1;
						break;
					}
			}
			if (flag) break;
		}
		if (n%2==0)
		{
		   qsort(odd,n/2,sizeof(char),cmp);
		   qsort(even,n/2,sizeof(char),cmp);
		}
		else 
		{
		   qsort(odd,n/2,sizeof(char),cmp);
		   qsort(even,(n+1)/2,sizeof(char),cmp);
		}	
		int s=0,k=0;
		for (j=0;j<n;j++)
		{
			strings[j]=even[k++];
			j++;
			strings[j]=odd[s++];
		}
		strings[n]='\0';
	    printf("Case %d: %s\n",++reg,strings);
	}
	return 0;
}
