#include<stdio.h>
#include<string.h>
main()
{
unsigned long long k;
while(scanf("%llu",&k)>0)
{
    if (k!=1) printf("%llu471\n",k-1);
    else printf("471\n");

}
return 0;
}

