#include<stdio.h>
#include<string.h>
main()
{
	char s[100000];
	int i,j,k,l,m,n;
    scanf("%d",&n);
	getchar();
	for (i=0;i<n;i++)
	{
       scanf("%s",s);
	   l=strlen(s);
	   if (l==1 && (s[0]=='4'||s[0]=='1')) 
	   {
		   printf("+\n");
		   continue;
	   }
	   if (l==2 && s[0]=='7' && s[1]=='8')
	   {
		   printf("+\n");
		   continue;
	   }
	   if (l>=3)
	   {
	     if (s[l-2]=='3' && s[l-1]=='5')
			 printf("-\n");
		 else 
		 if (s[0]=='9' && s[l-1]=='4')
			 printf("*\n");
		 else
		 if (s[0]=='1' && s[1]=='9' && s[2]=='0')
			 printf("?\n");
	   }
	}
	return 0;
}


