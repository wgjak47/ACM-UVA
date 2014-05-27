#include<stdio.h>
int gy(int a,int b)
{
    if (b==0) return a;
    if (a>b) gy(b,a%b);
    else gy(a,b%a);

}
main()
{
    int m,n,k,i,j,leng;
    int a[1000]={0};
    scanf("%d%d%d",&k,&m,&n);
    i=1;
    j=m>n?n:m;
    while (i*j<=k)
    {
        a[i*m]=1;
        a[i*n]=1;
        i++;
    }
    for (i=1;m*n*i/gy(m,n)<=k;i++)
    {
        a[m*n*i/gy(m,n)]=0;
    }
    for (i=k;i>=1;i--)
    if (a[i]==1) {leng=i; break;}
    for (i=1;i<=k;i++)
    if (a[i]==1)
    {
    printf("%d",i);
    if (i!=leng)
    putchar(' ');
    }
    return 0;
}
