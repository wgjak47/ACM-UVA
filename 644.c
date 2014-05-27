#include<stdio.h>
#include<string.h>
char s[100000][20];
int my_strcmp(char *s,char *sc)
{
    int i=0,j=0;
    while(s[i++]==sc[j++]);
    if (s[i-1]=='\0' || sc[j-1]=='\0' ) return 0;
    else return 1;
}
main()
{
    char temp;
   int a,b,c,d,e,flag=1,g=0,i=0,j,k,l;
   freopen("in.txt","r",stdin);
   while (gets(s[i++])!=NULL)
   {
       if (s[i-1][0]=='9')

       {
        g++;
        i=0;
        if (flag)
        printf("Set %d is immediately decodable\n",g);
        else printf("Set %d not immediately decodable\n",g);
        flag=1;
       }
       if (flag)
       if (i!=1)
       {
           for (j=0;j<i-1;j++)
           if (!(flag=my_strcmp(s[i-1],s[j])))
              break;
       }
   }
   return 0;
}
