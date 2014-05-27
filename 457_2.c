#include<stdio.h>
#include<string.h>
int main()
{
freopen("text.txt","r",stdin);
freopen("out.txt","w",stdout);
int i,j,n;
int yest[50],today[50],DNA[10];
while(scanf("%d",&n)==1)
{
while(n--)
{
for(i=0;i<10;i++)
scanf("%d",&DNA[i]);
memset(today,0,sizeof(today));
today[19]=1;
for(i=0;i<50;i++)
{
for(j=0;j<40;j++)
{
switch(today[j])
{
case 0:printf(" ");break;
case 1:printf(".");break;
case 2:printf("x");break;
case 3:printf("W");break;
}
}
printf("\n");
memcpy(yest,today,sizeof(yest));
for(j=1;j<40;j++)
today[j]=DNA[yest[j-1]+yest[j]+yest[j+1]];
today[0]=DNA[yest[0]+yest[1]];
}
if(n>0) printf("\n");
}
}
return 0;
}
