#include<stdio.h>
main()
{
    int a,b,c,d,e,i,j;
    scanf("%d",&a);
    b=100-a;
    if (b<10)
    {
        if (b>=5)
    printf("$20 bills: 0\n$10 bills: 0\n $5 bills: 1\n $1 bills: %d",b-5);
         else printf("$20 bills: 0\n$10 bills: 0\n $5 bills: 0\n $1 bills: %d",b);
    return 0;
    }
    if (b>=10)
    if (b%10>=5)
    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: 1\n $1 bills: %d",b/20,(b-b/20*20)/10,b-b/10*10-5);
    else printf("$20 bills: %d\n$10 bills: %d\n $5 bills: 0\n $1 bills: %d",b/20,(b-b/20*20)/10,b-b/10*10);
    return 0;

}
