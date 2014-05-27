#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
char input[1000];
int k,C;
int w[20];
int min(int a,int b)
{
	return a>b?b:a;
}
bool find()
{
	for (int i=0;i<=k;i++)
		for (int j=i+1;j<=k;j++)
		if (w[i]!=0 && w[j]!=0)
		if ((int)floor((double)C/(double)w[i])%(k+1)==(int)floor((double)C/(double)w[j])%(k+1))
		{
			C=min((int)(floor((double)C/(double)w[i])+1)*w[i],((int)floor((double)C/(double)w[j])+1)*w[j]);
			return true;
		}
	return false;
}
main()
{
	int reg=0;
	while (gets(input)!=NULL)
	{	
		C=100000;
		puts(input);
		int i,j,l,m,n;
		memset(w,0,sizeof(w));
		l=strlen(input);
		j=0;
		while (input[j]==' ') j++;
		k=0;
		for (i=j;i<l;i++)
		{
			if (isalpha(input[i]))
			{
				w[k]=w[k]*32+input[i]-'a'+1;	
			}
			else if (input[i]==' ' && isalpha(input[i+1])) k++;
		}
		for (i=0;i<=k;i++)
		{
			if (C>w[i] && w[i]!=0) C=w[i];
		}
		while (find());
		printf("%d\n",C);
		puts(""); 
	}
	return 0;
}
