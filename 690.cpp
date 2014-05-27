#include <stdio.h>
#include <string.h>
const char ans[8][16]={"SIMPLE","FULLY-GROWN","MUTAGENIC","MUTANT"};
int n,len,p;
char buf[1024]={'\0'};
void Cellular()
{
     if(!(len&1))
     { p=3; return; }
     if(len==1)
     {
        if(buf[0]=='A') p=0; // SIMPLE
        else p=3;
        return;
     }
     if(buf[len-2]=='A'&&buf[len-1]=='B') // FULL-GROWN
     { p=1; return; }
     if(buf[0]=='B'&&buf[len-1]=='A')//MUTAGENIC
     { p=2; return; }
     p=3;
     return;
}
int main()
{
    scanf("%d",&n);
    for(int t=0;t<n;t++)
    {
       scanf("%s",buf);
       len=strlen(buf);
       Cellular();
       printf("%s\n",ans[p]);
    }
    return 0;
}
