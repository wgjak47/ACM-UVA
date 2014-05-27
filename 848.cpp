#include<cstdio>
#include<cstring>
#define nobreak 1
#define breaks 2
#define 
int k=0;
main()
{
	char c;
	char s[80];
	while (c=getchar(),c!=EOF)
	{
		if (c=='\n') 
		{
			c=getchar();
			switch(c)
			{
				
			}
		}
		s[k++]=c;	
		if (k==72)
		{
			c=getchar();
			if ((c!=' ' || c!='\n') && outl(s))
			{
				output(s,nobreak);
				while (c=getchar(),c!=' ' && c!='\n' && c!=EOF)
					putchar(c);
				if (c==EOF) return 0;
				putchar('\n');
				if (c==' ') k=0,s[k++]=c;	
			}
			else if ((c!=' ' || c!='\n'))
			{
				
			}
		}
	}	
	return 0;
}
