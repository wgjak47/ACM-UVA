#include<stdio.h>
main()
{
    int m,n,i,j,l,k;
    int a[1000]={0};
    scanf("%d%d",&m,&n);
    for (i=2;i<=n;i++)
    for (j=2;j*i<=n;j++)
     a[j*i]=1;
     printf("=====\n");
     for (i=n;i>=m;i--)
     if (a[i]!=1 && i!=1 &&i!=0) printf("%d\n",i);
     printf("=====");
     return 0;
}
