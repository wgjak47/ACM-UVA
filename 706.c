#include<stdio.h>
#include<string.h>
#define num0 {{" - "},{"| |"},{"   "},{"| |"},{" - "}}
#define num1 {{"   "},{"  |"},{"   "},{"  |"},{"   "}}
#define num2 {{" - "},{"  |"},{" - "},{"|  "},{" - "}}
#define num3 {{" - "},{"  |"},{" - "},{"  |"},{" - "}}
#define num4 {{"   "},{"| |"},{" - "},{"  |"},{"   "}}
#define num5 {{" - "},{"|  "},{" - "},{"  |"},{" - "}}
#define num6 {{" - "},{"|  "},{" - "},{"| |"},{" - "}}
#define num7 {{" - "},{"  |"},{"   "},{"  |"},{"   "}}
#define num8 {{" - "},{"| |"},{" - "},{"| |"},{" - "}}
#define num9 {{" - "},{"| |"},{" - "},{"  |"},{" - "}}
int main()
{
		int len,i,j,k,l,p,o,n,u,a[100]={0};
		 char s[100],sm[10][10][10]={num0,num1,num2,num3,num4,num5,num6,num7,num8,num9};
		 while (scanf("%d",&n)>0)
		 {
				getchar();
					scanf("%s",s);
					 len=strlen(s);
					  if (n==0 && len==1 && s[0]=='0') break;
					   for (i=0;i<len;i++)
						    a[i]=s[i]-48;
					    for (i=0;i<5;i++)
						{
							if (i!=0 && i!=4 && i!=2 )
								for (j=1;j<=n;j++)
									for (u=0;u<len;u++)
									{
										putchar(sm[a[u]][i][0]); 
										for(l=1;l<=n;l++)
											putchar(sm[a[u]][i][1]);
										putchar(sm[a[u]][i][2]);
										if (u!=len-1) putchar(' '); 
										else   putchar('\n');
									}
							else
								for (u=0;u<len;u++)
								{
									putchar(sm[a[u]][i][0]); 
									for(p=1;p<=n;p++)
										putchar(sm[a[u]][i][1]);
									putchar(sm[a[u]][i][2]);
									if (u!=len-1) putchar(' ');
									else putchar('\n');
								}
						}
						printf("\n");
		 }
		 return 0;
} 

