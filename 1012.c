#include<stdio.h>
int flower(int n)
{
    int ge,shi,bai;
    ge=n%10;
    shi=n/10%10;
    bai=n/100;
    if (ge*ge*ge+shi*shi*shi+bai*bai*bai==n)
    return 1;
    else return 0;

}
main()
{
    int a;
    scanf("%d",&a);
    if (flower(a)==1)
    printf("YES");
    else printf("NO");
}
