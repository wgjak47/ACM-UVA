#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000];
int mirror (int l)
{
	int n,t=0,i,re=0;
	if (l%2==0) n=0;
	else n=1;	
	for (i=0;i<=l/2;i++)
	{ 
	if (i<=l-i-1) 
	   switch(s[i])
	   { 
		case 'A': case 'H': case 'I':	case 'M': case 'O': case 'T':
		case 'U': case 'V':case 'W':case 'X':case 'Y': case '1':case '8':
	   if (s[i]==s[l-i-1]) t++;break;
	case 'E': if (s[l-i-1]=='3') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case '3': if (s[l-i-1]=='E') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case 'S': if (s[l-i-1]=='2') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case 'Z': if (s[l-i-1]=='5') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case '2': if (s[l-i-1]=='S') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
        case '5': if (s[l-i-1]=='Z') t++;if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case 'L': if (s[l-i-1]=='J') t++; if (s[i]==s[l-i-1]) {re=1;t++;}break;
	case 'J': if (s[l-i-1]=='L') t++; if (s[i]==s[l-i-1])  {re=1;t++;}break;			  
	default: if (s[i]==s[l-i-1]) t++; re=1; 
	   }
	}
	    if (t==l/2+n)  
            if (re==0) return 1;
		else return 2;
	return 0;
}
int judger (int len)
{  
	int i;
	if (len%2==0)
	{
		for (i=0;i<len/2;i++)
          if (s[len/2+i]!=s[len/2-1-i])
                return 0;
 	 }
	else 
	{
		for (i=0;i<=len/2;i++)
			if (s[len/2-i]!=s[len/2+i])
				return 0;
 	} 
	return 1;
}
main()
{ 
	int a,l,b,i,c,d,judge2,judge,reg=0;
	/*freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	while(scanf("%s",s)>0)
 	{
		 
		
		l=strlen(s);
		judge=judger(l);
		if (judge==0)
		{
                judge2=mirror(l);
		if (judge2==2) printf ("%s -- is a regular palindrome.\n",s);
                else
		if (judge2==0) printf("%s -- is not a palindrome.\n",s);
		else printf("%s -- is a mirrored string.\n",s);
  	 	}
		else
		{
		judge2=mirror(l);
		if (judge2==1) printf("%s -- is a mirrored palindrome.\n",s);
		else printf("%s -- is a regular palindrome.\n",s);
 	 	}
        putchar('\n');
	} 
	return 0;
}	


