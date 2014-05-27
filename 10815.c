#include<stdio.h>
#include<string.h>
char sr[100010][210];
int  my_scanf(char *s)
{
	char m;
	int i=0,j=0;
	while ((m=getchar())>0)
	{ 
	   if (m>='A' && m<='Z')
           m-='A'-'a';
	   if (m>='a' && m<='z')
	   s[i++]=m;
	   else 
	    {
		   s[i]='\0';
		   return 1;
		}
	}
	s[i]='\0';
	return 0;
}

main()
{ 
	char *s[100010]={NULL},*temp;
	int i=0,j,k,l,n,m;
	while(my_scanf(sr[i++])>0)
 	{
	  s[i-1]=sr[i-1];
      if (i!=1)
 	  {
		if (strlen(s[i-1])==0) 
		{
			continue;
			i=i-1;
		}
	    for (j=0;j<i-1;j++)
		{
		m=strcmp(s[i-1],s[j]);
		if (m==0)
		{
			i--;
			break;
 		}
		else if (m<0)
 		{
			temp=s[i-1];
			for (l=i-2;l>=j;l--)
			s[l+1]=s[l];
			s[j]=temp;
			break;
		}
 		}
	  }
	}
	  for (j=0;j<i-1;j++)
	  {
		if (strlen(s[j])!=0)
		puts(s[j]);
	  }
	return 0;
}
